#include <iostream>
#include <vector>

#define UNDEFINED 2147483647

int N;
std::vector<int>	dp;

//n에서 1까지 가는 가장 적은 횟수를 구하자

int solve(int n)
{
/* degenerate case */
	if (n == 1)
		return (0);
	else if (dp[n] != UNDEFINED)
		return (dp[n]);
	
	if (n % 3 == 0)
		dp[n] = std::min(dp[n], solve(n / 3) + 1);
	if (n % 2 == 0)
		dp[n] = std::min(dp[n], solve(n / 2) + 1);
	if (n - 1 >= 0)
		dp[n] = std::min(dp[n], solve(n - 1) + 1);

	return (dp[n]);
}

int main(void)
{
/* input data */
	std::cin >> N;

	dp.resize(N + 1);
	for (int i = 0; i <= N; i++)
		dp[i] = UNDEFINED;
	
/* print result */
	std::cout << solve(N) << "\n";

	return (0);
}
