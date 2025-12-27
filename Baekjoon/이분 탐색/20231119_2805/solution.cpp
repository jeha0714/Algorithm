#include <iostream>

using namespace std;

/* Calulate total height of wood with cut of current cutter */
long long	check_cut_wood_height(int N, int *woods_height, int cutter_height)
{
	long long	cut_wood_height;

	cut_wood_height = 0;
	for (int i = 0; i < N; i++)
	{
		if (woods_height[i] > cutter_height)
			cut_wood_height += (woods_height[i] - cutter_height);
	}

	return (cut_wood_height);
}

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int			N, M;
	int			*woods_height;
	long long	cut_wood_height;
	long long	start, end; // binary search start-point and end-point
	int			cutter_height;

	/* Set initial input */
	cin >> N >> M;
	woods_height = new int[N];
	start = 0; end = 0; // set edge-point to 0 and max-height of wood
	for (int i = 0; i < N; i++)
	{
		cin >> woods_height[i];
		if (end < woods_height[i])
			end = woods_height[i];
	}
	cutter_height = 0;

	/* Find max cutter_height */
	while (1)
	{
		// Calulate total height of wood with cut of current cutter
		cut_wood_height = check_cut_wood_height(N, woods_height, cutter_height);

			// When total wood height smaller than M
		if (cut_wood_height < M)
		{
			if (check_cut_wood_height(N, woods_height, cutter_height - 1) >= M)
			{
				cutter_height -= 1;
				break ;
			}
			end = cutter_height - 1;
		}
			// When total wood height bigger or smae with M
		else if (cut_wood_height >= M)
		{
			if (check_cut_wood_height(N, woods_height, cutter_height + 1) < M)
				break ;
			start = cutter_height + 1;
		}
		cutter_height = (start + end) / 2;
	}

	/* Print result */
	cout << cutter_height << "\n";

	/* Free memory */
	delete[] woods_height;

	return (0);
}
