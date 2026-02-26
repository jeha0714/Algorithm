#include <iostream>
#include <vector>

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int len1, len2, len3;

	while (1)
	{
		// Insert and Set initial data
		std::cin >> len1 >> len2 >> len3;

		/* Stop condition! */
		if (len1 == 0 && len2 == 0 && len3 == 0)
			break ;

		/* Convert value! */
		len1 = len1 * len1;
		len2 = len2 * len2;
		len3 = len3 * len3;

		/* Print result! */
		if (len1 == len2 + len3 || len2 == len1 + len3 || len3 == len1 + len2)
			std::cout << "right\n";
		else
			std::cout << "wrong\n";

	}

	return (0);
}
