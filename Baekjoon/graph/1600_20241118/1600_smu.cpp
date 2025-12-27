#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <utility>

using namespace std;

/* 자료구조 */
int	W, H, K;
int	map[200][200];
int	visit[200][200][30];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int hx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int hy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int solve() /* bfs 기반 */
{
/* 1. queue 선언 */
	/* queue의 원소는 (x, y)
					몇 번 이동했나를 세는 cnt
					몇 번 말 이동했냐를 새는 kcnt */

/* queue의 원소는 pair<x, y>, pair<cnt, kcnt> */
	queue<pair<pair<int, int>, pair<int, int> > >	myq;

/* 시작은 (0,0), cnt = 0, kcnt = 0 */
	visit[0][0][0] = 1;
	myq.push(make_pair(make_pair(0, 0), make_pair(0, 0)));

	int currx, curry, nextx, nexty;
	int cnt, kcnt;
/* while 문 (!myq.empty()) */
	while (!myq.empty())
	{
		/* 2. pop */
		currx = myq.front().first.first;
		curry = myq.front().first.second;
		cnt = myq.front().second.first;
		kcnt = myq.front().second.second;

		/* 3. 이동하면서 queue에 넣기 */
		/* 3.1 말 이동 구현 */
		/* 말 이동이 가능한지 확인 */
		if (kcnt < K)
		{
			for (int i = 0; i < 8; i++)
			{
				nextx = currx + hx[i];
				nexty = curry + hx[i];

				/* map 밖으로 나가는지 확인 */
				if (nextx < 0 || nextx >= W || nexty <0 || nexty >= H)
					continue ;
				/* 장애물 확인 */
				if (map[nextx][nexty] == 1)
					continue ;
				/* visit 확인 */
				if (visit[nextx][nexty][kcnt + 1] == 1)
					continue ;

				/* 목표에 도달 했니? */
				if (nextx == W - 1 && nexty == H - 1)
					return cnt + 1;
				
				/* visit을 1로 만들고 push */
				visit[nextx][nexty][kcnt + 1] = 1;
				myq.push(make_pair(make_pair(nextx, nexty), make_pair(cnt + 1, kcnt + 1)));
			}
		}

		/* 3.2 일반 이동 구현 */
		for (int i = 0; i < 4; i++)
		{
			nextx = currx + dx[i];
			nexty = currx + dy[i];

			/* map 밖으로 나가는지 확인 */
			if (nextx < 0 || nextx >= W || nexty <0 || nexty >= H)
				continue ;
			/* 장애물 확인 */
			if (map[nextx][nexty] == 1)
				continue ;
			/* visit 확인 */
			if (visit[nextx][nexty][kcnt] == 1)
				continue ;

			/* 목표에 도달 했니? */
			if (nextx == W - 1 && nexty == H - 1)
				return cnt + 1;
			
			/* visit을 1로 만들고 push */
			visit[nextx][nexty][kcnt] = 1;
			myq.push(make_pair(make_pair(nextx, nexty), make_pair(cnt + 1, kcnt)));
		}
	}

	return (-1);
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
		fscanf(fp, "%d", &K);
		fscanf(fp, "%d %d", &W, &H);

		/* 초기화 */
		for (int j = 0; j < H; j++)
		{
			for (int k = 0; k < W; k++)
				map[j][k] = 0;
		}

		/* map graph 읽기 */
		for (int j = 0; j < H; j++)
		{
			for (int k = 0; k < W; k++)
				fscanf(fp, "%d", &map[j][k]);
		}

		fscanf(fp, "%d", &ans);

		/* visit 초기화 */
		for (int j = 0; j < H; j++)
		{
			for (int k = 0; k < W; k++)
			{
				for (int t = 0; t < K; t++)
					visit[j][k][t] = 0;
			}
		}


		printf("%d --> %d\n", solve(), ans);
	}

	fclose(fp);
	return (0);
}
