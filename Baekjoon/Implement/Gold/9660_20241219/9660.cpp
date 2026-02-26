#include <iostream>

long long	N; // # of rock

int main(void)
{
/* input data */
	std::cin >> N;

/* print result */
	if (N % 7 == 0)
		std::cout << "CY\n";
	else if (N % 7 == 1)
		std::cout << "SK\n";
	else if (N % 7 == 2)
		std::cout << "CY\n";
	else if (N % 7 == 3)
		std::cout << "SK\n";
	else if (N % 7 == 4)
		std::cout << "SK\n";
	else if (N % 7 == 5)
		std::cout << "SK\n";
	else if (N % 7 == 6)
		std::cout << "SK\n";

	return (0);
}
