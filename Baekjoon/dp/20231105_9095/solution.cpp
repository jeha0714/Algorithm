#include <iostream>

using namespace std;

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int	T, n;
	int	*num_method_of_expression;

	/* Set initial input */
	cin >> T;
	num_method_of_expression = new int[12]();
	num_method_of_expression[1] = 1;
	num_method_of_expression[2] = 2;
	num_method_of_expression[3] = 4;
	num_method_of_expression[4] = 7;

	/* Print result in each case */
	for (int nth_test = 1; nth_test <= T; nth_test++)
	{
		cin >> n;
		if (num_method_of_expression[n] == 0)
		{
			for (int i = 5; i <= n; i++)
			{
				if (num_method_of_expression[i] == 0)
					num_method_of_expression[i] =
						num_method_of_expression[i - 1] * 2 - num_method_of_expression[i - 4];
			}
		}

		// Print result
		cout << num_method_of_expression[n] << "\n";
	}

	/* Free memory */
	delete[] num_method_of_expression;

	return (0);
}
