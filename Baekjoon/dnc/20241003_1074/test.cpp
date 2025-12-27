#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

/* 자료구조 */

int solve(int n, int x, int y)
{
/* 1. degenerate case */
	if (n == 1)
	{
		if (x == 0 && y == 0)
			return (0);
		else if (x == 0 && y == 1)
			return (1);
		else if (x == 1 && y == 0)
			return (2);
		else if (x == 1 && y == 1)
			return (3);

		return (-1);
	}

/* 2. divide */
	int half = pow(2, n - 1);
	int nx, ny;
	int cnt;
	int offset;

	if (x < half) // U
	{
		if (y < half) // L
		{
			nx = x;
			ny = y;
			offset = 0;
		}
		else // R
		{
			nx = x;
			ny = y - half;
			offset = half * half;
		}
	}
	else // D
	{
		if (y < half) // L
		{
			nx = x - half;
			ny = y;
			offset = half * half * 2;
		}
		else // R
		{
			nx = x - half;
			ny = y - half;
			offset = half * half * 3;
		}
	}

	cnt = solve(n - 1, nx, ny);

/* 3. combine --> None */
	return (cnt + offset);

}

int main(void)
{
	int N, r, c;
	std::cin >> N >> r >> c;

	std::cout << solve(N, r, c) << "\n";

	return (0);
}
