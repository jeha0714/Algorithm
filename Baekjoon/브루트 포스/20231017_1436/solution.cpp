#include <iostream>

/* Check number of end */
int	is_number_of_end(int num)
{
	int	consequtive;

	consequtive = 0;
	while (num > 0)
	{
		if (num % 10 == 6)
			consequtive++;
		else
			consequtive = 0;
		if (consequtive == 3)
			break ;
		num /= 10;
	}
	if (consequtive >= 3)
		return (1);
	else
		return (0);
}

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N;
	int	result;
	
	/* Set initial input */
	std::cin >> N;
	result = 0;

	/* Find nth number of end */
	while (N > 0)
	{
		result++;
		if (is_number_of_end(result) == 1)
			N--;
	}

	/* Print result */
	std::cout << result << "\n";

	return (0);
}
