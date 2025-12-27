#include <iostream>

using namespace std;

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int	N, temp;
	int	*min_N;

	/* Set initial input */
	cin >> N;
	min_N = new int[N + 1];

	/* Find min 1 to N */
	for (int n = 1; n <= N; n++)
	{
		if (n == 1)
			min_N[n] = 0;
		else
		{
			temp = min_N[n - 1] + 1;
			if (n % 2 == 0 && min_N[n / 2] + 1 < temp)
				temp = min_N[n / 2] + 1;
			if (n % 3 == 0 && min_N[n / 3] + 1 < temp)
				temp = min_N[n / 3] + 1;
			min_N[n] = temp;
		}
	}

	/* Print result */
	cout << min_N[N] << "\n";

	/* Free memory */
	delete [] min_N;

	return (0);
}
