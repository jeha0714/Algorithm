#include <iostream>
#include <vector>

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N, M, B;
	int value;
	int min_h, max_h;
	int time, height;
	int temp_time, available_block;
	std::vector<int> array(0);

	// Insert and Set initial data
	std::cin >> N >> M >> B;
	std::cin >> value;
	array.push_back(value);
	min_h = array[0];
	max_h = array[0];
	for (int i = 1; i < N * M; i++)
	{
		std::cin >> value;
		array.push_back(value);
		if (min_h > array[i])
			min_h = array[i];
		if (max_h < array[i])
			max_h = array[i];
	}
	time = 2 * N * M * max_h;
	height = 0;

	// Find optimal situation
	for (int set_h = min_h; set_h <= max_h; set_h++)
	{
		// Calculate time when set_height(set_h)
		temp_time = 0;
		available_block = B;
		for (int i = 0; i < N * M; i++)
		{
			if (set_h < array[i])
			{
				temp_time += (2 * (array[i] - set_h));
				available_block += (array[i] - set_h);
			}
			else if (set_h > array[i])
			{
				temp_time += (set_h - array[i]);
				available_block -= (set_h - array[i]);
			}
		}

		// Check remained of blocks and time
		if (available_block >= 0 && temp_time <= time)
		{
			time = temp_time;
			height = set_h;
		}
	}

	// Print Result
	std::cout << time << " " << height << "\n";

	return (0);
}
