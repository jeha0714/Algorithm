#include <iostream>

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N;
	int	**info;
	int	*num_bigger_than_me;
	
	/* Set initial input */
	std::cin >> N;
	info = new int*[N];
	for (int i = 0; i < N; i++)
	{
		info[i] = new int[2];
		std::cin >> info[i][0] >> info[i][1];
	}
	num_bigger_than_me = new int[N]();

	/* Compare eachother */
	for (int main = 0; main < N; main++)
	{
		num_bigger_than_me[main] = 0;
		for (int compare = 0; compare < N; compare++)
		{
			if (main != compare && info[main][0] < info[compare][0] && info[main][1] < info[compare][1])
				num_bigger_than_me[main]++;
		}
	}

	/* Check rank */
	for (int i = 0; i < N; i ++)
		std::cout << num_bigger_than_me[i] + 1 << " ";

	/* Free memory */
	for (int i = 0; i < N; i++)
		delete[] info[i];
	delete[] info;
	delete[] num_bigger_than_me;

	return (0);
}
