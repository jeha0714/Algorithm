#include <stdio.h>
#include <stdlib.h>
#include <iostream>

/* 자료구조 */
int n;
int** arr;
int cnt[3];

int is_same(int xs, int xe, int ys, int ye)
{
	int flag = arr[xs][ys];

	for (int i = xs; i <= xe; i++)
	{
		for (int j = ys; j <= ye; j++)
			if (arr[i][j] != flag)
				return (0); /* not same */
	}

	return (1); /* same */
}

void solve(int xs, int xe, int ys, int ye)
{
/* 1. degenerate case */
	/* first case --> n == 1 */
	if (xs == xe && ys == ye)
	{
		if (arr[xs][ys] == -1)
			cnt[0]++;
		if (arr[xs][ys] == 0)
			cnt[1]++;
		if (arr[xs][ys] == 1)
			cnt[2]++;

		return ;
	}

	/* second case --> all same cells */
	if (is_same(xs, xe, ys, ye))
	{
		if (arr[xs][ys] == -1)
			cnt[0]++;
		if (arr[xs][ys] == 0)
			cnt[1]++;
		if (arr[xs][ys] == 1)
			cnt[2]++;

		return ;
	}

/* 2. divide */
	int xm1 = (2 * xs + xe) / 3;
	int xm2 = (xs + 2 * xe) / 3;
	int ym1 = (2 * ys + ye) / 3;
	int ym2 = (ys + 2 * ye) / 3;

	solve(xs, xm1, ys, ym1);
	solve(xm1 + 1, xm2, ys, ym1);
	solve(xm2 + 1, xe, ys, ym1);

	solve(xs, xm1, ym1 + 1, ym2);
	solve(xm1 + 1, xm2, ym1 + 1, ym2);
	solve(xm2 + 1, xe, ym1 + 1, ym2);

	solve(xs, xm1, ym2 + 1, ye);
	solve(xm1 + 1, xm2, ym2 + 1, ye);
	solve(xm2 + 1, xe, ym2 + 1, ye);

/* 3. combine --> None */

}

int main(void)
{
	/* input 처리 */
	int n;
	std::cin >> n;

	arr = (int **)calloc(n, sizeof(int*));
	for (int j = 0; j < n; j++)
		arr[j] = (int*)calloc(n, sizeof(int));
	
	int temp;
	for (int j = 0; j < n; j++)
	{	
		for (int k = 0; k < n; k++)
		{
			std::cin >> temp;
			arr[j][k] = temp;
		}
	}

	/* solve */
	cnt[0] = cnt[1] = cnt[2] = 0;
	solve(0, n - 1, 0, n - 1);

	std::cout << cnt[0] << "\n";
	std::cout << cnt[1] << "\n";
	std::cout << cnt[2] << "\n";

	return (0);
}
