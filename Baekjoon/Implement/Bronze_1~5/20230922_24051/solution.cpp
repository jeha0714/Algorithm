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
	for (int i = 1; i < N; i++)
	{
		// check right ascending sequence
		if (!(array[i - 1] < array[i]))
		{
			// find proper index with array[i]
			int i_proper = 0;
			if (!(array[i] < array[0]))
			{
				i_proper = 1;
				while (!(array[i_proper - 1] < array[i] && array[i] < array[i_proper]))
					i_proper++;
			}

			// move numbers and insert array[i] into proper index
			temp = array[i];
			for (int move = i; move >= i_proper; move--)
			{
				if (move == i_proper)
					array[move] = temp;
				else
					array[move] = array[move - 1];
				current_k++;

				// check current_k with K
				if (current_k == K)
					std::cout << array[move] << "\n";
			}
		}
	}
	// check Total_k with K
	if (current_k < K)
		std::cout << -1 << "\n";

	return (0);
}
