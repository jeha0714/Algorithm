#include <iostream>

int main()
{
	int N; std::cin >> N;
	int *arr = new int [N + 1]();

	for (int i = N - 1; i >= 1; i--)
	{
		arr[i] = arr[i + 1] + 1;

		if (i * 2 <= N)
		{
			int current_value = arr[i * 2] + 1;
			if (current_value < arr[i])
				arr[i] = current_value;
		}
		if (i * 3 <= N)
		{
			int current_value = arr[i * 3] + 1;
			if (current_value < arr[i])
				arr[i] = current_value;
		}
	}

	std::cout << arr[1];


	return (0);
}
