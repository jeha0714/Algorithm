#include <iostream>
#include <algorithm>

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int	N;
	int	*sequence;
	
	/* Set initial input */
	std::cin >> N;
	sequence = new int[N];
	for (int i = 0; i < N; i++)
		std::cin >> sequence[i];

	/* Sort */
	std::sort(sequence, sequence + N);

	/* Print */
	for (int i = 0 ; i < N; i++)
		std::cout << sequence[i] << "\n";

	return (0);
}
