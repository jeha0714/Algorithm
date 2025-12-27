#include <iostream>
#include <vector>
#include <queue>
#include <string>

#define INFINITE 2147483647
#define NONVISIT 0
#define VISIT 1

int	N, M; // N = size of maze , M = # of key
std::vector< std::string >	map;
std::vector< std::pair<int, int> >	loc; // index 0 is Start, index 1 ~ M are key
std::vector< std::vector< std::vector<int> > >	minCost; // min cost to go each loc

std::queue< std::pair<int, int> >	bfsQueue; // bfs queue
std::vector< std::vector<int> >		bfsVisit;
int	mx[4] = {0, 0, -1, 1}; // up down left right for coordinate x
int	my[4] = {-1, 1, 0, 0}; // up down left right for coordinate y

// void	bfs(int iLoc, int iX, int iY, int currCost)
void	bfs(int iLoc, int x, int y)
{
	// set visit to VISIT
	bfsVisit[x][y] = VISIT;

	// sequence UP, DOWN, LEFT, RIGHT
	for (int i = 0; i < 4; i++)
	{
		if ((0 <= x + mx[i] && x + mx[i] < N) && (0 <= y + my[i] && y + my[i] < N)
			&& map[x + mx[i]][y + my[i]] != '1'
			&& bfsVisit[x + mx[i]][y + my[i]] != VISIT)
		{
			minCost[iLoc][x + mx[i]][y + my[i]] = minCost[iLoc][x][y] + 1;
			bfsQueue.push(std::make_pair(x + mx[i], y + my[i]));
		}
	}
}

struct Compare
{
	bool operator()(const std::pair<int, std::pair<int, int> > &a
					, const std::pair<int, std::pair<int, int> > &b)
	{
		return (a.first > b.first);
	}
};

long long	prim()
{
	long long			totalCost;
	std::vector<int> 	visit(M + 1, NONVISIT);
	std::priority_queue< std::pair<int, std::pair<int, int> > // (weight, (u, v))
						, std::vector< std::pair<int, std::pair<int, int> > > 
						, Compare>	pq; // weight ascending queue
	std::vector<int>	U; // check for while
	
// init
	totalCost = 0;
	U.reserve(M + 1);
	U.push_back(0);
	// push weight Start to nth Key
	for (int i = 1; i <= M; i++)
	{
		int vX = loc[i].first;
		int vY = loc[i].second;
		int	w = minCost[0][vX][vY];

		if (w != INFINITE)
			pq.push(std::make_pair(minCost[0][vX][vY], std::make_pair(0, i)));
	}

	// prim start
	while (!pq.empty() && U.size() < M + 1)
	{
		int w = pq.top().first;
		int u = pq.top().second.first;
		int v = pq.top().second.second;
		pq.pop();

		if (visit[v] == NONVISIT)
		{
			visit[v] = VISIT;
			totalCost += w;
			U.push_back(v);
			for (int i = 1; i <= M; i++)
			{
				if (i == v && visit[i] == VISIT)
					continue ;

				int vVX = loc[i].first;
				int vVY = loc[i].second;
				int	vW = minCost[v][vVX][vVY];
				if (vW != INFINITE)
					pq.push(std::make_pair(vW, std::make_pair(v, i)));
			}
		}
	}

	if (U.size() != M + 1)
		return (-1);
	else
		return (totalCost);
}

int main(void)
{
/* input data */
	std::cin >> N >> M;
	
	map.resize(N);
	for (int i = 0; i < N; i++)
	{
		std::cin >> map[i];
	}

/* set data */
	// 1. find Start & Key location
	loc.reserve(M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 'S')
				loc.push_back(std::make_pair(i, j));
			else if (map[i][j] == 'K')
				loc.push_back(std::make_pair(i, j));
		}
	}

	// 2. set weight of each key or start
		// init minCost
	minCost.resize(M + 1);
	for (int i = 0; i <= M; i++)
	{
		minCost[i].resize(N + 1);
		for (int j = 0; j < N; j++)
		{
			minCost[i][j].resize(N + 1);
			for (int k = 0; k < N; k++)
			{
				minCost[i][j][k] = INFINITE;
			}
		}
	}

	// 3. init bfsVisit
	bfsVisit.resize(N);
	for (int i = 0; i < N; i++)
		bfsVisit[i].resize(N);

	// do bfs
	for (int i = 0; i <= M; i++)
	{
		// clear visit
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				bfsVisit[i][j] = NONVISIT;

		// set current start or key location
		int	iX, iY;
		iX = loc[i].first;
		iY = loc[i].second;

		// cost is 0 where it exist
		minCost[i][iX][iY] = 0;

		// push i location
		bfsQueue.push(std::make_pair(iX, iY));

		// bfs start
		while(!bfsQueue.empty())
		{
			std::pair<int, int> v = bfsQueue.front();
			bfsQueue.pop();

			if (bfsVisit[v.first][v.second] == NONVISIT)
				bfs(i, v.first, v.second);
		}
	}

// prim algorithm
	std::cout << prim() << "\n";

	return (0);
}