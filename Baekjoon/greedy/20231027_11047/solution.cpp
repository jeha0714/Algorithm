#include <iostream>

using namespace std;

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int	N, K;
	int	*worth_of_coins;
	int	num_coins;
	
	/* Set initial input */
	cin >> N >> K;
	worth_of_coins = new int[N]();
	for (int i = 0 ; i < N; i++)
		cin >> worth_of_coins[i];
	
	/* Find min num of coins */
	num_coins = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		if (K / worth_of_coins[i] == 0)
			continue;
		else
		{
			num_coins += (K / worth_of_coins[i]);
			K %= worth_of_coins[i];
		}
	}

	/* Print result */
	cout << num_coins << "\n";

	return (0);
}
