#include <iostream>
#include <vector>
#include <queue>

#define NONVISIT 0
#define VISIT 1
#define INFINITE 2147483647

int V, E; // # of vertex and edge
int K; // # of start vertext

std::vector<std::vector<std::pair<int, int> > >	graph;
std::vector<int>	visit;
std::vector<int>	dist;

void	dijkstra(int start)
{
	std::priority_queue<std::pair<int, int> >	pq;
	int u, v, w;

	// init visit
	visit.resize(V + 1);
	for (int i = 0; i <= V; i++)
		visit[i] = NONVISIT;
	
	// init dist
	dist.resize(V + 1);
	for (int i = 0; i <= V; i++)
		dist[i] = INFINITE;
	dist[start] = 0;
	
	// push pq to vertex
	for (int i = 1; i <= V; i++)
		pq.push(std::make_pair(-1 * dist[i], i));

	// do bfs
	while (!pq.empty())
	{
		// pq pop
		u = pq.top().second;
		pq.pop();

		// continue if alr visit
		if (visit[u] == VISIT)
			continue;
		
		visit[u] = VISIT;

		for (int i = 0; i < graph[u].size(); i++)
		{
			v = graph[u][i].first;
			w = graph[u][i].second;
			if (dist[u] != INFINITE && dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				pq.push(std::make_pair(-1 * dist[v], v));
			}
		}
	}
}

int main(void)
{
	int u, v, w;

/* input data */
	std::cin >> V >> E;
	std::cin >> K;

	graph.resize(V + 1);
	for (int i = 0; i < E; i++)
	{
		std::cin >> u >> v >> w;
		graph[u].push_back(std::make_pair(v, w));
	}

	dijkstra(K);

/* print result */
	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == INFINITE)
			std::cout << "INF\n";
		else
			std::cout << dist[i] << "\n";
	}

	return (0);
}