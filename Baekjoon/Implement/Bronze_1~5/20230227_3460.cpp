#include <iostream>

int main ()
{
	int T; std::cin >> T;

	for (int now_T = 1; now_T <= T ; now_T++)
	{
		int n; std::cin >> n;
		for (int loc = 0; n != 0; loc++, n /= 2)
		{
			if (n % 2 == 1)
				std::cout << loc << " ";
		}
	}

	return (0);
}
