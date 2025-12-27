#include <iostream>
#include <vector>

#define UNDEFINED -1

int n, m;

// first : calorie, second : price
std::vector<std::pair<int, int> >	candy;
// dp for remain money
std::vector<int>					dp;

int	solve(int remainMoney)
{
/* degenerate case */
	if (dp[remainMoney] != UNDEFINED)
		return (dp[remainMoney]);

	for (int i = 0; i < n; i++)
	{
		if (remainMoney - candy[i].second >= 0)
			dp[remainMoney] = std::max(dp[remainMoney]
						, solve(remainMoney - candy[i].second) + candy[i].first);
	}

	if (dp[remainMoney] == UNDEFINED)
		return (0);
	else
		return (dp[remainMoney]);
}

int main(void)
{
	float floatM;
	float tmp;

	while (1)
	{
	/* input data */
		std::cin >> n >> floatM;
		m = static_cast<int>(floatM * 100 + 0.5);

		// done
		if (n == 0 && m == 0)
			break ;
		
		candy.resize(n);
		for (int i = 0; i < n; i++)
		{
			std::cin >> candy[i].first >> tmp;
			candy[i].second = static_cast<int>(tmp * 100 + 0.5);
		}
	
	/* init dp */
		dp.resize(m + 1);
		for (size_t i = 0; i <= m; i++)
			dp[i] = UNDEFINED;

	/* print result */
		std::cout << solve(m) << "\n";

	/* clear data */
		candy.clear();
		dp.clear();
	}

	return (0);
}
