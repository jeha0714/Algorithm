#include <iostream>

using namespace std;

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	long long	N, K;
	long long	result;

	/* Set initial input */
	cin >> N >> K;
	result = 1;

	for (int i = N; i > N - K; i--)
		result *= i;
	for (int i = 2; i <= K; i++)
		result /= i;

	/* Print result */
	cout << result << "\n";

	return (0);
}