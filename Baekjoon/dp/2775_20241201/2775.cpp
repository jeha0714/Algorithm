#include <iostream>
#include <vector>

#define UNDEFINED -1

int k, n;
std::vector< std::vector<int> >	dp;

int	solve(int k, int n)
{
	int	sum = 0;

/* degenerate case */
	if (k == 0)
		return (dp[k][n]);
	else if (dp[k][n] != UNDEFINED)
		return (dp[k][n]);
	
	for (int i = 1; i <= n; i++)
		sum += solve(k - 1, i);
	
	dp[k][n] = sum;
	return (sum);
}

int main(void)
{
	int	T; // # of test case
	
/* input data */
	std::cin >> T;
	for (int tc = 0; tc < T; tc++)
	{
		std::cin >> k >> n;

	/* init dp*/
		dp.resize(k + 1);
		for (int i = 0; i <= k; i++)
			dp[i].resize(n + 1);

		for (int i = 1; i <= n; i++)
			dp[0][i] = i;
		for (int i = 1; i <= k; i++)
		{
			for (int j = 1; j <= n; j++)
				dp[i][j] = UNDEFINED;
		}

		std::cout << solve(k, n) << "\n";
	}

	return (0);
}