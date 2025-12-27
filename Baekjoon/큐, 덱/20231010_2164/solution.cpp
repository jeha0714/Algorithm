#include <iostream>
#include <deque> // deque data_structure

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N;
	int temp;
	std::deque <int> sequence(0);

	/* Set initial input */
	std::cin >> N;
	for (int i = 1; i <= N; i++)
		sequence.push_back(i);

	/* Execute card rule */
	while (sequence.size() != 1)
	{
		sequence.pop_front();
		temp = sequence.front();
		sequence.pop_front();
		sequence.push_back(temp);
	}

	/* Print last card number */
	std::cout << sequence.front() << "\n";

	return (0);
}
