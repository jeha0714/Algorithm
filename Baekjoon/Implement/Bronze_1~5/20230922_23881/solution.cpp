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
	int i_current_max, current_k;
	int temp;
	std::vector<int> array(0);

	// Insert Data
	std::cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		std::cin >> value;
		array.push_back(value);
	}

	current_k = 0;
	for (int nth_try = 1; nth_try < N; nth_try++)
	{
		i_current_max = 0;
		// Find largest number in unsorted sequence
		for (int i_compare = 0; i_compare <= N - nth_try; i_compare++)
		{
			if (array[i_current_max] < array[i_compare])
				i_current_max = i_compare;
		}
		// Swap if the largest number is not set to the last index
		if (i_current_max != N - nth_try)
		{
			temp = array[N - nth_try];
			array[N - nth_try] = array[i_current_max];
			array[i_current_max] = temp;
			current_k++;
		}
		// check current_k with K
		if (current_k == K)
			std::cout << temp << " " << array[N - nth_try] << "\n";
	}
	// check Total_k with K
	if (current_k < K)
		std::cout << -1 << "\n";

	return (0);
}
