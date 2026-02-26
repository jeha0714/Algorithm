#include <iostream>

int main()
{
	int max = 0;
	int current = 0;

	for (int now = 1; now <= 4 ; now++)
	{
		int out, in; std::cin >> out >> in;

		current = current - out + in;
		if (current > max)
			max = current;
	}

	std::cout << max;

	return (0);
}
