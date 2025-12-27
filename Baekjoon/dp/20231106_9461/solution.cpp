#include <iostream>

using namespace std;

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int			T, N;
	long long	*P;

	/* Set initial input */
	cin >> T;
	P = new long long[101]();
	P[1] = 1;
	P[2] = 1;
	P[3] = 1;
	P[4] = 2;
	P[5] = 2;

	/* Print result in each case */
	for (int nth_test = 1; nth_test <= T; nth_test++)
	{
		cin >> N;
		if (P[N] == 0)
		{
			for (int i = 6; i <= N; i++)
			{
				if (P[i] == 0)
					P[i] = P[i - 1] + P[i - 5];
			}
		}
		cout << P[N] << "\n";
	}

	/* Free memory */
	delete[] P;

	return (0);
}
