#include <iostream>

using namespace std;

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int32_t	n;
	int32_t	*method;

	/* Set initial input */
	cin >> n;
	method = new int[n + 1]();

	/* Find num method in each rectangle */
	method[1] = 1;
	method[2] = 3;
	for(int nth = 3; nth <= n; nth++)
	{
		method[nth] = method[nth - 1] + method[nth - 2] * 2;

		// F(x) = Q(x) * 10007 + R(x)
		method[nth] %= 10007;
	}

	/* Print result */
	cout << method[n] << "\n";

	/* Free memory */
	delete[] method;

	return (0);
}
