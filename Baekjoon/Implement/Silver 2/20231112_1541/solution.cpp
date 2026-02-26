#include <iostream>
#include <string>

using namespace std;

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	string	formula;
	int32_t	temp;
	int32_t	index;
	int32_t	result;

	/* Set initial input */
	cin >> formula;
	index = 0;
		// set result to first number
	result = atoi(&(formula[index]));
		// set index to first operator
	while ('0' <= formula[index] && formula[index] <= '9')
		index++;

	/* Parsing and calculate */
	while (formula[index])
	{
		// Just add number if + operator
		if (formula[index] == '+')
		{
			index++;
			result += atoi(&(formula[index]));
		}
		// Subtract
		// Try to subtract most biggest number 
		else if (formula[index] == '-')
		{
			index++;
			temp = atoi(&(formula[index]));
			// make biggest number
			// ex) 1 + 2 - 3 + 4 + 5 + 6 - 7
			// ex) 1 + 2 - (3 + 4 + 5 + 6) - 7
			while (formula[index] != '-' && formula[index] != '\0')
			{
				if (formula[index] == '+')
				{
					index++;
					temp += atoi(&(formula[index]));
				}
				else
					index++;
			}
			result -= temp;
			if (formula[index] == '\0')
				break ;
		}
		else
			index++;
	}

	/* Print result */
	cout << result << "\n";

	return (0);
}
