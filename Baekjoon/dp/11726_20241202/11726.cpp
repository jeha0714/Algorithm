#include <iostream>
#include <vector>

#define UNDEFINED -1

int n; // size of rectangular
std::vector<int>	dp;

int	solve(int k)
{
	if (k == 1)
		return (1);
	else if (k == 2)
		return (2);
	else if (dp[k] != UNDEFINED)
		return (dp[k]);

	dp[k] = solve(k - 1) + solve(k - 2);	
	if (dp[k] > 10007)
		dp[k] %= 10007;
	return (dp[k]);
}

int main(void)
{
/* input data */
	std::cin >> n;

	// init dp
	dp.resize(n + 1);
	for (int i = 1; i <= n; i++)
		dp[i] = UNDEFINED;

/* print result */
	std::cout << solve(n) << "\n";

	return (0);
}
