#include <iostream>

void find_paper(int start_r, int start_c, int N, int **arr, int *white, int *blue)
{
	// 초기숫자의 값을 처음 시작 위치 숫자 값으로 초기화
	int initial_num = arr[start_r][start_c];

	// 처음 시작 위치부터 start_r + N 행 start_c + N행을 돌면서
	for (int current_r = start_r; current_r < start_r + N; current_r++)
	{
		for (int current_c = start_c; current_c < start_c + N; current_c++)
		{
			// 현재위치의 숫자값과 초기숫자 값과 비교
			// 일치하지 않다면 종이를 분할 해야 하므로 
			// 주어진 문제에 맞게 크기를 N /2로 나눔.
			if (initial_num != arr[current_r][current_c])
			{
				// 크기를 나누고 위치도 분할된 종이의 첫 지점에 맞게 값 설정
				find_paper(start_r, start_c, N / 2, arr, white, blue);
				find_paper(start_r + N / 2, start_c, N / 2, arr, white, blue);
				find_paper(start_r, start_c + N / 2, N / 2, arr, white, blue);
				find_paper(start_r + N / 2, start_c + N / 2, N / 2, arr, white, blue);

				// 분할해야 하는 경우이면 더 이상 반복문을 돌지 않고 종료
				return ;
			}
		}
	}
	
	// 초기 숫자값에 따른 색상별 종이 수 추가
	if (initial_num == 0)
		*white += 1;
	else
		*blue += 1;
}

int main()
{
	// 데이터를 받아와서 배열에 저장.
	int N; std::cin >> N;
	int **arr = new int *[N];
	for (int r = 0; r < N; r++)
	{
		arr[r] = new int [N];
		for (int c = 0; c < N; c++)
			std::cin >> arr[r][c];
	}

	// 정답이 저장될 변수
	int white_paper = 0, blue_paper = 0;

	// 재귀를 통한 분할정복 시작
	find_paper(0, 0, N, arr, &white_paper, &blue_paper);

	// 결과값 출력
	std::cout << white_paper << "\n" << blue_paper;

	// 메모리 반납
	for (int r = 0; r < N; r++)
		delete [] arr[r];
	delete [] arr;

	return (0);
}
