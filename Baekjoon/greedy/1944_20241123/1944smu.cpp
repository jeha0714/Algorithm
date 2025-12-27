#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

/* skgraph */
int 	n, m; /* n: skgraph의 vertex의 수, m: skgraph의 edge의 수 */
vector< pair<int, int> >	vertex;
vector< pair<int, int> >	graph[2501];
pair<int, int>				start;

/* mapgraph */
char	map[50][50]; /* map graph */
int		dist[50][50];
int		visits[2501];

int	prim()
{
	vector< pair<int, int> >	mcst;
	vector<int>	U;
	priority_queue< pair<int, pair<int, int> >, vector< pair<int, pair<int, int> > >, greater<> > pq;

	for (int i = 0; i < n; i++)
		visits[i] = 0;
	
	int u, v, w;

	/* U 초기화 <-- start vertex를 U에 저장 */
	for (int i = 0; i < n; i++)
	{
		if (vertex[i].first == start.first && vertex[i].second == start.second)
		{
			u = i;
			break ;
		}
	}
	U.push_back(u);
	visits[u] = 1;
	for (int i = 0; i < graph[u].size(); i++)
	{
		v = graph[u][i].first;
		w = graph[u][i].second;
		pq.push(make_pair(w, make_pair(u, v)));
	}

	int rdist = 0;
	int no_mcst = 0;
	while (U.size() < n)
	{
		if (!pq.empty())
		{
			no_mcst = 1;
			break ;
		}

		u = pq.top().second.first;
		v = pq.top().second.second;
		w = pq.top().first;
		pq.pop();

		if (visits[u] == 0 || visits[v] == 1)
			continue ;
		
		mcst.push_back(make_pair(u, v));
		rdist += w;
		U.push_back(v);
		visits[v] = 1;

		for (int i = 0; i < graph[v].size(); i++)
		{
			u = graph[v][i].first;
			w = graph[v][i].second;
			if (visits[u] == 1)
				continue ;
			pq.push(make_pair(w, make_pair(v, u)));
		}
	}

	return rdist;
}

/* bfs를 이용해서 (x1, y1) (x2, y2) 사이의 거리 계산 */
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int	get_dist(int x1, int y1, int x2, int y2)
{
	int	vx, vy;
	int	nx, ny;

	queue< pair<int, int> > myq;

	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
			dist[i][j] = -1;
	}

	myq.push(make_pair(x1, y1));
	dist[x1][y1] = 0;

	while (!myq.empty())
	{
		vx = myq.front().first;
		vy = myq.front().second;
		myq.pop();

		for (int i = 0; i < 4; i++)
		{
			nx = vx + dx[i];
			ny = vy + dy[i];

			if (nx == x2 && ny == y2)
				return (dist[vx][vy] + 1);
			
			if (nx < 0 || nx >= 50 || ny < 0 || ny >= 50)
				continue; /* out of bound */
			
			if (map[nx][ny] == '1')
				continue;

			if (dist[nx][ny] == -1)
			{
				dist[nx][ny] = dist[vx][vy] + 1;
				myq.push(make_pair(nx, ny));
			}
		}
	}

	return (-1);
}

int main(void)
{
	FILE *fp;
	fp = fopen("input.txt", "r");
	int	tc;
	int	wid, nk;
	char ch;
	char str[50];
	int	ans;
	int	w;

	fscanf(fp, "%d", &tc);
	for (int t = 0; t < tc; t++)
	{
	/* mapgraph를 읽어서 S와 K를 추출 --> vertex에 저장 */
		/* 초기화 */
		vertex.clear();
		for (int i = 0; i < 50; i++)
		{
			for (int j = 0; j < 50; j++)
				map[i][j] = -1;
		}

		fscanf(fp, "%d %d", &wid, &nk);
		fscanf(fp, "%c", &ch);
		for (int i = 0; i < wid; i++)
		{
			fgets(str, 50, fp);
			for (int j = 0; j < wid; j++)
			{
				map[i][j] = str[j];
				/* S와 K를 추출 */
				if (str[j] == 'S')
				{
					start = make_pair(i, j);
					vertex.push_back(make_pair(i, j));
				}
				if (str[j] == 'K')
					vertex.push_back(make_pair(i, j));
			}
		}
		fscanf(fp, "%d", &ans);

		/* skgraph 구축 */
		n = vertex.size();
		/* 초기화 */
		for (int i = 0; i < n; i++)
			graph[i].clear();
		
		/* no_path flag 설정 */
		int no_path = 0;

		/* edge 생성 */
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				w = get_dist(vertex[i].first, vertex[i].second, vertex[j].first, vertex[j].second);
				graph[i].push_back(make_pair(j, w));
				graph[j].push_back(make_pair(i, w));
				if (w < 0) /* i와 j 사이에는 경로가 없음 */
					no_path = 1;
			}
		}

		if (no_path)
			printf("%d --> -1\n", ans);
		else
			printf("%d --> %d\n", ans, prim());
	}




	fclose(fp);
	return (0);
}