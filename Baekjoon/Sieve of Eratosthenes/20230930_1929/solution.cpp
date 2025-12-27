#include <iostream>
#include <cmath> // sqrt

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int	N,M;
	int *sequence;

	/* Set initial input */
	std::cin >> M >> N;
	sequence = new int[N + 1];
	for (int n = 1; n <= N; n++)
		sequence[n] = 1;

	/* Sieve of Eratosthenes */
		// Find prime number below the root N
	for (int n = 1; n <= sqrt(N); n++)
	{
		if (n == 1)
			sequence[n] = 0;
		else if (n != 1 && sequence[n] == 1)
		{
			for (int compare = 2; compare < n; compare++)
			{
				if (n % compare == 0)
					sequence[n] = 0;
			}
		}
		// Check not prime number below the N
		if (sequence[n] == 1)
		{
			for (int i = 2; n * i <= N; i++)
				sequence[n * i] = 0;
		}
	}

	/* Print result*/
	for (int n = M; n <= N; n++)
	{
		if (sequence[n] == 1)
			std::cout << n << "\n";
	}

	return (0);
}
