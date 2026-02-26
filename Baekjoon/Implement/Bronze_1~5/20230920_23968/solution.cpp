#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N, K;
	int value;
	int num_swap;
	std::vector<int> array(0);

	std::cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		std::cin >> value;
		array.push_back(value);
	}

	num_swap = 0;
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				num_swap++;

				int temp;
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				if (num_swap == K)
				{
					std::cout << array[j] << " " << array[j + 1] << "\n";
					return (0);
				}
			}
		}
	}
	if (num_swap < K)
		std::cout << -1 << "\n";

	return (0);
}
