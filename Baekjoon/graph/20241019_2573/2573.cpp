#include <iostream>
#include <vector>
#include <unistd.h>

#define NONVISIT 0
#define VISIT 1
#define ICE 0


int N, M;
std::vector< std::vector<int> > graph;
std::vector< std::vector<int> > visit;
std::vector< std::pair<int, int> > vertex;

void	dfs(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= M)
		return ;

	visit[x][y] = VISIT;

/* dfs adjacent */
	if (graph[x - 1][y] != ICE && visit[x - 1][y] == NONVISIT)
		dfs(x - 1, y);
	if (graph[x + 1][y] != ICE && visit[x + 1][y] == NONVISIT)
		dfs(x + 1, y);
	if (graph[x][y - 1] != ICE && visit[x][y - 1] == NONVISIT)
		dfs(x, y - 1);
	if (graph[x][y + 1] != ICE && visit[x][y + 1] == NONVISIT)
		dfs(x, y + 1);
}

void	melting()
{
	int numEdge[N][M];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (graph[i][j] == ICE)
				numEdge[i][j] = 0;
			else
			{
				numEdge[i][j] = 4;
				if (graph[i - 1][j] == ICE)
					numEdge[i][j]--;
				if (graph[i + 1][j] == ICE)
					numEdge[i][j]--;
				if (graph[i][j - 1] == ICE)
					numEdge[i][j]--;
				if (graph[i][j + 1] == ICE)
					numEdge[i][j]--;
				// calculate num edge
			}
		}
	}

	int vertexSize = vertex.size();
	for (int i = 0; i < vertexSize; i++)
	{
		if (graph[vertex[i].first][vertex[i].second] >= 4 - numEdge[vertex[i].first][vertex[i].second])
			graph[vertex[i].first][vertex[i].second] -= (4 - numEdge[vertex[i].first][vertex[i].second]);
		else
			graph[vertex[i].first][vertex[i].second] = 0;
	}
}

int main(void)
{
	int num;

	std::cin >> N >> M;

/* Set graph and visit size */
	graph.reserve(N);
	visit.reserve(N);
	for (int i = 0; i < N; i++)
	{
		graph[i].reserve(M);
		visit[i].reserve(M);
	}

/* Set graph input */	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			std::cin >> num;
			graph[i].push_back(num);
		}
	}

	int year = 0;
	int vertexSize;
	int numChunk;
	while (1)
	{

/* Init visit and vertex */
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				visit[i].push_back(NONVISIT);
				if (graph[i][j] != ICE)
					vertex.push_back(std::pair<int, int>(i, j));
			}
		}

		vertexSize = vertex.size();
		numChunk = 0;

		for (int i = 0; i < vertexSize; i++)
		{
			if (visit[vertex[i].first][vertex[i].second] == NONVISIT)
			{
				dfs(vertex[i].first, vertex[i].second);
				numChunk++;
			}
		}

		if (vertexSize == 0)
		{
			std::cout << "0\n";
			break ;
		}

		if (numChunk >= 2)
		{
			std::cout << year << "\n";
			break ;
		}
		else
		{
			year++;
			melting();
		}

/* clear */
		vertex.clear();
		for(int i = 0; i < N; i++)
			visit[i].clear();
		visit.clear();
	}

	return (0);
}