#include <stdio.h>
#include <stdlib.h>

int n, m;
int graph[10000][10000];
int ngraph[10000][10000];
int cc[10000][10000];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
// graph의 모든 cell이 0이면 1을 return, 아니면 0을 return
int melt_out()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (graph[i][j] > 0)
				return 0;
		}
	}

	return 1;
}

/* graph의 각 cell (x, y)에서 이웃한 0의 갯수를 세서 cell[x][y]에서 뺌 */
/* graph --> ngraph --> graph */
void	melt_graph()
{
	int nx, ny;

	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < m; y++)
		{
			if (graph[x][y] == 0) // 바닷물은 녹는 고려 x
			{
				ngraph[x][y] = 0;
				continue;
			}

			int cntzero = 0;
			for (int k = 0; k < 4; k++)
			{
				nx = x + dx[k];
				ny = y + dy[k];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m)
					continue;
				/* 이웃한 cell에서 0의 갯수를 셀 것*/
				if (graph[nx][ny] == 0)
					cntzero++;
			}
			ngraph[x][y] = graph[x][y] - cntzero;
			if (ngraph[x][y] < 0)
				ngraph[x][y] = 0;
		}
	}

	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++)
			graph[x][y] = ngraph[x][y];
}

void dfs_cc(int x, int y, int ccflag)
{
	int nx, ny;

	cc[x][y] = ccflag;

	for (int i = 0; i < 4; i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			continue;

		if (graph[nx][ny] == 0) // 바닷물이면 굳이 pass
			continue;

		if (cc[nx][ny] == 0)
			dfs_cc(nx, ny, ccflag);
	}
}

int dfs_cc()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cc[i][j] = 0;
	
	int ccflag = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (graph[i][j] == 0)
				continue;

			if (cc[i][j] == 0)
			{
				dfs_cc(i, j, ccflag);
				ccflag++;
			}
		}
	}

	return ccflag - 1;
}

int solve()
{
	int no_cc;
	int m_year = 0;

	if (melt_out())
		return 0;
	do
	{
		no_cc = dfs_cc();
		if (no_cc > 1)
			return m_year;

		melt_graph();
		if (melt_out())
			return 0;

		m_year++;
	} while (no_cc == 1); // 아직 분리되지 않았으면 반복

	return 0;
}

int main(void)
{
	FILE* fp;
	fp = fopen("input.txt", "r");

	int tc;
	int ans;
	fscanf(fp, "%d", &tc);
	for (int i = 0; i < tc; i++)
	{
		fscanf(fp, "%d %d", &n, &m);
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
				fscanf(fp, "%dd", &graph[j][k]);
		fscanf(fp, "%d", &ans);

		printf("%d --> %d\n", ans, solve());
	}

	fclose(fp);
	return (0);
}