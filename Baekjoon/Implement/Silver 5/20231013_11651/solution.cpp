#include <iostream>

/* Merge sort*/
static void	merge_sort(int **coordinate, int start, int end)
{
	int mid;

	// Recursive
	mid = (start + end) / 2;
	if (start < end)
	{
		merge_sort(coordinate, start, mid);
		merge_sort(coordinate, mid + 1, end);
	}
	else
		return ;

	// Make temp array
	int	**temp;
	temp = new int*[end - start + 1];
	for (int i = 0; i < end - start + 1; i++)
		temp[i] = new int[2];

	/* Sorting!! */
	int i_temp, i_arr1, i_arr2;
	i_temp = 0;
	i_arr1 = start;
	i_arr2 = mid + 1;

		// Compare and Push in temp;
	while (i_arr1 <= mid && i_arr2 <= end)
	{
		// Compare y coordinate
		if (coordinate[i_arr1][1] < coordinate[i_arr2][1])
		{
			temp[i_temp][0] = coordinate[i_arr1][0];
			temp[i_temp][1] = coordinate[i_arr1][1];
			i_arr1++;
		}
		else if (coordinate[i_arr1][1] > coordinate[i_arr2][1])
		{
			temp[i_temp][0] = coordinate[i_arr2][0];
			temp[i_temp][1] = coordinate[i_arr2][1];
			i_arr2++;
		}
		else // if y coordniate same!
		{
			// Compare x coordinate
			if (coordinate[i_arr1][0] < coordinate[i_arr2][0])
			{
				temp[i_temp][0] = coordinate[i_arr1][0];
				temp[i_temp][1] = coordinate[i_arr1][1];
				i_arr1++;
			}
			else if (coordinate[i_arr1][0] > coordinate[i_arr2][0])
			{
				temp[i_temp][0] = coordinate[i_arr2][0];
				temp[i_temp][1] = coordinate[i_arr2][1];
				i_arr2++;
			}
		}
		i_temp++;
	}

		// Copy remains to temp
	while (i_arr1 <= mid)
	{
		temp[i_temp][0] = coordinate[i_arr1][0];
		temp[i_temp][1] = coordinate[i_arr1][1];
		i_temp++;
		i_arr1++;
	}
	while (i_arr2 <= end)
	{
		temp[i_temp][0] = coordinate[i_arr2][0];
		temp[i_temp][1] = coordinate[i_arr2][1];
		i_temp++;
		i_arr2++;
	}

		// Copy temp to main arr
	i_temp = 0;
	for (int i = start; i <= end; i++, i_temp++)
	{
		coordinate[i][0] = temp[i_temp][0];
		coordinate[i][1] = temp[i_temp][1];
	}

	// Delete memory
	for (int i = 0; i < end - start + 1; i++)
		delete[] temp[i];
	delete[] temp;

}

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N;
	int	**coordinate;
	
	/* Set initial input */
	std::cin >> N;
	coordinate = new int*[N];
	for (int i = 0; i < N; i++)
	{
		coordinate[i] = new int[2];
		std::cin >> coordinate[i][0] >> coordinate[i][1];
	}

	/* Sorting */
	merge_sort(coordinate, 0, N - 1);
	
	/* Print sorted */
	for (int i = 0; i < N; i++)
		std::cout << coordinate[i][0] << " " << coordinate[i][1] << "\n";

	/* Free memory */
	for (int i = 0; i < N; i++)
		delete[] coordinate[i];
	delete[] coordinate;

	return (0);
}
