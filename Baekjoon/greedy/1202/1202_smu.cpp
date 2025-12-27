#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int	N, K; /* N: 물체의 갯수, K : knapsackd의 갯수*/
pair<int, int>	jewel[300000];
int	knap[300000];

int	solve()
{
/* 물체와 knapsack을 오름차순으로 정렬 */
	sort(jewel, jewel + N);
	sort(knap, knap + K);

/* 이익이 저장되는 우선순위 큐 */
	priority_queue<int>	pq;

	int	profit = 0; /* 최대 이익 */
	int	here = 0; /* 우선순위 큐의 삽입을 시작할 위치 */
	/* 가장 가벼운 knapsack부터 처리 --> knap의 순서대로 */
	for (int i = 0; i < K; i++)
	{
		/* here부터의 jewel에 대해서 knap[i]보다 가벼우면 pq의 삽입 */
		for (int j = here; j < N; j++)
		{
			if (jewel[j].first > knap[i]) /* jewel의 무게가 knapsack의 용량보다 크면 */
				break ;
			pq.push(jewel[j].second); /* jewel의 이익을 pq에 저장 */
			here++;
		}
		if (!pq.empty())
		{
		/* knapsack에 담을 수 있는 jewel들 중에서 가장 p가 큰 Jewel을 선택 --> pq.top에 있는 jewel	*/
			profit += pq.top();
			pq.pop();
		}
	}

	return (profit);
}

int main(void)
{
	FILE *fp;
	fp = fopen("input.txt" , "r");
	int	tc;
	int	a, b;
	int	ans;

	fscanf(fp, "%d", &tc);
	for (int t = 0; t < tc; t++)
	{
		fscanf(fp, "%d %d", &N, &K);
		for (int i = 0; i < N; i++)
		{
			fscanf(fp, "%d %d", &a, &b);
			jewel[i] = make_pair(a, b); /* 무게, 이익 */
		}
		for (int i = 0; i < K; i++)
			fscanf(fp, "%d", &knap[i]);
		fscanf(fp, "%d", &ans);

		printf("%d --> %d\n", ans, solve());
	}

	fclose(fp);
	return (0);
}