#include <iostream>
#include <vector> // vector

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int K;
	int	value;
	int result;
	std::vector <int> sequence(0);

	/* Set initial input */
	std::cin >> K;
	for (int i = 0; i < K; i++)
	{
		std::cin >> value;
		// Distinguish whether input is 0 or not
		if (value == 0)
			sequence.pop_back();
		else
			sequence.push_back(value);
	}

	/* Sum all */
	result = 0;
	for (int i = 0; i < sequence.size(); i++)
		result += sequence[i];

	/* Print result */
	std::cout << result << "\n";

	return (0);
}
