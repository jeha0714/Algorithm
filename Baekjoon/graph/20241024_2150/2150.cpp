#include <iostream>
#include <vector>
#include <algorithm>

#define NONVISIT 0
#define VISIT 1

int	V, E;
int ccflag;
int cclock;

std::vector<int> visit;
std::vector< std::vector<int> > graph;
std::vector< std::vector<int> > graphR;
std::vector<int> pre;
std::vector<int> post;
std::vector<int> vCcflag;
std::vector< std::vector<int> > scc;

/* set Pre number function */
void	setPre(int n)
{
	pre[n] = cclock++;
}

/* set Post number function */
void	setPost(int n)
{
	post[n] = cclock++;
}

/* dfs function 
		set Pre & Post number */
void	dfsR(int n)
{
	int	edgeSize = graphR[n].size();

	visit[n] = VISIT;

// set pre num for vertex n
	setPre(n);
	for (int i = 0; i < edgeSize; i++)
	{
		if (visit[graphR[n][i]] == NONVISIT)
			dfsR(graphR[n][i]);
	}
// set post num for vertex n
	setPost(n);
}

/* get Max Post Vertex number function */
int	getMaxPostVertex()
{
	int currentMaxVertex = 0;

	post[currentMaxVertex] = 0;

	for (int i = 1; i <= V; i++)
	{
		if (visit[i] == NONVISIT && post[i] > post[currentMaxVertex])
			currentMaxVertex = i;
	}

	return (currentMaxVertex);
}

/* dfs function
		set ccflag */
void	dfsC(int n)
{
	int	edgeSize = graph[n].size();

	visit[n] = VISIT;
	vCcflag[n] = ccflag;

	for (int i = 0; i < edgeSize; i++)
	{
		if (visit[graph[n][i]] == NONVISIT)
			dfsC(graph[n][i]);
	}

}

/* main function */
int	main(void)
{
// set V E
	std::cin >> V >> E;

// set capacity visit, graph, graphR, pre, post, vCcflag
	visit.reserve(V + 1);
	graph.reserve(V + 1);
	graphR.reserve(V + 1);
	pre.reserve(V + 1);
	post.reserve(V + 1);
	vCcflag.reserve(V + 1);

// set edge info
	int	s, e;
	for (int i = 0; i < E; i++)
	{
		std::cin >> s >> e;
		graph[s].push_back(e);
		graphR[e].push_back(s);
	}

// sort each edge info
// reset visit
	for (int i = 1; i <= V; i++)
	{
		std::sort(graph[i].begin(), graph[i].end());
		std::sort(graphR[i].begin(), graphR[i].end());
		visit[i] = NONVISIT;
	}

// setcclock 
	cclock = 1;

// dfs graphR
	for (int i = 1; i <= V; i++)
	{
		if (visit[i] == NONVISIT)
			dfsR(i);
	}

// reset visit
	for (int i = 1; i <= V; i++)
		visit[i] = NONVISIT;

// set ccflag
	ccflag = 1;

// dfs graph 
// Rule. dfs first for most high post num
	int maxPostVertex;
	while (1)
	{
		if ((maxPostVertex = getMaxPostVertex()) == 0)
			break ;
		
		dfsC(maxPostVertex);

		ccflag++;
	}

// set scc
	for (int i = 1; i < ccflag; i++)
	{
		scc.push_back(std::vector<int>());
		for (int j = 1; j <= V; j++)
		{
			if (vCcflag[j] == i)
				scc[i - 1].push_back(j);
		}
	}

// sort scc ascendent
	std::sort(scc.begin(), scc.end());

// print result
	int ccSize;
	std::cout << ccflag - 1 << "\n";
	for (int i = 0; i < ccflag - 1; i++)
	{
		ccSize = scc[i].size();
		for (int j = 0; j < ccSize; j++)
			std::cout << scc[i][j] << " ";
		std::cout << "-1\n";
	}

	return (0);
}