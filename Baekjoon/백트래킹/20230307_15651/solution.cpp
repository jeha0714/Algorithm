#include <iostream>

void back_tracking(int N, int M, int current, int *sequence)
{
	// current 즉, 배열에 접근할 인덱스 값이 M인 경우 
	// 배열에 저장된 0~M-1의 모든 값들을 출력
	if (current == M)
	{
		for (int i = 0; i < M; i++)
			std::cout << sequence[i] << " ";
		std::cout << "\n";
	}
	else
	{
		// 현재 인덱스 위치 값을 1로 초기화.
		sequence[current] = 1;

		// 현재 인덱스 위치 값을 1씩 증가시키면서 
		// 다음 인덱스를 정하기 위해 함수 재호출
		for (; sequence[current] <= N; sequence[current]++)
			back_tracking(N, M, current + 1, sequence);
	}
}

int main()
{
	// 자연수 N과 M이 주어짐
	int N, M; std::cin >> N >> M;
	// M개의 수열이 저장될 배열 sequence정의
	int *sequence = new int [M]();

	// 재귀 함수를 통한 결과값 출력 시작.
	back_tracking(N, M, 0, sequence);

	return (0);
}
