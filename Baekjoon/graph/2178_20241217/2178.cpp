#include <iostream>
#include <vector>
#include <string>

#define INFINITE 2147483647

int	N, M;
std::vector< std::string >		map;
std::vector< std::vector<int> >	visit;

// up down left right
int mr[4] = {-1, 1, 0 , 0};
int mc[4] = {0, 0, -1 , 1};

void	dfs(int currRow, int currCol)
{
	int nr, nc; // next row, column

	// dfs up, down, left, right
	for (int i = 0; i < 4; i++)
	{
		nr = currRow + mr[i];
		nc = currCol + mc[i];

		if ((0 <= nr && nr < N) && (0 <= nc && nc < M)
			&& (map[nr][nc] == '1') && (visit[nr][nc] > visit[currRow][currCol] + 1))
		{
			visit[nr][nc] = visit[currRow][currCol] + 1;
			dfs(nr, nc);
		}
	}
}

int main(void)
{
/* input data */
	std::cin >> N >> M;

	map.resize(N);
	for (int i = 0; i < N; i++)
		std::cin >> map[i];

/* init data */
	visit.resize(N);
	for (int i = 0; i < N; i++)
	{
		visit[i].resize(M);
		for (int j = 0; j < M; j++)
			visit[i][j] = INFINITE;
	}
	visit[0][0] = 1;

/* dfs */
	dfs(0, 0);

/* print result */
	std::cout << visit[N - 1][M -1] << "\n";

	return (0);
}
