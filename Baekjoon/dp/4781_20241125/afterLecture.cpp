#include <iostream>
#include <vector>

#define UNDEFINED -1

int n;
double m;

// first : calorie, second : price
std::vector<std::pair<int, double> >	candy;
// store pair (remain money, nth candy)
std::vector<std::vector<int> >			dp;

int	solve(double remainMoney, int iCandy)
{
	int	intRemainMoney = static_cast<int>(remainMoney * 100 + 0.5);
	int	max;
	int	cnt;
	int	temp;

/* degenerate case */
	// choose last candy
	if (iCandy == n - 1)
		return (static_cast<int>(remainMoney / candy[iCandy].second)
				* candy[iCandy].first);

	// already calculate
	if (dp[intRemainMoney][iCandy] != UNDEFINED)
		return (dp[intRemainMoney][iCandy]);

	max = 0;
	cnt = static_cast<int>(remainMoney / candy[iCandy].second);
	for (int i = 0; i <= cnt; i++)
	{
		temp = solve(remainMoney - i * candy[iCandy].second, iCandy + 1) + i * candy[iCandy].first;
		if (max < temp)
			max = temp;
	}
	dp[intRemainMoney][iCandy] = max;

	return (max);
}

int main(void)
{
	while (1)
	{
	/* input data */
		std::cin >> n >> m;

		// done
		if (n == 0 && m == 0.0)
			break ;
		
		candy.resize(n);
		for (int i = 0; i < n; i++)
			std::cin >> candy[i].first >> candy[i].second;
	
	/* init dp */
		dp.resize(static_cast<int>(m * 100 + 0.5) + 1);
		for (size_t i = 0; i < dp.size(); i++)
		{
			dp[i].resize(n);
			for (int j = 0; j < n; j++)
				dp[i][j] = UNDEFINED;
		}

	/* print result */
		std::cout << solve(m, 0) << "\n";

	/* clear data */
		candy.clear();
		for (size_t i = 0; i < dp.size(); i++)
			dp[i].clear();
		dp.clear();
	}

	return (0);
}