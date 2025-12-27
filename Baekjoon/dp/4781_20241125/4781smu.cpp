#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <vector>

using namespace std;

/* 자료 구조 */
int n, m; /* n: 사탕의 종류, m: 내가 가진 돈 */
pair<int, int> candy[5001]; /* 칼로리(이익) + 가격(무게) */

int cal(int C, int k)
{
/* degenerate case: 마지막 사탕 --> k == n */
	if (k == n)
	{
		return candy[k].first * (int)(C / candy[k].second);
	}

	int remain = C;
	int	temp;
	int	max_cal;
	int cnt = 0; /* 선택한 사탕의 갯수 count */
	max_cal = cal(C, k + 1); /* k번째 사탕을 안고르고 다음 사탕으로 넘어간 경우 */
	while (remain >= candy[k].second) /* 남은 금액이 사탕 가격보다 크거나 같은 동안 진행 */
	{
		remain -= candy[k].second;
		cnt++;
		temp = cal(remain, k + 1) + cnt * candy[k].first;
		if (temp > max_cal)
			max_cal = temp;
	}
	return (max_cal);
}

int solve()
{
	return (cal(m, 1));
}

int main(void)
{
	FILE *fp;
	fp = fopen("input.txt", "r");
	int tc;
	int a;
	float b;
	int ans;

	fscanf(fp, "%d", &tc);
	for (int t = 0; t< tc; t++)
	{
		fscanf(fp, "%d %f", &a, &b);
		n = a;
		m = (int)(b * 100.0 + 0.5);
		for (int i = 1; i <= n; i++)
		{
			fscanf(fp, "%d %f", &a, &b);
			candy[i] = make_pair(a, (int(b * 100.0 + 0.5)));
		}
		fscanf(fp, "%d", &ans);
		printf("%d --> %d\n", ans, solve());
	}

	fclose(fp);
	return (0);
}