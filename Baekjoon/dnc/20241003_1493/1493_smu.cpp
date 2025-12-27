#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 자료구조 */
int sol;
int n;
int A[20];
int B[20];

int min3(int a, int b, int c)
{
	if (a < b && a < c)
		return a;
	if (b < c)
		return b;
	return  c;
}

void solve(int length, int width, int height)
{
/* 1. degenerate case */
	if (length == 0 && width == 0 && height == 0)
		return ;

/* 2. divide */
	/* 1. length, width, height 중에서 최소값 */
	int mind = min3(length, width, height);

	/* 2. mind보다 작으면서 가장 큰 cube */
	int scube = -1;
	for (int i = n - 1; i >= 0; i--)
	{
		if (B[i] == 0)
			continue;
		if (A[i] > mind)
			continue;
		scube = i;
		break ;
	}

	if (scube < 0)
	{
		sol = -1;
		return ;
	}

	int cube = A[scube];
	sol++;
	B[scube]--;

	/* 3 분할 */
	solve(length - cube, width, height);
	solve(cube, width, height - cube);
	solve(cube, width - cube, cube);

/* 3. combine*/

}

int main(void)
{
	FILE* fp;
	fopen_s(&fp, "input.txt", "r+t");

	int tc;
	int length, width, height;
	int ans;
	int a, b;

	fscanf_s(fp, "%d", &tc);
	for (int i = 0; i < tc; i++)
	{
		/* input 처리 */
		fscanf_s(fp, "%d %d %d", &length, &width, &height);
		fscanf_s(fp, "%d", &n);

		for (int j = 0; j < n; j++)
		{
			fscanf_s(fp, "%d %d", &a, &b);
			A[j] = pow(2, a);
			B[j] = b;
		}
		fscanf_s(fp, "%d", &ans);

		/* solve */
		sol = 0;
		solve(length, width, height);
		printf("%d, %d\n", ans, sol);
	}


	fclose(fp);

	return (0);
}
