#include <iostream>
#include <cmath>

using namespace std;

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	u_int32_t	n;
	u_int32_t	*min_method;

	/* Set initial input */
	cin >> n;
	min_method = new u_int32_t[n + 1]();

	/* Find solution */
	min_method[1] = 1;
	for (u_int32_t i = 2; i <= n; i++)
	{
		if (sqrt(i) - (u_int32_t)sqrt(i) == 0)
			min_method[i] = 1;
		else
		{
			min_method[i] = 4; // set worst case 4
			for (u_int32_t j = 1; j * j < i; j++)
				// example) we can show F(123) to F(11 * 11) + F(2)
				min_method[i] = min(min_method[i],
									min_method[j * j] + min_method[i - j * j]);
		}
	}

	/* Print result */
	cout << min_method[n] << "\n";

	/* Free memory */
	delete[] min_method;

	return (0);
}
