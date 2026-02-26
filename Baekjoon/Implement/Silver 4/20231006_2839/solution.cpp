#include <iostream>

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N;
	int	num_paperbag;
	int temp;

	// Insert and Set initial data
	std::cin >> N;

	num_paperbag = -1;
	for (int i = 0; i <= N / 5; i++)
	{
		if ((N - 5 * i) % 3 == 0)
		{
			temp = 0;
			temp = i + (N - 5 * i) / 3;
			if (num_paperbag == -1)
				num_paperbag = temp;
			else if (num_paperbag > temp)
				num_paperbag = temp;
		}
	}

	std::cout << num_paperbag << "\n";

	return (0);
}
