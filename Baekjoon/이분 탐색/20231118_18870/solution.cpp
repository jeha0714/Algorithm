#include <iostream>
#include <vector> // vector 
#include <algorithm> // sort

using namespace std;

/* Binary search */
int	my_binary_search(int start, int end, vector<int> *arr, int target)
{
	int	mid = (start + end) / 2;

	if ((*arr)[mid] < target)
		return (my_binary_search(mid + 1, end, arr, target));
	else if ((*arr)[mid] > target)
		return (my_binary_search(start, mid - 1, arr, target));
	else 
		return (mid);
}

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);
	
	int	N;
	int	*arr_X, *sort_X;
	vector<int>	sorted_set;
	int	location;

	/* Set initial input */
	cin >> N;
	arr_X = new int[N];
	sort_X = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr_X[i];
		sort_X[i] = arr_X[i];
	}
	sorted_set.reserve(N);

	/* Sort sort_X */
	sort(sort_X, sort_X + N);

	/* Delete duplication value */
	sorted_set.push_back(sort_X[0]);
	for (int i = 1; i < N; i++)
	{
		if (sort_X[i] != sorted_set[sorted_set.size() - 1])
			sorted_set.push_back(sort_X[i]);
	}

	///* Match arr_X[a] with sort_X[b] */
	for (int i = 0; i < N; i++)
	{
		location = my_binary_search(0, sorted_set.size() - 1, &sorted_set, arr_X[i]);
		cout << location << " ";
	}

	/* Free memory */
	delete[] arr_X;
	delete[] sort_X;

	return (0);
}
