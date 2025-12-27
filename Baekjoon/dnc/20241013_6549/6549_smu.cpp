#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)
#define MAX3(a, b, c) (MAX(MAX(a, b), c))

int n;
int *hist;

int centroid(int s, int e, int m)
{
	int width, height, marea;

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
		}
		/* lptr 이동 */
		else
		{
			height = MIN(hist[lptr], height);
			lptr--;
		}

		/* width, height 갱신 */
		width = rptr - lptr - 1;
		marea = MAX(marea, height * width);
	}

	return marea;
}

int solve(int s, int e)
{
/* 1. degenerate case */
	if (s == e) /* historgram이 1개 */
		return  hist[s];
	else if (s + 1 == e) /* histogram이 2개 */
		return 2 * MIN(hist[s], hist[e]);

/* 2. divide */
	int m = (s + e) / 2;
	int larea = solve(s, m);
	int rarea = solve(m, e);

/* 3. combine */
	int marea = centroid(s, e, m);

	return MAX3(larea, rarea, marea);
}

int main()
{
	FILE* fp;
	fp = fopen("input.txt", "r+t");

	int tc;
	fscanf(fp, "%d", &tc);
	for (int i = 0; i < tc; i++)
	{
		fscanf(fp, "%d", &n);

		hist = (int *)calloc(n, sizeof(int));
		for (int j = 0; j < n; j++)
			fscanf(fp, "%d", &hist[j]);

		printf("%d\n", solve(0, n - 1));		
	}




	return 0;
}