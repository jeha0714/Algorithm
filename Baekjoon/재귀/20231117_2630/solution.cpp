#include <iostream>

using namespace std;

int white = 0, blue = 0;

/* Find num of color-paper */
void	find_num_color(int size, int **paper, int start_row, int start_col)
{
	int	temp;

	if (size == 1)
	{
		if (paper[start_row][start_col] == 0)
			white++;
		else
			blue++;
	}
	else
	{
		temp = paper[start_row][start_col];
		for (int row = start_row; row < start_row + size; row++)
		{
			for (int col = start_col; col < start_col + size; col++)
			{
				if (temp != paper[row][col])
				{
					find_num_color(size / 2, paper, start_row, start_col);
					find_num_color(size / 2, paper, start_row + size / 2, start_col);
					find_num_color(size / 2, paper, start_row, start_col + size / 2);
					find_num_color(size / 2, paper, start_row + size / 2, start_col + size / 2);
					return ;
				}
			}
		}
		if (temp == 0)
			white++;
		else
			blue++;
	}
}

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int	N;
	int	**color_paper;

	/* Set initial input */
	cin >> N;
	color_paper = new int *[N];
	for (int row = 0; row < N; row++)
	{
		color_paper[row] = new int[N];
		for (int col = 0; col < N; col++)
			cin >> color_paper[row][col];
	}

	/* Recursive find */
	find_num_color(N, color_paper, 0, 0);

	/* Print result */
	cout << white << "\n" << blue << "\n";

	/* Free memory */
	for (int row = 0; row < N; row++)
		delete [] color_paper[row];
	delete [] color_paper;

	return (0);
}
