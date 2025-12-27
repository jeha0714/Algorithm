#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace	std;

/* 자료 구조 */
int	n, m;
vector<pair<int, int> > graph[10001];
int	dist[10001];
int	pre[10001];

int	solve(int s)
{
	/* 초기화 */
	for (int i = 1; i <= n; i++)
	{
		dist[i] = 10000000;
		pre[i] = -1;
	}
	dist[s] = 0;
	pre[s] = -1;

	/* 최단 거리 계산 */
	int	u, v, luv;
	/* n - 1번 수행 */
	for (int i = 1; i < n; i++)
	{
		/* 모든 edge에 대해서 */
		for (int u = 1; u <= n; u++)
		{
			/* u의 모든 edge에 대해서  */
			for (int k = 0; k < graph[u].size(); k++)
			{
				v = graph[u][k].first;
				luv = graph[u][k].second;
				if (dist[u] != 10000000 && dist[v] > dist[u] + luv)
				{
					dist[v] = dist[u] + luv;
					pre[v] = u;
				}
			}
		}
	}

	/* negative cycle 존재 여부 확인 */
	int	ncflag = 0;
	for (int u = 1; u <= n; u++)
	{
		for (int k = 0; k < graph[u].size(); k++)
		{
			v = graph[u][k].first;
			luv = graph[u][k].second;
			if (dist[u] != 10000000 && dist[v] > dist[u] + luv)
			{
				ncflag = 1;
			}
		}
	}
	
	return (ncflag); /* negative cycle이 존재 */
}

int main(void)
{
	FILE *fp;
	fp = fopen("input.txt", "r");

	int	tc;
	int	u, v, w;

	fscanf(fp, "%d", &tc);
	for (int i = 0; i < tc; i++)
	{
		fscanf(fp, "%d %d", &n, &m);

		/* 그래프 초기화 */
		for (int j = 1; j <= n; j++)
			graph[j].clear();

		/* weighted directed graph 입력 */
		for (int j = 1; j <= m; j++)
		{
			fscanf(fp, "%d %d %d", &u, &v, &w);
			graph[u].push_back(make_pair(v, w));
		}
		for (int j = 1; j <= m; j++)
			sort(graph[j].begin(), graph[j].end());

		/* bellman-ford 호출 */
		if (solve(1)) // negative cycle이 존재
			printf("-1\n");
		else
		{
			for (int j = 2; j <= n; j++)
			{
				if (dist[j] == 10000000) // INF
					printf("-1\n");
				else
					printf("%d\n", dist[j]);
			}
		}
		printf("\n");
	}

	fclose(fp);
	return (0);
}
