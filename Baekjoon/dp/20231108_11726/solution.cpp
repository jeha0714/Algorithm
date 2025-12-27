#include <iostream>

using namespace std;

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int				n;
	unsigned int	*num_method;

	/* Set initial input */
	cin >> n;
	num_method = new unsigned int[n + 1]();

	/* Find solution */
	num_method[1] = 1;
	num_method[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		num_method[i] = num_method[i - 1] + num_method[i - 2];
		num_method[i] %= 10007;

		// dp[a] = 10007 * Q(a) + R(a)
		// dp[a] % 10007 = R(a)
	}

	/* Print result */
	cout << num_method[n] << "\n";

	/* Free memory */
	delete[] num_method;

	return (0);
}
