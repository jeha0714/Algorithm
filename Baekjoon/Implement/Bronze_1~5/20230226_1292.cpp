#include <iostream>

int main()
{
	int A, B; std::cin >> A >> B;
	int current_loc = 1, result = 0;

	for (int start = 1; ; start++)
	{
		for (int n = 1; n <= start; n++, current_loc++)
		{
			if (A <= current_loc && current_loc <= B)
				result += start;
		}
		if (current_loc > B)
			break;
	}

	std::cout << result;
	return(0);
}
