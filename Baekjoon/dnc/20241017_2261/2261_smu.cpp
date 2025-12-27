#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define MIN(a, b) (a < b ? a : b)
#define MIN3(a, b, c) (MIN(MIN(a, b), c))
#define PAIRSIZE 10001

int n;
pair<int, int> p[PAIRSIZE];

int distance(int x1, int y1, int x2, int y2)
{
	return (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
}

int closest_pair_square(int s, int e, pair<int, int> *ps)
{
	int cdist = 2147483647;
	int dist;
	for (int i = s; i <= e; i++)
	{
		for (int j = s; j <= e; j++)
		{
			if (i == j)
				continue;

			dist = distance(ps[i].first, ps[i].second, ps[j].first, ps[j].second);
			if (dist < cdist)
				cdist = dist;
		}
	}
	return (cdist);
}

int centroid(int s, int e, int m, int delta)
{
	int nu = 0;
	pair<int, int> u[PAIRSIZE];
/* 1. (p[m].x - delta, p[m].x + delta)에 있는 점들 찾기 -> u*/
	for (int i = s; i <= e; i++)
	{
		if (p[m].first - delta < p[i].first && p[i].first < p[m].first + delta)
			u[nu++] = p[i];
	}

/* 2. ufmf y축의 내림차순으로 정렬 */
	sort(u, u + nu, [](const std::pair<int, int> &a, const std::pair<int, int> &b)
		{
			return a.second > b.second;
		}
	);

/* 3. u를 15개씩 쪼개서 최단 거리 쌍 구하기 */
	if (nu < 15)
		return (closest_pair_square(0, nu - 1, u));

	int dist;
	int mdist = closest_pair_square(0, 14, u);
	for (int i = 1; i <= nu - 15; i++)
	{
		dist = closest_pair_square(i, i + 14, u);
		if (dist < mdist)
			mdist = dist;
	}
	return (mdist);
}

int solve(int s, int e)
{
/* 1. degenerate case */
	if (s == e)
		return 0;
	else if (e == s + 1)
		return distance(p[s].first, p[s].second, p[e].first, p[e].second);

/* 2. divide */
	int m = (s + e) / 2;
	int ldist = solve(s, m);
	int rdist = solve(m, e);

/* 3. combine */
	int delta = MIN(ldist, rdist);
	int mdist = centroid(s, e, m, delta);

	return (MIN3(ldist, rdist, mdist));
}

int main(void)
{
	FILE *fp;
	fp = fopen("input.txt", "r");

	int tc;
	int x, y;
	int ans;
	fscanf(fp, "%d", &tc);
	for (int i = 0; i < tc; i++)
	{
		fscanf(fp, "%d", &n);
		for (int j = 0; j < n; j++)
		{
			fscanf(fp, "%d %d", &x, &y);
			p[j] = make_pair(x, y);
		}
		sort(p, p + n);

		ans = closest_pair_square(0, n - 1, p);
		printf("%d --> ", ans);
		printf("%d", solve(0, n - 1));
		printf("\n");
	}

	fclose(fp);
	return (0);
}