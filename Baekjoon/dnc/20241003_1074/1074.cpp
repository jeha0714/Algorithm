#include <iostream>
#include <vector>
#include <cmath>

void	dnc(int, int, int, int, int);

int nth = 0;

void	dnc(int N, int r, int c, int iRow, int iCol)
{
	// 1. degenerate case
	if (r == iRow && c == iCol)
		return ;

	// 2. divide
	if (r < iRow + pow(2, N - 1) && c < iCol + pow(2, N - 1))
		dnc (N - 1, r, c, iRow, iCol);
	else if (r < iRow + pow(2, N - 1))
	{
		nth += pow(2, N - 1) * pow(2, N - 1);
		dnc (N - 1, r, c, iRow, iCol + pow(2 , N - 1));
	}
	else if (c < iCol + pow(2, N - 1))
	{
		nth += pow(2, N - 1) * pow(2, N - 1) * 2;
		dnc (N - 1, r, c, iRow + pow(2, N - 1), iCol);
	}
	else
	{
		nth += pow(2, N - 1) * pow(2, N - 1) * 3;
		dnc (N - 1, r, c, iRow + pow(2, N - 1), iCol + pow(2 , N - 1));
	}
	
	// 3. combine
}

int main(void)
{
	int N, r, c;
	std::cin >> N >> r >> c;

	dnc(N, r, c, 0, 0);

	std::cout << nth << "\n";

	return (0);
}