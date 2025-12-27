#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define NONVISIT 0
#define VISITED 1

int N, M, V;
std::vector< std::vector<int> > edges;
std::vector<int> visit;
std::queue<int> queue;

/* dfs function */
void	dfs(int v)
{
	int edgeSize = edges[v].size();

// set visit and print
	visit[v] = VISITED;
	std::cout << v << " ";

// dfs again
	for (int i = 0; i < edgeSize; i++)
	{
		if (visit[edges[v][i]] == NONVISIT)
			dfs(edges[v][i]);
	}
}

void	bfs(int v)
{
	int edgeSize = edges[v].size();
	int	queueFront;

// set visit and print
	visit[v] = VISITED;
	std::cout << v << " ";

// push adjacent to queue
	for (int i = 0; i < edgeSize; i++)
	{
		queue.push(edges[v][i]);
	}

// bfs again
	for (int i = 0; i < queue.size(); i++)
	{
		queueFront = queue.front();
		queue.pop();

		if (visit[queueFront] == NONVISIT)
			bfs(queueFront);
	}
}

/* main function */
int main(void)
{
// set N, M, V
	std::cin >> N >> M >> V;

// set visit, edges size
	visit.reserve(N + 1);
	edges.reserve(N + 1);

// set visit, edges data
	for (int i = 1; i <= N; i++)
		visit[i] = NONVISIT;
	int s, e;
	for (int i = 1; i <= M; i++)
	{
		std::cin >> s >> e;
		edges[s].push_back(e);
		edges[e].push_back(s);
	}

// sort edges to ascendent
	for (int i = 1; i <= N; i++)	
		sort(edges[i].begin(), edges[i].end());

// dfs
	dfs(V);
	std::cout << "\n";

// reset visit 
	for (int i = 1; i <= N; i++)
		visit[i] = NONVISIT;

// bfs
	bfs(V);
	std::cout << "\n";

	return (0);
}
