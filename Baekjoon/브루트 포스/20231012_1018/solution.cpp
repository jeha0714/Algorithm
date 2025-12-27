#include <iostream>

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N, M;
	char **chess;
	int	result;
	int temp;

	/* Set initial input */
	std::cin >> N >> M;
	chess = new char*[N];
	for (int i = 0; i < N; i++)
		chess[i] = new char[M];
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < M; col++)
			std::cin >> chess[row][col];
	}

	/* Find result */
	result = 2147483647;

		// Cut 8 * 8
	for (int start_row = 0; start_row <= N - 8; start_row++)
	{
		for (int start_col = 0; start_col <= M - 8; start_col++)
		{
				// Start 'W'
			temp = 0;
			for (int row = start_row; row < start_row + 8; row++)
			{
				for (int col = start_col; col < start_col + 8; col++)
				{
					if (chess[row][col] == 'W' && ((row + col) % 2) == 1)
						temp++;
					else if (chess[row][col] == 'B' && ((row + col) % 2) == 0)
						temp++;
				}
			}
			if (temp < result)
				result = temp;

				// Start 'B'
			temp = 0;
			for (int row = start_row; row < start_row + 8; row++)
			{
				for (int col = start_col; col < start_col + 8; col++)
				{
					if (chess[row][col] == 'W' && ((row + col) % 2) == 0)
						temp++;
					else if (chess[row][col] == 'B' && ((row + col) % 2) == 1)
						temp++;
				}
			}
			if (temp < result)
				result = temp;
		}
	}

	/* Print result */
	std::cout << result << "\n";

	/* Free memory */
	for (int i = 0; i < N; i++)
		delete[] chess[i];
	delete[] chess;

	return (0);
}
