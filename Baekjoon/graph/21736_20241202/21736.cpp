#include <iostream>
#include <vector>
#include <string>
#include <queue>

#define NONVISIT 0
#define VISIT 1

int N, M; // size of map
std::vector<std::string>				map;
std::vector< std::vector<int> >			visit;
int	nPeople; // # of meet human

/* bfs */
std::queue< std::pair<int, int> >	q; // bfs queue
int mx[4] = {-1, 0, 1, 0};
int my[4] = {0, 1, 0, -1};

void	bfs(int x, int y)
{
	int nX, nY;

	visit[x][y] = VISIT;
	if (map[x][y] == 'P')
		nPeople++;

	for (int i = 0; i < 4; i++)
	{
		nX = mx[i] + x;
		nY = my[i] + y; 
		if (0 <= nX && nX < N && 0 <= nY && nY < M
			&& map[nX][nY] != 'X')
			q.push(std::make_pair(nX, nY));
	}
}

int main(void)
{
	int x, y;

/* input data */
	std::cin >> N >> M;

	map.resize(N);
	for (int i = 0; i < N; i++)
	{
		map[i].reserve(M);
		std::cin >> map[i];
	}

	nPeople = 0;

/* init vistt */
	visit.resize(N);
	for (int i = 0; i < N; i++)
	{
		visit[i].resize(M);
		for (int j = 0; j < M; j++)
			visit[i][j] = NONVISIT;
	}

/* find I */
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 'I')
			{
				x = i;
				y = j;
				break ;
			}
		}
	}

/* do bfs */
	q.push(std::make_pair(x, y));
	while(!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		if (visit[x][y] != VISIT)
			bfs(x, y);
	}

/* print result */
	if (nPeople == 0)
		std::cout << "TT\n";
	else
		std::cout << nPeople << "\n";

	return (0);
}