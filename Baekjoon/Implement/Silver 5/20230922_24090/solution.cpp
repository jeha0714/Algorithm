#include <iostream>
#include <vector>

int N, K;
int current_k = 0;

static void partitioning(std::vector<int> &array, int start, int end, int *i_pivot)
{
	int temp;
	int i;
	
	i = start - 1;
	for (int j = start; j < end; j++)
	{
		if (array[j] <= array[*i_pivot])
		{
			// swap
			temp = array[j];
			array[j] = array[++i];
			array[i] = temp;
			current_k++;

			// check current_k with K
			if (current_k == K)
				std::cout << array[i] << " " << array[j] << "\n";
		}
	}
	if (i + 1 != *i_pivot)
	{
		// swap
		temp = array[i + 1];
		array[i + 1] = array[*i_pivot];
		array[*i_pivot] = temp;
		current_k++;

		// check current_k with K
		if (current_k == K)
			std::cout << array[i + 1] << " " << array[*i_pivot] << "\n";
	}
	*i_pivot = i + 1;
}

static void	my_quick_sort(std::vector<int> &array, int start, int end, int i_pivot)
{
	if (start < i_pivot)
	{
		partitioning(array, start, end, &i_pivot);
		my_quick_sort(array, start, i_pivot - 1, i_pivot - 1);
		my_quick_sort(array, i_pivot + 1, end, end);
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int value;
	std::vector<int> array(0);

	// Insert Data
	std::cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		std::cin >> value;
		array.push_back(value);
	}

	// Run Quick sort!
	my_quick_sort(array, 0, array.size() - 1, N - 1);

	// check Total_k with K
	if (current_k < K)
		std::cout << -1 << "\n";

	return (0);
}
