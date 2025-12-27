#include <iostream>
#include <vector>
#include <algorithm>

#define YES 1
#define NO 0
#define W 1
#define B 0
#define NONVISIT -1

std::vector< std::vector<int> >	graph;
std::vector<int>	vColor;

int dfs(int v, int color)
{
	int nextColor;
	int vSize = graph[v].size();
	int	vAdjacent;

	vColor[v] = color;

	if (color == W)
		nextColor = B;
	else
		nextColor = W;

	for (int i = 0; i < vSize; i++)
	{
		vAdjacent = graph[v][i];
		if (vColor[vAdjacent] == NONVISIT)
		{
			if (dfs(vAdjacent, nextColor) == NO)
				return (NO);
		}
		else if (vColor[vAdjacent] == color)
			return (NO);

	}

	return (YES);	
}

int main(void)
{
	int K;
	int V, E;
	int u, v;

	std::cin >> K;
	while (K--)
	{
		std::cin >> V >> E;

		graph.reserve(V + 1);
		vColor.reserve(V + 1);
		for (int i = 0; i <= V; i++)
			vColor[i] = NONVISIT;

		for (int i = 0; i < E; i++)
		{
			std::cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		for (int i = 1; i <= V; i++)
			sort(graph[i].begin(), graph[i].end());

		for (int i = 1; i <= V; i++)
		{
			if (vColor[i] == NONVISIT)
			{
				if (dfs(i, W) == NO)
				{
					std::cout << "NO\n";
					break ;
				}
			}
			if (i == V)
			{
				std::cout << "YES\n";
			}
		}

		for (int i = 1; i <= V; i++)
			graph[i].clear();
		graph.clear();
		vColor.clear();
	}


	return (0);
}