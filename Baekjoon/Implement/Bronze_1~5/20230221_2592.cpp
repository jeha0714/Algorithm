#include <iostream>

int main()
{
	int average = 0;
	int *arr = new int[100]();

	for (int now = 1; now <= 10; now++)
	{
		int n; std::cin >> n;
		average += n;

		arr[n / 10]++;
	}
	average /= 10;

	std::cout << average << "\n";

	int max_emerge = 0;
	for (int i = 0; i < 100; i++)
		if (max_emerge < arr[i])
			max_emerge = i;
	std::cout << max_emerge * 10;

	delete[] arr;
	return (0);
}
