#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace	std;

int	n; /* vertex의 수 */
int cnt; /* leaf node의 수 */
vector<int>	graph[10001];
int	visit[10001];

/* v는 u의 parent */
/* c는 cut node */
void	dfs(int u, int v, int c)
{
	visit[u] = 1;

	if (u == c) /* 여기서 cut */
		return ;

	/* leaf node인지 확인 -> edge의 수가 1개이고 연결된 vertexㅇ가 부모 vertex(v) */
	if (graph[u].size() == 1 && graph[u][0] == v)
	{
		cnt++;
		return ;
	}

	int	w;
	for (int i = 0; i < graph[u].size(); i++)
	{
		w = graph[u][i];
		if (visit[w] == 0)
			dfs(w, u, c);
	}
}

int main(void)
{
	FILE *fp;
	fp = fopen("input.txt", "r");

	int	tc;
	int	u;
	int	c;
	int	ans;

	fscanf(fp, "%d", &tc);
	for (int i = 0; i < tc; i++)
	{
		fscanf(fp, "%d", &n);
		for (int j = 0; j < n; j++)
			graph[j].clear();

		fscanf(fp, "%d", &u); /* -1 읽어서 버리기 */
		for (int j = 1; j <= n; j++)
		{
			fscanf(fp, "%d", &u); /* 0을 읽음 -> 1번 vectex의 부모가 0번 -> j번째 vertex의 부모가 u번 */
			graph[j].push_back(u); /* j와 u를 연결 */
			graph[u].push_back(j); /* u와 j를 연결 */
		}
		fscanf(fp, "%d", &c);
		fscanf(fp, "%d", &ans);

		for (int j = 1; j < n; j++)
			sort(graph[j].begin(), graph[j].end());

		/* dfs */
		for (int j = 0; j <= n; j++)
			visit[j] = 0;

		cnt = 0; /* leaf node의 개수 초기화 */
		dfs(0, -1, c); /* 0번 vertex에서 시작, 0번 vertex의 부모는 -1, cut node는 c */
		printf("%d --> %d\n", ans, cnt);

	}

	fclose(fp);
	return (0);
}
