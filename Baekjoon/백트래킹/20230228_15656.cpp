#include <iostream>
#include <algorithm>

void func(int N, int M, int *n_arr, int *set_arr, int set_arr_ind)
{
	if (set_arr_ind == M)
	{
		for (int i = 0; i < M; i++)
			std::cout << n_arr[set_arr[i]] << " ";
		std::cout << "\n";
	}
	else
	{
		set_arr[set_arr_ind] = 0;
		while (set_arr[set_arr_ind] < N)
		{
			func(N, M, n_arr, set_arr, set_arr_ind + 1);
			set_arr[set_arr_ind]++;
		}
		set_arr[set_arr_ind] = 0;
	}
}

int main()
{
	int N, M; std::cin >> N >> M;
	int n_arr[N];
	for (int i = 0 ; i < N ; i++)
		std::cin >> n_arr[i];
	std::sort(n_arr, n_arr + N);

	int set_arr[M];
	func(N, M, n_arr, set_arr, 0);

	return (0);
}
