#include <iostream>

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N, M;
	int	value;
	int	*card_number;

	/* Set initial input */
	std::cin >> N;
	card_number = new int[20000001]();
	for (int i = 0; i < N; i++)
	{
		std::cin >> value;
		card_number[value + 10000000]++;
	}

	/* Print each case */
	std::cin >> M;
	for (int test_case = 1; test_case <= M; test_case++)
	{
		std::cin >> value;
		std::cout << card_number[value + 10000000] << " ";
	}
	std::cout << "\n";

	return (0);
}
