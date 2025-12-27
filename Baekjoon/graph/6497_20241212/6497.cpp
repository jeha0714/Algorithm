#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define NONVISIT 0
#define VISIT 1

int m, n;

vector< vector< pair<int, int> > >	graph;
vector< pair<int, pair<int, int> > >	mcst;
vector<int>	vvisit;

void	prim(int s)
{
	int u, v, w;
	priority_queue< pair<int, pair<int, int> >,
					vector< pair<int, pair<int, int> > >,
					greater< pair<int, pair<int, int> > > >	pq;

	// init visit
	vvisit.resize(m);
	for (int i = 0; i < m; i++)
		vvisit[i] = NONVISIT;
	vvisit[s] = VISIT;
	
	// init pq
	for (int i = 0; i < graph[s].size(); i++)
		pq.push(make_pair(graph[s][i].second, make_pair(s, graph[s][i].first)));
	
	while (mcst.size() < m - 1)
	{
		if (pq.empty())
			break ;
		
		u = pq.top().second.first;
		v = pq.top().second.second;
		w = pq.top().first;
		pq.pop();

		if (vvisit[u] == NONVISIT || vvisit[v] == VISIT)
			continue ;
		
		// set visit for delete dest to v in pq
		vvisit[v] = 1;

		// add mcst
		mcst.push_back(make_pair(w, make_pair(u, v)));

		// add path with source v in pq
		for (int i = 0; i < graph[v].size(); i++)
			pq.push(make_pair(graph[v][i].second, make_pair(v, graph[v][i].first)));

	}

	if (mcst.size() < m - 1)
	{
		std::cout << "no mcst !\n";
		exit(0);
	}
}

int main(void)
{
	int x, y, z;
	long long	maxCost;
	long long	cost;

	while (1)
	{
	/* input data */
		std::cin >> m >> n;

		// break
		if (m == 0 && n == 0)
			break ;

		maxCost = 0;
		graph.resize(m);
		for (int i = 0; i < n; i++)
		{
			std::cin >> x >> y >> z;
			graph[x].push_back(make_pair(y, z));
			graph[y].push_back(make_pair(x, z));
			maxCost += z;
		}

	/* prim algorithm */
		prim(1);

	/* print result */
		cost = 0;
		for (int i = 0; i < mcst.size(); i++)
			cost += mcst[i].first;
		
		std::cout << maxCost - cost << "\n";

	/* clear data */
		for (int i = 0; i < m; i++)
			graph[i].clear();
		graph.clear();
		mcst.clear();
		vvisit.clear();
	}

	return (0);
}