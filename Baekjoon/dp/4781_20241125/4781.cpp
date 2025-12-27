#include <iostream>
#include <vector>
#include <algorithm>

#define UNDEFINE -1

int 	n; // # of candy
double	m; // amount of money
std::vector< std::vector<int> >	candy(10001); // 10000 array for price * 100 (0.01 ~ 100.00 => 1 ~ 10000)
std::vector<int>				dp(10001, 0); // dp for max calorie each price

bool	descending(const int &a, const int &b)
{
	return (a > b);
}

int	dnc(int	p)
{
	if (dp[p] != UNDEFINE)
		return (dp[p]);
	else if (candy[p].size() != 0)
		dp[p] = candy[p][0];
	else
		dp[p] = 0;

	// for (int i = 1; i <= p / 2; i++)
	// {
	// 	dp[p] = std::max(dp[p], dnc(i) + dnc(p - i));
	// }

	for (int i = 1; i <= p / 2 ; i++)
	{
		if (!candy[i].empty())
			dp[p] = std::max(dp[p], candy[i][0] + dnc(p - i));
	}

	// std::cout << p << " " << dp[p] << "\n";
	// std::cout << p << " " << ret << "\n";
	return (dp[p]);
}

int main(void)
{
	// each calorie, price about candy
	int		c;
	double	p;

	while (1)
	{
	/* input data */
		// candy calorie and price
		std::cin >> n >> m;

		// finish
		if (n == 0 && m == 0.00)
			break ;
		
	/* set candy vector */
		candy.resize(10001);
		// clear
		for (int i = 1; i <= 10000; i++)	
			candy[i].clear();

		// init
		for (int i = 0; i < n; i++)
		{
			std::cin >> c >> p;
			if (candy[static_cast<int>(p * 100)].size() != 0 && candy[static_cast<int>(p * 100)][0] < c)
				candy[static_cast<int>(p * 100)][0] = c;
			else
				candy[static_cast<int>(p * 100)].push_back(c);
		}

		// sort candy to descending each price
		// for (int i = 1; i <= 10000; i++)
		// {
		// 	if (candy[i].size() > 1)
		// 		std::sort(candy[i].begin(), candy[i].end(), descending);
		// }

	/* set dp */
		// clear
		dp.clear();

		// init to undefine
		for (int i = 1; i <= static_cast<int>(m * 100); i++)
			dp[i] = UNDEFINE;

	/* dnc */
		dnc(static_cast<int>(m * 100));

	/* print result */
		std::cout << dp[static_cast<int>(m * 100)] << "\n";
	}

	return (0);	
}
