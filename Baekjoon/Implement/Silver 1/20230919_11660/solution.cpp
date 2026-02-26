#include <iostream>
#include <vector>

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int	N, M;
	std::vector<std::vector<int> > graph;
	std::vector<int> array;
	int value;
	int	result;
	int	x1, y1, x2, y2;

	std::cin >> N >> M;
	for (int row = 0; row < N; row++)
	{
		array.clear();
		for (int col = 0; col < N; col++)
		{
			std::cin >> value;
			array.push_back(value);
			if (row == 0 && col != 0)
				array[col] = array[col - 1] + array[col];
			else if (row != 0)
			{
				if (col == 0)
					array[col] = graph[row - 1][col] + array[col];
				else
				{
					array[col] = array[col - 1] + array[col];
					array[col] = graph[row - 1][col] + array[col] - graph[row - 1][col - 1];
				}
			}
		}
		graph.push_back(array);
	}
	
	for (int times = 0; times < M; times++)
	{
		result = 0;
		std::cin >> x1 >> y1 >> x2 >> y2;

		if (x1 == 1 || x2 == 1)
		{
			if (y1 == 1)
				result = graph[x2 - 1][y2 - 1];
			else if (y2 == 1)
				result = graph[x2 - 1][y2 - 1];
			else
				result = graph[x2 - 1][y2 - 1] - graph[x2 - 1][y1 - 2];
		}
		else
		{
			if (y1 == 1)
				result = graph[x2 - 1][y2 - 1] - graph[x1 - 2][y2 - 1];
			else if (y2 == 1)
				result = graph[x2 - 1][y2 - 1] - graph[x1 - 2][y2 - 1];
			else
				result = graph[x2 - 1][y2 - 1] - graph[x2 - 1][y1 - 2] - graph[x1 - 2][y2 - 1] + graph[x1 - 2][y1 - 2];
		}

		std::cout << result << "\n";
	}

	return (0);
}

