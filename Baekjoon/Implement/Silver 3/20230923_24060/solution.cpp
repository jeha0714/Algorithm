#include <iostream>
#include <vector>

int N, K;
int current_k = 0;

static void merge(std::vector<int> &array, std::vector<int> &result, int start, int mid, int end)
{
	int i_first_set = start;
	int i_second_set = mid + 1;
	int	i_result = 0;

	// Sort two groups!
	while (i_first_set <= mid && i_second_set <= end)
	{
		if (array[i_first_set] < array[i_second_set])
			result[i_result++] = array[i_first_set++];
		else
			result[i_result++] = array[i_second_set++];

		current_k++;
		// check current_k with K
		if (current_k == K)
			std::cout << result[i_result - 1] << "\n";
	}

	// Sort remaining first group!
	while (i_first_set <= mid)
	{
		result[i_result++] = array[i_first_set++];
		current_k++;
		// check current_k with K
		if (current_k == K)
			std::cout << result[i_result - 1] << "\n";
	}

	// Sort remaining second group!
	while (i_second_set <= end)
	{
		result[i_result++] = array[i_second_set++];
		current_k++;
		// check current_k with K
		if (current_k == K)
			std::cout << result[i_result - 1] << "\n";
	}

	// Copy sorted result to origin array
	i_result = 0;
	for (int i = start; i <= end; i++, i_result++)
		array[i] = result[i_result];
}

static void my_merge_sort(std::vector<int> &array, std::vector<int> &result, int start, int end)
{
	int mid;

	if (start < end)
	{
		// Division array!
		mid = (start + end) / 2;
		my_merge_sort(array, result, start ,mid);
		my_merge_sort(array, result, mid + 1 ,end);

		// Merge!
		merge(array, result, start, mid, end);
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

	// Run Merge sort!
	std::vector<int> result(N);
	my_merge_sort(array, result, 0, array.size() - 1);

	// check Total_k with K
	if (current_k < K)
		std::cout << -1 << "\n";

	return (0);
}
