#include <iostream>
#include <vector>

/* Merge function */
static void	merging(std::vector<int> &sequence, int start, int mid, int end)
{
	int ptr1, ptr2;
	int *temp;
	int i_temp;

	ptr1 = start;
	ptr2 = mid + 1;
	temp = new int[end - start + 1];
	i_temp = 0;
	while (ptr1 < mid + 1 && ptr2 < end + 1)
	{
		if (sequence[ptr1] < sequence[ptr2])
			temp[i_temp++] = sequence[ptr1++];
		else if (sequence[ptr1] > sequence[ptr2])
			temp[i_temp++] = sequence[ptr2++];
		else
		{
			temp[i_temp++] = sequence[ptr1++];
			temp[i_temp++] = sequence[ptr2++];
		}
	}
	while (ptr1 < mid + 1)
		temp[i_temp++] = sequence[ptr1++];
	while (ptr2 < end + 1)
		temp[i_temp++] = sequence[ptr2++];
	i_temp = 0;
	while (i_temp < end - start + 1)
	{
		sequence[start + i_temp] = temp[i_temp];
		i_temp++;
	}
	delete [] temp;
}

/* Merge function */
static void	merge_sort(std::vector<int> &sequence, int N, int start, int end)
{
	int mid;

	if (start < end)
	{
		mid = (start + end) / 2;

		merge_sort(sequence, N, start, mid);
		merge_sort(sequence, N, mid + 1, end);
		merging(sequence, start, mid, end);
	}
}

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N;
	int value;
	std::vector<int> sequence(0);
	int	*mode_sequence;
	int	average;
	int median;
	int	mode, flag;
	int	range;

	/* Set initial input */
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		std::cin >> value;
		sequence.push_back(value);
	}
	mode_sequence = new int[8001];
	for (int i = 0; i < 8001; i++)
		mode_sequence[i] = 0;

	/* Sort sequence */
	merge_sort(sequence, N, 0, sequence.size() - 1);

	/* Set result */

		// Set average
	average = 0;
	for (int i = 0; i < N; i++)
	{
		average += sequence[i];
		mode_sequence[sequence[i] + 4000]++;
	}
	if (average / N < 0)
	{
		if (((double)average / N) - (double)(average / N) > -0.5)
			average = average / N;
		else
			average = average / N - 1;
	}
	else
	{
		if (((double)average / N) - (double)(average / N) < 0.5)
			average = average / N;
		else
			average = average / N + 1;
	}
		// Set median
	median = sequence[N / 2];
		// Set mode 
	mode = sequence[0];
	flag = 0;
	for (int i = sequence[0] + 4001; i < 8001; i++)
	{
		if (mode_sequence[mode + 4000] == mode_sequence[i])
		{
			if (flag == 0)
			{
				mode = i - 4000;
				flag = 1;
			}
		}
		else if (mode_sequence[mode + 4000] < mode_sequence[i])
		{
			mode = i - 4000;
			flag = 0;
		}
	}
		// Set range
	range = sequence[N - 1] - sequence[0];

	/* Print result*/
	std::cout << average << "\n";
	std::cout << median << "\n";
	std::cout << mode << "\n";
	std::cout << range << "\n";

	return (0);
}
