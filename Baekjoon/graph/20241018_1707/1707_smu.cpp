#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> graph[10001];
int visit[10001];

int flag_bg;

/* 2단계 graph에서의 dfs 구현 */
void dfs(int u, int flag)
{
	visit[u] = flag;
	flag = (flag + 1) % 2; /* flag이 0이면 1이 되고, 1이면 0이 됨 */

	int w;
	for (int i = 0; i < graph[u].size(); i++)
	{
		w = graph[u][i];

		if (visit[w] == -1)
			dfs(w, flag);
		else if (visit[u] == visit[w]) /* 나의 flag와 내 이웃의 flag이 같음 --> bipartite graph가 아님*/
			flag_bg = 0;
	}
}

int main(void)
{
/* 1단계  자료구조 및 데이터 입력 과정 구현 */
	FILE* fp;
	fp = fopen("input.txt", "r");

	int tc;
	int ans;
	int u, v;
	fscanf(fp, "%d", &tc);
	for (int i = 0; i < tc; i++)
	{
		fscanf(fp, "%d %d", &n, &m);
		for (int j = 1; j <= n; j++)
			graph[j].clear();

		for (int j = 1; j <= m; j++)
		{
			fscanf(fp, "%d %d", &u, &v);
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		fscanf(fp, "%d", &ans);

		for (int j = 1; j <= n; j++)
			sort(graph[j].begin(), graph[j].end());

		for (int j = 1; j <= n; j++)
			visit[j] = -1;

		flag_bg = 1;
		for (int j = 1; j <= n; j++)
		{
			if (visit[j] == -1)
				dfs(j, 0);
		}

		printf("%d --> %d\n", ans, flag_bg);
	}

	fclose(fp);
	return (0);
}
