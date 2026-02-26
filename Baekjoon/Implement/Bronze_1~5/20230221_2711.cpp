#include <iostream>

int main()
{
	int T; std::cin >> T;

	for (int now_case = 1; now_case <= T; now_case++)
	{
		int error_spot;
		std::string str;
		std::cin >> error_spot >> str;

		for (int i = 0; i < error_spot - 1; i++)
			std::cout << str[i];
		for (int i = error_spot ; i < str.length(); i++)
			std::cout << str[i];

		std::cout << "\n";
	}
	
	return (0);
}
