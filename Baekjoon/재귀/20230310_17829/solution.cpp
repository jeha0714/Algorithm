#include <iostream>

int find_second_max(int start_r, int start_c, int **arr);
void make_mini_arr(int size, int **arr);

void make_mini_arr(int size, int **arr)
{
	// size가 2 * 2일때에는 4개의 값중 2번째로 큰 수 찾아서 바로 출력
	if (size == 2)
	{
		int result = find_second_max(0, 0, arr);
		std::cout << result;
	}
	else
	{
		// size / 2 크기의 배열을 새로 생성
		// 주어진 조건에 맞게 2번째로 작은 값을 대입한다.
		int **new_arr = new int *[size / 2];
		for (int r = 0; r < size / 2; r++)
			{
				new_arr[r] = new int[size / 2];

				for (int c = 0; c < size/ 2; c++)
					new_arr[r][c] = find_second_max(r * 2, c * 2, arr);
			}

		// size를 줄여나가며 함수를 호출한다.
		make_mini_arr(size / 2, new_arr);
	}

	// 현재 size 메모리 반환
	for (int r = 0; r < size; r++)
		delete[] arr[r];
	delete[] arr;

}

int find_second_max(int start_r, int start_c, int **arr)
{
	// 가장 큰수와 2번째로 큰 수 변수 생성
	int most_max = arr[start_r][start_c];
	int second_max = arr[start_r][start_c + 1];

	// 주어진 범위 내에서 값을 찾는다
	for (int current_r = start_r; current_r <= start_r + 1; current_r++)
	{
		for (int current_c = start_c; current_c <= start_c + 1; current_c++)
		{
			if (current_r == start_r && current_c == start_c)
				continue; 

			if (most_max <= arr[current_r][current_c])
			{
				second_max = most_max;
				most_max = arr[current_r][current_c];
			}
			else // most_max > arr[current_r][current_c]
			{
				if (arr[current_r][current_c] > second_max)
					second_max = arr[current_r][current_c];
			}
		}
	}

	return (second_max);
}

int main()
{
	// N과 배열 생성 후 배열 내부 값 입력
	int N; std::cin >> N;
	int **arr = new int *[N];
	for (int r = 0; r < N; r++)
	{
		arr[r] = new int[N];

		for (int c = 0; c < N; c++)
			std::cin >> arr[r][c];
	}

	// 배열의 크기를 문제의 조건에 맞게 줄여나가며 최종 답안 출력
	make_mini_arr(N, arr);

	return (0);
}
