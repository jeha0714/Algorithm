#include <iostream>
#include <vector>

#define NONVISIT 0
#define VISIT 1

int N;
std::vector< std::vector<int> >	matrix;
std::vector<int>				visit;

void	dfs(int u)
{
	for (int v = 0; v < N; v++)
	{
		if (matrix[u][v] == 1 && visit[v] == NONVISIT)
		{
			visit[v] = VISIT;
			dfs(v);
		}
	}
}

int main(void)
{
/* input data */
	std::cin >> N;

	matrix.resize(N);
	for (int i = 0; i < N; i++)
	{
		matrix[i].resize(N);
		for (int j = 0; j < N; j++)
			std::cin >> matrix[i][j];
	}

/* init visit */
	visit.resize(N);

/* dfs */
	// start 0th vertex
	for (int u = 0; u < N; u++)
	{
		// set visit
		for (int i = 0; i < N; i++)
			visit[i] = NONVISIT;

		// do dfs
		dfs(u);

		// set matrix that refer to visit
		for (int i = 0; i < N; i++)
		{
			if (visit[i] == VISIT)
				matrix[u][i] = 1;
		}
	}

/* print result */
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			std::cout << matrix[i][j] << " ";
		std::cout << "\n";
	}

	return (0);
}
