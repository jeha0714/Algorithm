#include <iostream>

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N;
	int num_two, num_five;
	
	/* Set initial input */
	std::cin >> N;

	/* Find quotient! */
	num_two = 0;
	num_five = 0;
	for (int i = 1; i <= N; i++)
	{
		if (i % 2 == 0)
		{
			int temp = i;
			while (temp % 2 == 0)
			{
				num_two++;
				temp /= 2;
			}
		}
		if (i % 5 == 0)
		{
			int temp = i;
			while (temp % 5 == 0)
			{
				num_five++;
				temp /= 5;
			}
		}
	}

	/* Print result */
	if (num_two < num_five)
		std::cout << num_two << "\n";
	else
		std::cout << num_five << "\n";

	return (0);
}
