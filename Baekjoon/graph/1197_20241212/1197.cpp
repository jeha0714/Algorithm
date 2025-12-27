#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V, E;

vector< pair< int, pair<int, int> > >	edges;
vector< pair< int, pair<int, int> > >	mcst;

class UnionFind 
{
private:
	vector<int>	root;
	vector<int>	rank;

public:
	UnionFind(int v)
	{
		root.resize(v + 1);
		rank.resize(v + 1);

		for (int i = 1; i <= v; i++)
		{
			root[i] = i;
			rank[i] = 0;
		}
	}

	~UnionFind()
	{

	}

	int find(int v)
	{
		if (root[v] != v)
			root[v] = find(root[v]);
		return (root[v]);
	}

	void uunion(int x, int y)
	{
		int	rootX = find(x);
		int rootY = find(y);

		if (rank[rootX] < rank[rootY])
		{
			root[rootX] = rootY;
		}
		else if (rank[rootX] > rank[rootY])
		{
			root[rootY] = rootX;
		}
		else
		{
			root[rootY] = rootX;
			rank[rootX] += 1;
		}
	}
};

void	kruskal()
{
	priority_queue< pair<int, pair<int, int> >,
					vector< pair<int, pair<int, int> > >,
					greater< pair<int, pair<int, int> > > > pq;
	UnionFind	uf(V);
	int u, v, w;
	
	// push data into pq
	for (int i = 0; i < E; i++)
		pq.push(make_pair(edges[i].first, make_pair(edges[i].second.first, edges[i].second.second)));

	while (!pq.empty() && mcst.size() < V - 1)
	{
		u = pq.top().second.first;
		v = pq.top().second.second;
		w = pq.top().first;
		pq.pop();

		// check cycle
			// diffrent root node
		if (uf.find(u) != uf.find(v))
		{
			uf.uunion(u, v);
			mcst.push_back(make_pair(w, make_pair(u, v)));
		}
		else // same root node
			continue;
	}
	
	if (mcst.size() < V - 1)
	{
		std::cout << "Non exit mcst!\n";
		exit(0);
	}
	
}

int main(void)
{
	int a, b, c;
	long long cost = 0;

/* input data */
	std::cin >> V >> E;

	for (int i = 0; i < E; i++)
	{
		std::cin >> a >> b >> c;
		edges.push_back(make_pair(c, make_pair(a, b)));
	}

/* kruskal algorithm */
	kruskal();

/* print rsesult */
	for (int i = 0; i < mcst.size(); i++)
		cost += mcst[i].first;
	
	std::cout << cost << "\n";

	return (0);
}