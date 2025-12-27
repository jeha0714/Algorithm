#include <iostream>

void backtracking(int N, int M, int loc, int *arr, int num)
{
	// 현재 인덱스(loc)가 M보다 크면 (출력해야 하는 수열의 위치를 넘어가면)
	// 배열에 저장된 수열을 출력 후 함수 종료
	if (loc > M)
	{
		for (int i = 1; i <= M; i++)
			std::cout << arr[i] << " ";
		std::cout << "\n";

		return ;
	}
	else
	{
		// 현재 인덱스의 수열 값을 num으로 초기화
		arr[loc] = num;

		// 현재 인덱스의 수열 값의 최대값까지 증가시키면서 함수 호출
		for (; arr[loc] <= N - M + loc; arr[loc]++)
		// 다음 인덱스의 수열 값이 현재 수열 값보다 1이상이도록 함수 호출
			backtracking(N, M, loc + 1, arr, arr[loc] + 1);
	}
}

int main()
{
	int N, M; std::cin >> N >> M;
	int arr[M + 1]; // M개의 수열을 저장할 배열 생성 인덱스 0은 사용 x

	backtracking(N, M, 1, arr, 1);

	return (0);
}
