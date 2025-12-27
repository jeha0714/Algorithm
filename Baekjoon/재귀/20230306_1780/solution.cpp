#include <iostream>

void find_num_paper(int start_r, int start_c, int size, int **paper, int *num_paper)
{
	// 시작지점 위치의 숫자를 저장
	int initial_paper_num = paper[start_r][start_c];

	// size가 1인 경우 시작지점 위치 외의 비교할 숫자가 없으므로 
	// 해당되는 종이의 개수를 +1 해주고 종료
	if (size == 1)
		num_paper[initial_paper_num + 1] += 1;
	else
	{
		// 시작지점부터 가로세로 + size구역까지 paper에 저장된 값을 비교
		for (int current_r = start_r; current_r < start_r + size; current_r++)
		{
			for (int current_c = start_c; current_c < start_c + size; current_c++)
			{
				// 시작지점 위치의 값과 다르다면 종이를 쪼개야 함
				if (initial_paper_num != paper[current_r][current_c])
				{
					// 문제에서 언급한 것처럼 종이를 9개로 쪼개어 
					// 시작지점을 변경하여 함수를 재호출
					for (int plus_r = 0; plus_r < size; plus_r += size / 3)
						for (int plus_c = 0; plus_c < size; plus_c += size / 3)
							find_num_paper(start_r + plus_r, start_c + plus_c, size / 3, paper, num_paper);

					// 함수 호출 후 해당 size의 경우의 함수는 종료
					return ;
				}
			}
		}

		// 현재 size의 모든 값이 시작지점 위치의 값과 동일하다면
		// 시작지점 위치의 값에 해당되는 종이의 개수 +1
		num_paper[initial_paper_num + 1] += 1;
	}
}

int main()
{
	// 종이의 크기를 입력받는다.
	int N; std::cin >> N;
	// 크기에 해당되는 2차원 배열을 생성 후 값을 입력받는다.
	int **paper = new int *[N];
	for (int r = 0; r < N; r++)
	{
		paper[r] = new int [N];
		for (int c = 0; c < N; c++)
			std::cin >> paper[r][c];
	}

	// index0에는 -1로 채워진 종이 index1에는 0으로 채워진 종이 index2에는 1로 채워진 종이
	int num_paper[3] = {0};

	// 재귀를 통한 각 종이별 개수 파악
	find_num_paper(0, 0, N, paper, num_paper);

	// 각 종이별 개수를 출력
	for (int i = 0; i < 3; i++)
		std::cout << num_paper[i] << "\n";

	return (0);
}
