#include <iostream>
#include <vector>
#include <unistd.h>

void	dnc(int , std::vector< std::vector<int> > &, int , int);
bool	isAllSame(int , std::vector< std::vector<int> > &, int, int);

int minus = 0, zero = 0, plus = 0;

void	dnc(int N, std::vector< std::vector<int> > &arr, int iRow, int iCol)
{
	// 1. degenerate case
	if (N == 1 || isAllSame(N, arr, iRow, iCol))
	{
		if (arr[iRow][iCol] == -1)
			++minus;
		else if (arr[iRow][iCol] == 0)
			++zero;
		else
			++plus;
		return ;
	}
	
	// 2. devide
	dnc(N / 3, arr, iRow, iCol);
	dnc(N / 3, arr, iRow, iCol + N / 3);
	dnc(N / 3, arr, iRow, iCol + N / 3 * 2);

	dnc(N / 3, arr, iRow + N / 3, iCol);
	dnc(N / 3, arr, iRow + N / 3, iCol + N / 3);
	dnc(N / 3, arr, iRow + N / 3, iCol + N / 3 * 2);

	dnc(N / 3, arr, iRow + N / 3 * 2, iCol);
	dnc(N / 3, arr, iRow + N / 3 * 2, iCol + N / 3);
	dnc(N / 3, arr, iRow + N / 3 * 2, iCol + N / 3 * 2);

	// 3. combine
}

bool	isAllSame(int N, std::vector< std::vector<int> > &arr, int iRow, int iCol)
{
	int	num = arr[iRow][iCol];
	int	eRow = iRow + N;
	int	eCol = iCol + N;

	for (int i = iRow; i < eRow ; i++)
	{
		for (int j = iCol; j < eCol; j++)
		{
			if (arr[i][j] != num)
				return (false);
		}
	}
	return (true);
}

int main(void)
{
	int N;
	std::cin >> N;

	std::vector< std::vector<int> > arr(N);
	int temp;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> temp;
			arr[i].push_back(temp);
		}
	}

	dnc(N, arr, 0, 0);

	std::cout << minus << "\n";
	std::cout << zero << "\n";
	std::cout << plus << "\n";

	return (0);
}