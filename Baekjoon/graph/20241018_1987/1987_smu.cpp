#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

/* 자료 구조 */
int R, C; /* map의 크기 */
char graph[20][20]; /* graph의 값은 'A' ~ 'Z' */
int visit[26];

int maxd;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void dfs(int x, int y, int dist)
{
	int nx, ny;
	visit[graph[x][y] - 'A'] = 1;

	if (dist > maxd)
		maxd = dist;

	/* 상하좌우 이동 */
	for (int i = 0; i < 4; i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];

		/* map을 벗어나는 경우를 배제 */
		if (nx < 0 || ny < 0 || nx >= R || ny >= C)
			continue;
		
		if (visit[graph[nx][ny] - 'A'] == 0)
		{
			dfs(nx, ny, dist + 1);
			visit[graph[nx][ny] - 'A'] = 0;
		}
	}
}

int main(void)
{
	FILE* fp;
	fp = fopen("input.txt", "r");

	int tc;
	char c;
	int ans;
	fscanf(fp, "%d", &tc);
	for (int i = 0; i < tc; i++)
	{
		fscanf(fp, "%d %d", &R, &C);
		fscanf(fp, "%c", &c); /* carriage return을 읽어들임 */
		for (int j = 0; j < R; j++)
		{
			for (int k = 0; k < C; k++)
				fscanf(fp, "%c", &graph[j][k]);
			fscanf(fp, "%c", &c); /* carriage return을 읽어들임 */
		}
		fscanf(fp, "%d", &ans);

		for (int j = 0; j < 26; j++)
			visit[j] = 0;

		maxd = 0;
		dfs(0, 0, 1);
		printf("%d --> %d\n", ans, maxd);
	}

	fclose(fp);
	return (0);
}