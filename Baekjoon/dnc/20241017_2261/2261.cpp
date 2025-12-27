#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define MIN2(x, y) (x < y ? x : y)
#define MIN3(x, y, z) (MIN2(MIN2(x, y), z)) 

int n;
std::vector< std::pair<int, int> >p;

int	cal(std::pair<int, int> p1, std::pair<int, int> p2)
{
	int xx = (p1.first - p2.first) * (p1.first - p2.first);
	int yy = (p1.second - p2.second) * (p1.second - p2.second);

	return (xx + yy);
}

int br(int s, int e, std::vector<std::pair<int, int> > &u)
{
	int dist;
	int minDist = cal(p[s], p[e]);

	for (int i = s; i < e; i++)
	{
		for (int j = i + 1; j <= e; j++)
		{
			dist = cal(u[i], u[j]);
			if (minDist > dist)
				minDist = dist;
		}
	}


	return (minDist);
}

bool cmpSecondDown(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
	return (a.second > b.second);
}

bool cmpFirstUp(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
	return (a.first < b.first);
}

int	centroid(int s, int e, int m, int delta)
{
	std::vector<std::pair<int, int > > u;

/* 1. s ~ e 사이의 점들 중 p[m].x - delta, p[m].x + delta에 속하는 점들을 찾기 */
	for (int i = s; i <= e; i++)
	{
		if (p[m].first - delta <= p[i].first 
			&& p[i].first <= p[m].first + delta)
		{
			u.push_back(std::pair<int, int>(p[i].first, p[i].second));
		}
	}

/* 2. u를 y의 내림차순으로 정렬 */
	std::sort(u.begin(), u.end(), cmpSecondDown);

/* 3. u를 위에서부터 15개씩 묶어서 최단 거리를 구하고, 이 중에서 최단 거리를 리턴 */
	if (u.size() < 15)
		return (br(0, u.size() - 1, u));
	else
	{
		int minDist = br(0, 14, u);
		int dist;
		int usize = u.size();

		for (int i = 1; i <= usize - 15; i++)
		{
			dist = br(i, i + 14, u);
			if (dist < minDist)
				minDist = dist;
		}

		return (minDist);
	}
}

int	dnc(int s, int e)
{
/* degenerate case */
	if (s == e)
		return (0);
	else if (e - s == 1)
		return (cal(p[s], p[e]));

/* divide */
	int m = (s + e) / 2;
	int lside = dnc(s, m);
	int rside = dnc(m, e);

/* combine */
	int delta = MIN2(lside, rside);
	int mside = centroid(s, e, m, delta);

	return MIN3(lside, mside, rside);
}

int main(void)
{
	FILE *fp;
	fp = fopen("/Users/pjeha/Downloads/4.in.txt", "r");
	int x, y;
	int result;

	// std::cin >> n;
	fscanf(fp, "%d", &n);
	p.reserve(n);
	for (int i = 0; i < n; i++)
	{
		// std::cin >> x >> y;
		fscanf(fp, "%d %d", &x, &y);
		p[i].first = x;
		p[i].second = y;
	}

	std::sort(p.begin(), p.begin() + n, cmpFirstUp);

	result = dnc(0, n - 1);
	std::cout << result << "\n";
	
	return (0);
}
