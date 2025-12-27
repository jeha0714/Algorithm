#include <iostream>
#include <vector>
#include <algorithm>

#define UNDEFINED -1
#define NONDIVIDED 0
#define DIVIDED 1

int N; // # of coin type
std::vector< std::pair<int, int> >	coin; // pair of (price, # of coin)
std::vector<int> 					dp; // remain Money that Divieded or NONDivided

int	total = 0; // total price of all coin

bool	greater(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
	return (a.first < b.first);
}

/* parameter */
	// 1. curent Price, 2. index coin
int	solve(int cP, std::vector<std::pair<int, int> > vCoin)
{
	int	temp;

/* degenerate case */
	// if alr calculated
	if (dp[cP] != UNDEFINED)
		return (dp[cP]);

	// last coin

	// early stop
	if (cP == total / 2)
		return (DIVIDED);

/*	do dp */
	for (int i = 0; i < N; i++)
	{
		// it good for after sort
		// if (cP + i * coin[i].first > total / 2)
		// 	break ;

		if (vCoin[i].second > 0)
		{
			vCoin[i].second -= 1; // decrease 1 coin
			if (solve(cP + coin[i].first, vCoin) == DIVIDED)
				return (DIVIDED);
		}
	}

	dp[cP] = NONDIVIDED;
	return (NONDIVIDED);
}

int main(void)
{

	for (int tc = 0; tc < 3; tc++)
	{

	/* input data */
		std::cin >> N;

		coin.resize(N);
		for (int i = 0; i < N; i++)
			std::cin >> coin[i].first >> coin[i].second;
		
	/* set total price of coins */
		for (int i = 0; i < N; i++)
			total += (coin[i].first * coin[i].second);

	/* init dp */
		dp.resize(total + 1);
		for (int i = 0; i <= total; i++)
			dp[i] = UNDEFINED;
	
	/* print result */
		if (total % 2 != 0)
			std::cout << NONDIVIDED << "\n";
		else // do dp!
			std::cout << solve(0, coin) << "\n";
		
	/* clear data */
		coin.clear();
		dp.clear();
		total = 0;
	}

	return (0);
}
