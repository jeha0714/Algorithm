#include <iostream>
#include <queue> // queue 

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N, K;
	int num;
	std::queue<int> sequence;
	
	/* Set initial input */
	std::cin >> N >> K;
	for (int i = 1; i <= N; i++)
		sequence.push(i);

	/* Find sequence */
	std::cout << "<";

	num = 1;
	while (sequence.size() != 0)
	{
		// pop and push again if K-1th people
		if (num < K)
		{
			sequence.push(sequence.front());
			sequence.pop();
			num++;
		}
		// pop and print if Kth people
		else if (num == K)
		{
			if (sequence.size() > 1)
				std::cout << sequence.front() << ", ";
			else if (sequence.size() == 1)
				std::cout << sequence.front();
			sequence.pop();
			num = 1;
		}
	}

	std::cout << ">\n";

	return (0);
}
