#include <iostream>

void backtracking_(int N, int M, int loc, int *arr)
{
	// 현재 loc번쩨가 출력해야하는 M번째보다 크다면
	// 이전까지 저장된 숫자들을 출력이후 함수 종료.
	if (loc > M)
	{
		for (int i = 1; i <= M; i++)
			std::cout << arr[i] << " ";
		std::cout << "\n";

		return ;
	}
	else
	{
		// loc번째 숫자가 N과 같을때 까지만 반복
		for (arr[loc] = 1; arr[loc] <= N; arr[loc]++)
		{
			// 수열들의 숫자가 저장된 배열에 중복된 수가 있는지 검사
			int is_duplication = 0;
			for (int current = 1; current < loc; current++)
				if (arr[current] == arr[loc])
					is_duplication = 1;

			// 중복된 부분이 존재한다면 다음 경우의 수를 고려
			if (is_duplication == 1)
				continue;

			// 다음 loc + 1번째 숫자를 고려하기 위해 함수 호출
			backtracking_(N, M, loc + 1, arr);
		}
	}
}

int main()
{
	int N, M; std::cin >> N >> M;
	// n번째 숫자를 저장할 크기가 M + 1인 배열 (인덱스0은 사용하지 않는다)
	int arr[M + 1];

	backtracking_(N, M, 1, arr);

	return (0);
}
