#include <iostream>
#include <vector>
#include <queue>

#define NONVISIT 0
#define VISIT 1
#define UNREACHABLE -1
#define WALL 0

int n, m; // size of map n * m
std::vector< std::vector<int> >	map; // info of map
std::queue< std::pair<int, int> > queue;
std::vector< std::vector<int> >	visit;

std::vector< std::vector<int> >	dist; // distance between target spot

int	mRow[4] = {-1, 0, 1, 0};
int	mCol[4] = {0, 1, 0, -1};

void	bfs(std::pair<int, int> curr)
{
	int nRow, nCol; // next location

	for (int i = 0; i < 4; i++)
	{
		nRow = curr.first + mRow[i];
		nCol = curr.second + mCol[i];

		// if possible to reachable
		if ((0 <= nRow && nRow < n) && (0 <= nCol && nCol < m)
			&& (visit[nRow][nCol] == NONVISIT))
		{
			// if not wall in location
			if (map[nRow][nCol] != 0)
			{
				dist[nRow][nCol] = dist[curr.first][curr.second] + 1;
				queue.push(std::make_pair(nRow, nCol));
			}
		}

	}
}

int main(void)
{
	std::pair<int, int>	target;

/* input data */
	std::cin >> n >> m;

	map.resize(n);
	for (int i = 0; i < n; i++)
	{
		map[i].resize(m);
		for (int j = 0; j < m; j++)
			std::cin >> map[i][j];
	}

/* init data */
	visit.resize(n);
	dist.resize(n);
	for (int i = 0; i < n; i++)
	{
		visit[i].resize(m);
		dist[i].resize(m);
		for (int j = 0; j < m; j++)
		{
			visit[i][j] = NONVISIT;

			// init target spot
			if (map[i][j] == 0)
				dist[i][j] = WALL;
			else if (map[i][j] == 1)
				dist[i][j] = UNREACHABLE;
			else if (map[i][j] == 2)
			{
				target.first = i;
				target.second = j;
			}
		}
	}
	dist[target.first][target.second] = 0;

/* do bfs */
	queue.push(target);
	while (!queue.empty())
	{
		target = queue.front();
		queue.pop();

		if (visit[target.first][target.second] == NONVISIT)
		{
			visit[target.first][target.second] = VISIT;
			bfs(target);
		}
	}

/* print result */
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cout << dist[i][j];
			if (j != m - 1)
				std::cout << " ";
		}
		std::cout << "\n";
	}

	return (0);
}
