#include <iostream>
#include <vector>
#include <string>

#define NONVISIT 0
#define VISIT 1

int	N;
std::vector<std::string>		map;
std::vector< std::vector<int> >	visit;
int	general = 0, special = 0;

int	mx[4] = {0, 0, -1, 1};
int	my[4] = {-1, 1, 0, 0};

/* argument : current X, current Y, current Color */
void	dfs(int cX, int cY, int cColor)
{
	visit[cX][cY] = VISIT;

	for (int i = 0; i < 4; i++)
	{
		if (0 <= cX + mx[i] && cX + mx[i] < N && 0 <= cY + my[i] && cY + my[i] < N
			&& visit[cX + mx[i]][cY + my[i]] == NONVISIT
			&& map[cX + mx[i]][cY + my[i]] == cColor)
			dfs(cX + mx[i], cY + my[i], cColor);
	}
}

int main(void)
{
/* input data */
	std::cin >> N;

	map.resize(N);
	for (int i = 0; i < N; i++)
		std::cin >> map[i];

/* init */
	// init visit
	visit.resize(N);
	for (int i = 0; i < N; i++)
	{
		visit[i].resize(N);
		for (int j = 0; j < N; j++)
			visit[i][j] = NONVISIT;
	}

// dfs for general
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j] == NONVISIT)
			{
				general++;
				dfs(i, j, map[i][j]);
			}
		}
	}

// edit map for special
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 'G')
				map[i][j] = 'R';
		}
	}

// clear visit
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			visit[i][j] = NONVISIT;
	}

// dfs for special
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j] == NONVISIT)
			{
				special++;
				dfs(i, j, map[i][j]);
			}
		}
	}
/* print result */
	std::cout << general << " " << special << "\n";

}