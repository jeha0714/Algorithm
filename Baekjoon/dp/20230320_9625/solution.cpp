#include <iostream>

int main()
{
	// Input K
	int K; std::cin >> K;
	// Make a two-dimensional array that save num of A and B appreance
	unsigned long long **num_AB = new unsigned long long *[K + 1];
	for (int i = 1; i <= K; i++)
		num_AB[i] = new unsigned long long[2];

	// Initial value of A and B when K == 1
	num_AB[1][0] = 0;
	num_AB[1][1] = 1;

	// Rule of appearance of A and B when press K-times of button
	for (int i = 2; i <= K; i++)
	{
		num_AB[i][0] = num_AB[i - 1][1];
		num_AB[i][1] = num_AB[i - 1][0] + num_AB[i - 1][1];
	}

	// Print result
	printf("%lld %lld\n", num_AB[K][0], num_AB[K][1]);

	// free to two-dimensional array
	for (int i = 1; i <= K; i++)
		delete[] num_AB[i];
	delete[] num_AB;
	return (0);
}
