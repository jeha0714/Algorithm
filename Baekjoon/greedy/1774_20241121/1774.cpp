#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

#define NONVISIT 0
#define VISIT 1

int	N, M; // # of space ship and path
std::vector< std::pair<long long, long long> >	loc; // store space ship location
std::vector< std::vector<int> >		path; // already exist path

class UnionFind
{
private:
	std::vector<int> 					visit;

/* dfs function that will set who is root */	
	void	dfs(int curr, int root)
	{
		visit[curr] = VISIT;
		whoRoot[curr] = root;

		for (size_t i = 0; i < path[curr].size(); i++)
		{
			if (visit[path[curr][i]] != VISIT)
				dfs(path[curr][i], root);
		}
	}

public:
	std::vector<int>	whoRoot;
	std::vector<int>	rank;

/* constructor */
	UnionFind()
	{
		whoRoot.reserve(N + 1);
		rank.reserve(N + 1);
		for (int i = 1; i <= N; i++)
		{
			whoRoot[i] = i;
			rank[i] = 0;
		}

		// path를 기반으로 dfs돌면서 root 재설정
		visit.reserve(N + 1);
		for (int i = 1; i <= N; i++)
			visit[i] = NONVISIT;
		for (int i = 1; i <= N; i++)
		{
			if (visit[i] != VISIT)
				dfs(i, i);
		}
	}

/* find function that inform root node */
	int	find(int x)
	{
		if (whoRoot[x] != x)
			whoRoot[x] = find(whoRoot[x]);
		return (whoRoot[x]);
	}

/* unite function that union two seperate tree */
	void	unite(int x, int y)
	{
		int	rootX = find(x);
		int	rootY = find(y);

		if (rank[rootX] < rank[rootY])
		{
			whoRoot[rootX] = rootY;
		}
		else if (rank[rootX] > rank[rootY])
		{
			whoRoot[rootY] = rootX;
		}
		else
		{
			whoRoot[rootY] = rootX;
			rank[rootX]++;
		}
	}
};

/* compare function in priority queue */
struct Compare
{
	bool	operator()(const std::pair< double, std::pair<int, int> > &a
						, const std::pair< double, std::pair<int, int> > &b)
	{
		return (a.first > b.first);
	}
};

double	kruskal()
{
	double	minCost = 0.0;
	std::priority_queue< std::pair< double, std::pair<int, int> >
						, std::vector< std::pair< double, std::pair<int, int> > >
						, Compare> pq;
	UnionFind	uf;
	std::pair<double, std::pair<int, int> >	popInfo;

/* init pq */
	// push all of path between vertex
	for (int i = 1; i <= N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			double dist = std::sqrt(std::pow((loc[i].first - loc[j].first), 2) + std::pow((loc[i].second - loc[j].second), 2));
			pq.push(std::make_pair(dist, std::make_pair(i, j)));
		}
	}

	while (!pq.empty())
	{
		popInfo = pq.top();
		pq.pop();

		// union if diff root node between two vertex
		if (uf.find(popInfo.second.first) != uf.find(popInfo.second.second))
		{
			minCost += popInfo.first;
			uf.unite(popInfo.second.first, popInfo.second.second);
		}
	}

	return (minCost);
}

int main(void)
{
	int	x, y;
	int	ship1, ship2;

/* input & init data */
	std::cin >> N >> M;

	// init location
	loc.reserve(N + 1);
	for (int i = 1; i <= N; i++)
	{
		std::cin >> x >> y;
		loc[i] = std::make_pair(x, y);
	}

	// init	path
	path.reserve(N + 1);
	for (int i = 0; i < M; i++)
	{
		std::cin >> ship1 >> ship2;
		path[ship1].push_back(ship2);
		path[ship2].push_back(ship1);
	}

/* convert print option */
	// forces floating-point numbers
	std::cout << std::fixed;
	// sets the precision
	std::cout.precision(2);

/* print result */
	std::cout << kruskal() << "\n";

	return (0);
}