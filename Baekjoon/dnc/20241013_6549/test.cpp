#include <iostream>

#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)
#define MAX3(a, b, c) (MAX(MAX(a, b), c))

int n;
int *hist;

long long centroid(long long s, long long e, long long m)
{
	int width, height;
	long long marea;

/* 초기값은 m만 고려*/
	width = 1;
	height = hist[m];
	marea = width * height;

/* two pointer */
	int lptr = m - 1;
	int rptr = m + 1;

	while (lptr > s || rptr < e)
	{
		/* rptr 이동, height 갱신*/
		if (lptr <= s || (rptr < e && hist[lptr] <= hist[rptr]))
		{
			height = MIN(hist[rptr], height);
			rptr++;
			if (lptr == s)
				width = rptr - lptr;
			else 
				width = rptr - lptr - 1;
		}
		/* lptr 이동 */
		else
		{
			height = MIN(hist[lptr], height);
			lptr--;
			width = rptr - lptr - 1;
		}

		/* width, height 갱신 */
		// width = rptr - lptr - 1;
		marea = MAX(marea, (long long)height * width);
		// std::cout << rptr << " | " << lptr << " | " << marea << "\n";
	}

	width = rptr - lptr + 1;
	height = MIN(hist[rptr], height);
	height = MIN(hist[lptr], height);
	marea = MAX(marea, (long long)height * width);
	// std::cout << rptr << " | " << lptr << " | " << marea << "\n";
	// std::cout << "------------------\n";

	return marea;
}

long long solve(int s, int e)
{
/* 1. degenerate case */
	if (s == e) /* historgram이 1개 */
		return  hist[s];
	else if (s + 1 == e) /* histogram이 2개 */
		return (long long)2 * MIN(hist[s], hist[e]);

/* 2. divide */
	int m = (s + e) / 2;
	long long larea = solve(s, m);
	long long rarea = solve(m, e);

/* 3. combine */
	long long marea = centroid(s, e, m);

	return MAX3(larea, rarea, marea);
}

int main()
{
	while (1)
	{
		std::cin >> n;
		if (n == 0)
			break ;

		hist = new int[n];
		for (int i = 0; i < n; i++)
			std::cin >> hist[i];
		
		std::cout << solve(0, n - 1) << "\n";

		delete[] hist;
	}

	return 0;
}