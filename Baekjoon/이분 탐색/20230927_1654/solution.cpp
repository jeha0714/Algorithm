#include <iostream>
#include <vector>

static int how_many_make(std::vector<int> &len_cables, int len_cutting, int n_cable)
{
	int produced_cables;

	produced_cables = 0;
	for (int i = 0; i < n_cable; i++)
		produced_cables += (len_cables[i] / len_cutting);

	return (produced_cables);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int K, N;
	int value;
	long long top, bottom, mid;
	long long max_length_of_cable;
	int produced_cables;
	std::vector<int> len_cables(0);

	/* Set initial input */
	std::cin >> K >> N;
	std::cin >> value;
	len_cables.push_back(value);
	top = len_cables[0];
	for (int i = 1; i < K; i++)
	{
		std::cin >> value;
		len_cables.push_back(value);
		if (top < len_cables[i])
			top = len_cables[i];
	}
	if (top > N)
		bottom = top / N;
	else
		bottom = 1;

	/* Find cable's max length */
	while (bottom <= top)
	{
		mid = (top + bottom) / 2;
		produced_cables = how_many_make(len_cables, mid, K);
		if (produced_cables < N)
			top = mid - 1;
		else
			bottom = mid + 1;
	}
	max_length_of_cable = (top + bottom) / 2;
	
	/* Print max_len! */
	std::cout << max_length_of_cable << "\n";

	return (0);
}
