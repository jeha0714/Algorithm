#include <iostream>
#include <vector>

int virus = 0;

void	bfs(int vertex, std::vector< std::vector <int> > &edges, std::vector<int> &visit)
{
	visit[vertex] = 1;
	virus++;

	for (int i = 0; i < edges[vertex].size(); i++)
	{
		if (visit[edges[vertex][i]] == 0)
		{
			bfs(edges[vertex][i], edges, visit);
		}
	}
}

int main(void)
{
	int V, E;
	std::cin >> V >> E;

	std::vector< std::vector <int> >edges(V + 1);
	std::vector<int> visit(V + 1, 0);

	int s, e;
	for (int i = 0; i < E; i++)
	{
		std::cin >> s >> e;
		edges[s].push_back(e);
		edges[e].push_back(s);
	}

	bfs(1, edges, visit);

	std::cout << virus - 1 << "\n";

	return (0);
}
