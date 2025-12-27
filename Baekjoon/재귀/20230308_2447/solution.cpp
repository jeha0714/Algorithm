#include <iostream>

void make_pattern(int start_r, int start_c, int size, char **arr_pattern)
{
	// size == 3일때는 패턴의 가장 작은 경우이므로 
	// 주어진 좌표에 맞게 *을 새겨준다
	if (size == 3)
	{
		for (int current_r = start_r; current_r < start_r + 3; current_r++)
		{
			for (int current_c = start_c; current_c < start_c + 3; current_c++)
			{
				if (current_r == start_r + 1 && current_c == start_c + 1)
					continue;
				arr_pattern[current_r][current_c] = '*';
			}
		}
	}
	// size > 3일때는 패턴을 쪼개어 별을 새겨야한다.
	else
	{
		for (int current_r = start_r; current_r < start_r + size; current_r += size / 3)
		{
			for (int current_c = start_c; current_c < start_c + size; current_c += size / 3)
			{
				// 크게 9개의 영역으로 생각하고
				// 중간의 영역은 건너뛰고 각 영역마다 패턴을 추가할 수 있도록 한다.
				if (current_r == start_r + size / 3 && current_c == start_c + size / 3)
					continue;
				make_pattern(current_r, current_c, size / 3, arr_pattern);
			}
		}
	}
}


int main()
{
	// N을 입력 받는다.
	int N; std::cin >> N;
	// N*N 배열을 생성한 후 스페이스바로 채운다.
	char **arr_pattern = new char *[N];
	for (int r = 0; r < N; r++)
	{
		arr_pattern[r] = new char[N];

		for (int c = 0; c < N; c++)
			arr_pattern[r][c] = ' ';
	}

	// 함수를 통하여 배열에 *을 새겨준다.
	make_pattern(0, 0, N, arr_pattern);
	
	// 배열에 담긴 문자를 행열 순서로 출력해준다.
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
			std::cout << arr_pattern[r][c];
		std::cout << "\n";
	}

	return (0);
}
