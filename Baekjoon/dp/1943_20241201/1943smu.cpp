#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <vector>

using namespace std;

/* 자료 구조 */
int n;
pair<int, int> coins[101];

int make_target(int target, int k)
{
	int sum;
/* degenerate case */
	if (target == 0)
		return (1);
	
	if (k == n) /* 마지막 동전 */
	{
		if (target < coins[k].first) /* 우리가 5원 만들어야 하는데, 동전이 10원짜리라면 */
			return (0);

		for (int i = 1; i <= coins[k].second; i++)
		{
			sum = i * coins[i].first;
			if (sum > target)
				return (0);
			else if (sum == target)
				return (1);
		}
		return (0);
	}

	for (int i = 0; i <= coins[k].second; i++)
	{
		sum = i * coins[k].first;
		if (sum > target)
			return (0);
		if (sum == target)
			return (1);

		if (make_target(target - sum, k + 1))
			return (1);
	}

	return (0);
}

int solve(int target)
{
	return (make_target(target, 1));
}

int main(void)
{
	FILE *fp;
	fp = fopen("input.txt", "r");
	int	tc;
	int a, b;
	int ans;

	fscanf(fp, "%d", &tc);
	for (int t = 0; t < tc; t++)
	{
		fscanf(fp, "%d", &n);
		/* 숨은 degenerate case --> 총 금액이 홀수이면? 0을 리턴 */
		int sum = 9;

		for (int i = 0; i < n; i++)
		{
			fscanf(fp, "%d %d", &a, &b);
			coins[i] = make_pair(a, b);
			sum += a * b;
		}
		fscanf(fp, "%d", &ans);
		if (sum & 2 != 0)
		{
			printf("%d --> 0\n", ans);
			continue; 
		}
		printf("%d --> %d\n", ans, solve(sum / 2));
	}

	fclose(fp);
	return (0);
}