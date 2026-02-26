#include <iostream>
#include <algorithm> // sort
#include <cmath> // lround

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int n;
	int	*users_difficulty;
	long average_difficulty;

	/* Set initial input */
	std::cin >> n;
	users_difficulty = new int[n];
	for (int i = 0; i < n; i++)
		std::cin >> users_difficulty[i];

	/* Sort users_difficulty */
	std::sort(users_difficulty, users_difficulty + n);

	/* Calculate average_difficulty */
	average_difficulty = 0;
		// Sum 70% of users
	for (long i = lround(n * 0.15); i < n - lround(n * 0.15) ;i++)
		average_difficulty += users_difficulty[i];
	
		// Find average
	if (n == 0)
		average_difficulty = 0;
	else
		average_difficulty = lround(average_difficulty / (double)(n - lround(n * 0.15) * 2));

	/* Print result */
	std::cout << average_difficulty << "\n";

	return (0);
}
