#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int	N;
	int result;
	std::vector<int> array;

	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		int value;
		std::cin >> value;
		array.push_back(value);
	}

	result = 0;
	for (int i = 0; i < N; i++)
	{
		std::vector<int> copy(N - 1);
		if (i == 0)
			std::copy(array.begin() + 1, array.end(), copy.begin());
		else
		{
			std::copy(array.begin(), array.begin() + i, copy.begin());
			std::copy(array.begin() + i + 1, array.end() + 1, copy.begin() + i);
		}
		sort(copy.begin(), copy.end());

		int i_start = 0;
		int	i_end = copy.size() - 1;
		int start = copy[i_start];
		int end = copy[i_end];
		while (i_start < i_end)
		{
			if (start + end < array[i])
				start = copy[(++i_start)];
			else if (start + end > array[i])
				end = copy[(--i_end)];
			else if (start + end == array[i])
			{
				result++;
				break ;
			}
		}
	}

	std::cout << result << "\n";

	return (0);
}
