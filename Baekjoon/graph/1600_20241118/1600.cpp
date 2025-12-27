#include <iostream>
#include <vector>
#include <queue>

#define HURDLE 1 
#define NONVISIT 0
#define VISIT 1

int	K, W, H;
std::vector< std::vector< std::vector<int> > >		visit;
std::queue< std::pair< std::pair<int, int>, int > >	queue;
std::vector< std::vector<int> >						map;
int	mx[4] = {1, 0 , -1, 0};
int	my[4] = {0, 1 , 0, -1};
int	hx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int	hy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void	bfs(int x, int y, int k)
{
	int	nX, nY, nK; // n means next

	// move like monkey
		// right, left, down, up
	for (int i = 0; i < 4; i++)
	{
		nX = x + mx[i];
		nY = y + my[i];
		nK = k;
		if ((0 <= nX && nX < H) && (0 <= nY && nY < W)
			&& map[nX][nY] != HURDLE)
		{
			if (visit[nX][nY][nK] == 0)
			{
				visit[nX][nY][nK] = visit[x][y][k] + 1;
				queue.push(std::make_pair(std::make_pair(nX, nY), nK));
			}
			else if (visit[x][y][k] + 1 < visit[nX][nY][nK])
			{
				visit[nX][nY][nK] = visit[x][y][k] + 1;
				queue.push(std::make_pair(std::make_pair(nX, nY), nK));
			}
		}
	}

	// move like horse
		// Can't jump like horse more
	if (k == K)
		return ;
		// sequence 4, 5, 7, 8, 10, 11, 1, 2 clock direction
	for (int i = 0; i < 8; i++)
	{
		nX = x + hx[i];
		nY = y + hy[i];
		nK = k + 1;
		if ((0 <= nX && nX < H) && (0 <= nY && nY < W)
			&& map[nX][nY] != HURDLE)
		{
			if (visit[nX][nY][nK] == 0)
			{
				visit[nX][nY][nK] = visit[x][y][k] + 1;
				queue.push(std::make_pair(std::make_pair(nX, nY), nK));
			}
			else if (visit[x][y][k] + 1 < visit[nX][nY][nK])
			{
				visit[nX][nY][nK] = visit[x][y][k] + 1;
				queue.push(std::make_pair(std::make_pair(nX, nY), nK));
			}
		}
	}

}

int main(void)
{
	int	tmp;
	int	x, y, k;
	int	nMov = 0;

	// input data
	std::cin >> K >> W >> H;

	// init map
	map.reserve(H);
	for (int i = 0; i < H; i++)
	{
		map[i].reserve(W);
		for (int j = 0; j < W; j++)
		{
			std::cin >> tmp;
			map[i].push_back(tmp);
		}
	}

	// init visit
	visit.reserve(H);
	for (int i = 0; i < H; i++)
	{
		visit[i].reserve(W);
		for (int j = 0; j < W; j++)
		{
			visit[i][j].reserve(K);
			for (int r = 0; r <= K; r++)
				visit[i][j].push_back(0);
		}
	}

	// bfs start
	std::pair< std::pair<int, int>, int > dist;
	queue.push(std::make_pair(std::make_pair(0, 0), 0));

	while (!queue.empty())
	{
		dist = queue.front();
		x = dist.first.first;
		y = dist.first.second;
		k = dist.second;
		queue.pop();

		bfs(x, y, k);
	}
	
	// find min result
	nMov = visit[H - 1][W - 1][0];
	for (int i = 1; i <= K; i++)
	{
		if (visit[H - 1][W - 1][i] == 0)
			continue ;

		if (nMov == 0)
			nMov = visit[H - 1][W - 1][i];
		else if (nMov > visit[H - 1][W - 1][i])
			nMov = visit[H - 1][W - 1][i];
	}

	// print result
		// if map 1 * 1 dont need mov
	if (W == 1 && H == 1)
		std::cout << "0\n";
		// if cant visit to arrival
	else if (nMov == 0)
		std::cout << "-1\n";
	else
		std::cout << nMov << "\n";

	return (0);
}
