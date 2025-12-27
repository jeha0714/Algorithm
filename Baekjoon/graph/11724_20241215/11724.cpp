#include <iostream>
#include <vector>

#define NONVISIT 0
#define VISIT 1

int N, M; // # of vertex and edge
std::vector< std::vector<int> >	graph; // info of edge
std::vector<int>				visit;
int numCC; // # of connected component

void	dfs(int u)
{
	int v; // num of adjacent vertex u

	// set visit
	visit[u] = VISIT;

	// dfs to u's adjacent vertex
	for (int i = 0; i < graph[u].size(); i++)
	{
		v = graph[u][i];
		if (visit[v] == NONVISIT)
			dfs(graph[u][i]);
	}
}

int main(void)
{
	int u, v;

/* input data */
	std::cin >> N >> M;

	graph.resize(N + 1);
	for (int i = 0; i < M; i++)
	{
		std::cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

/* init data */
	visit.resize(N + 1);
	for (int i = 1; i <= N; i++)
		visit[i] = NONVISIT;

	numCC = 0;

/* do dfs */
	for (int i = 1; i <= N; i++)
	{
		if (visit[i] == NONVISIT)
		{
			dfs(i);
			numCC++;
		}
	}

/* print result */
	std::cout << numCC << "\n";

	return (0);
}
