#include <iostream>

int *hist;
int n;

long long centroid(int s, int e , int m)
{
	int height = hist[m];
	int	width = 1;
	long long marea = hist[m];
	int lptr = m - 1;
	int	rptr = m + 1;

	while (lptr > s || rptr < e)
	{
		if (lptr <= s || (rptr < e && hist[lptr] <= hist[rptr]))
		{
			height = std::min(hist[rptr], height);
			rptr++;
		}
		else
		{
			height = std::min(hist[lptr], height);
			lptr--;
		}

		width = rptr - lptr - 1;
		marea = std::max(marea, (long long)width * height);
	}

	return (marea);
}

long long max3(long long a, long long b, long long c)
{
	if (a > b && a > c)
		return (a);
	else if (b > c)
		return (b);
	else
		return (c);
}

long long dnc(int s, int e)
{
	int m;
	long long larea, rarea, marea;
/* degenerate case */
	if (s == e)
		return ((long long)hist[s]);
	else if (s + 1 == e)
		return ((long long)std::min(hist[s], hist[e]) * 2);

/* divide */
	m = (s + e) / 2;
	larea = dnc(s, m);
	rarea = dnc(m, e);

/* combine */
	marea = centroid(s, e, m);

	return (max3(larea, rarea, marea));
}

int main(void)
{
	long long result;

	while (1)
	{
		std::cin >> n;
		if (n == 0)
			break ;

		hist = new int[n];
		for (int i = 0; i < n; i++)
			std::cin >> hist[i];
		
		result = dnc(0, n - 1);
		std::cout << result << "\n";

		delete[] hist;
	}

	return (0);
}