#include <iostream>
#include <vector>

#define UNDEFINED -1
#define NONDIVIDED 0
#define DIVIDED 1

int N; // # of coin type
std::vector< std::pair<int, int> > coin; // pair of (price, # of coin)
std::vector< std::vector<int> > dp; // store dp[current total price][index coin]

int	total = 0; // total price of all coin

/* parameter */
	// 1. curent Price, 2. index coin
int	solve(int cP, int iCoin)
{
	int	temp;

/* degenerate case */
	// early stop
	if (cP == total / 2)
		return (DIVIDED);

	// if alr calculated
	if (dp[cP][iCoin] != UNDEFINED)
		return (dp[cP][iCoin]);

	// last coin
	if (iCoin == N - 1)
	{
		for (int i = 0; i <= coin[iCoin].second; i++)
		{
			if (cP + i * coin[iCoin].first == total / 2)
				return (DIVIDED);
		}
		dp[cP][iCoin] = NONDIVIDED;
		return (NONDIVIDED);
	}


/*	do dp */
	for (int i = 0; i <= coin[iCoin].second; i++)
	{
		if (cP + i * coin[iCoin].first > total / 2)
			break ;
		else if (solve(cP + i * coin[iCoin].first, iCoin + 1) == DIVIDED)
			return (DIVIDED);
	}

	dp[cP][iCoin] = NONDIVIDED;
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
		{
			dp[i].resize(N);
			for (int j = 0; j < N; j++)
				dp[i][j] = UNDEFINED;
		}
	
	/* print result */
		if (total % 2 != 0)
			std::cout << NONDIVIDED << "\n";
		else // do dp!
			std::cout << solve(0, 0) << "\n";
		
	/* clear data */
		coin.clear();
		for (int i = 0; i <= total; i++)
			dp[i].clear();
		dp.clear();
		total = 0;
	}

	return (0);
}
