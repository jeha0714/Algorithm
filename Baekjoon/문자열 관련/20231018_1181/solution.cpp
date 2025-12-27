#include <iostream>

static void	merge_sort(char **words, int start, int end);
static int	ft_strlen(char *str);
static int	ft_strcmp(char **words, int main, int compare);

/* Function Merge sort */
static void	merge_sort(char **words, int start, int end)
{
	int	mid;
	char **temp;
	int	i_temp, i_start, i_end;

	mid = (start + end) / 2;
	if (start < end)
	{
		merge_sort(words, start, mid);
		merge_sort(words, mid + 1, end);
	}
	else
		return ;

	// Sorting
	temp = new char* [end - start + 1];
	i_temp = 0;
	i_start = start;
	i_end = mid + 1;

		// merge
	while (i_start <= mid && i_end <= end)
	{
		if (ft_strlen(words[i_start]) < ft_strlen(words[i_end]))
			temp[i_temp++] = words[i_start++];
		else if (ft_strlen(words[i_start]) > ft_strlen(words[i_end]))
			temp[i_temp++] = (words[i_end++]);
		else if (ft_strlen(words[i_start]) == ft_strlen(words[i_end]))
		{
			if (ft_strcmp(words, i_start, i_end) < 0)
				temp[i_temp++] = (words[i_start++]);
			else if (ft_strcmp(words, i_start, i_end) > 0)
				temp[i_temp++] = (words[i_end++]);
			else if (ft_strcmp(words, i_start, i_end) == 0)
			{
				temp[i_temp++] = (words[i_start]);
				temp[i_temp++] = (words[i_end]);
				i_start++;
				i_end++;
			}
		}
	} 
	while (i_start <= mid)
		temp[i_temp++] = (words[i_start++]);
	while (i_end <= end)
		temp[i_temp++] = (words[i_end++]);

	// Copy
	for (int i = 0; i < end - start + 1; i++)
		words[start + i] = (temp[i]);
	
	// Free memory
	delete[] temp;
}

/* Function Strlen */
static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
		return (i);
	}
	else
		return (0);
}

/* Function Compare sentence */
static int	ft_strcmp(char **words, int main, int compare)
{
	int	i;

	i = 0;
	while (1)
	{
		if (words[main][i] == words[compare][i])
			i++;
		else
			return (words[main][i] - words[compare][i]);
		if (words[main][i] == '\0' && words[compare][i] == '\0')
			break ;
	}
	return (0);
}

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int 	N;
	char	**words;
	
	/* Set initial input */
	std::cin >> N;
	words = new char* [N];
	for (int i = 0; i < N; i++)
	{
		words[i] = new char [52];
		std::cin >> words[i];
	}

	/* Sorting */
	merge_sort(words, 0, N - 1);

	/* Print sorted */
	std::cout << words[0] << "\n";
	for (int i = 1; i < N; i++)
	{
		if (ft_strcmp(words, i - 1, i) != 0)
			std::cout << words[i] << "\n";
	}
	
	/* Free memory */
	for (int i = 0; i < N; i++)
		delete[] words[i];
	delete[] words;

	return (0);
}
