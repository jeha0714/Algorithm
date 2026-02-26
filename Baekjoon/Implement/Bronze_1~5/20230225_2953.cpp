#include <iostream>

int main()
{
	int arr[5][4] = {0};

	for (int r = 0; r < 5; r++)
	{
		for (int c = 0; c < 4 ; c++)
			std::cin >> arr[r][c];
	}

	int n_th = 1;
	int sum_all = 0;
	for (int n_th_ = 0; n_th_ < 5 ; n_th_++)
	{
		int now_person_score = 0;
		for (int each_score = 0; each_score < 4; each_score++)
			now_person_score += arr[n_th_][each_score];

		if (sum_all < now_person_score)
		{
			sum_all = now_person_score;
			n_th = n_th_ + 1;
		}
	}

	std::cout << n_th << "\n" << sum_all;

	return (0);
}
