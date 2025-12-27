#include <iostream>

/* Merge sort */
static void	merge_sort(int *arr, int start, int end)
{
	int mid = (start + end) / 2;
	int	*temp;
	int i_temp, i_front, i_back;

	// recursive 
	if (start < end)
	{
		merge_sort(arr, start, mid);
		merge_sort(arr, mid + 1, end);
	}
	else
	{
		return ;
	}

	// merge + sort
	temp = new int[end - start + 1];
	i_temp = 0;
	i_front = start;
	i_back = mid + 1;
	while (i_front <= mid && i_back <= end)
	{
		if (arr[i_front] < arr[i_back])
		{
			temp[i_temp] = arr[i_front];
			i_temp++;
			i_front++;
		}
		else if (arr[i_front] > arr[i_back])
		{
			temp[i_temp] = arr[i_back];
			i_temp++;
			i_back++;
		}
		else
		{
			temp[i_temp] = arr[i_front];
			i_temp++;
			i_front++;
			temp[i_temp] = arr[i_back];
			i_temp++;
			i_back++;
		}
	}
	while (i_front <= mid)
	{
		temp[i_temp] = arr[i_front];
		i_temp++;
		i_front++;
	}
	while (i_back <= end)
	{
		temp[i_temp] = arr[i_back];
		i_temp++;
		i_back++;
	}
	
	// Move to main arr
	for (int i = 0; i < end - start + 1; i++)
		arr[start + i] = temp[i];
	
	// Free memory
	delete[] temp;
}

/* Binary Search */
static int binary_search(int *arr, int start, int end, int num)
{
	int mid = (start + end) / 2;
	if (start <= end)
	{
		if (arr[mid] < num)
			return (binary_search(arr, mid + 1, end, num));
		else if (arr[mid] == num)
			return (1);
		else
			return (binary_search(arr, start, mid - 1, num));
	}
	return (0);
}

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N, M;
	int	*N_sequence;
	int	*M_sequence;

	/* Set initial input */
	std::cin >> N;
	N_sequence = new int[N];
	for (int i = 0; i < N; i++)
		std::cin >> N_sequence[i];

	std::cin >> M;
	M_sequence = new int[M];
	for (int i = 0; i < M; i++)
		std::cin >> M_sequence[i];

	/* sorting */
		// Merge sort
	merge_sort(N_sequence, 0, N - 1);


	/* Find and Print number */
	for (int i_m = 0; i_m < M; i_m++)
	{
		// Search Binary search	
		if (binary_search(N_sequence, 0, N - 1, M_sequence[i_m]) == 1)
			std::cout << 1 << "\n";
		else
			std::cout << 0 << "\n";
	}

	/* Free memory */
	delete[] N_sequence;
	delete[] M_sequence;

	return (0);
}
