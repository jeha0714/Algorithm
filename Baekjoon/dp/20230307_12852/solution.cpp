#include <iostream>

void following(int current_num, int N, int **arr)
{
	// 현재 출력 해야하는 숫자가 N과 같다면
	// N 출력후 더이상 함수를 호출하지 않는다.
	if (current_num == N)
		std::cout << N << " ";
	// 현재 출력 해야하는 숫자가 N보다 작다면
	else
	{
		// 현재 출력 해야하는 숫자가 만들어지기 이전 숫자를 함수로 호출
		following(arr[current_num][1], N, arr);

		// 현재 숫자를 출력
		std::cout << current_num << " ";
	}

}


int main()
{
	// 정수 N입력
	int N; std::cin >> N;
	// N에서 1까지 만들어가는 과정 속 최소 횟수를 저장하는 배열 생성
	// [a][0]에는 숫자 a가 만들어질때까지의 최소 횟수를 저장
	// [b][1]에는 숫자 b가 만들어지기 이전의 숫자를 저장
	int **arr = new int *[N +1];
	for (int i = 0; i <= N; i++)
		arr[i] = new int [2]();

	for (int num = N - 1; num >= 1; num--)
	{
		// -1 해준 경우
		arr[num][0] = arr[num + 1][0] + 1;
		arr[num][1] = num + 1;

		// 2로 나누어준 경우
		if (num * 2 <= N)
		{
			int current_way = arr[num * 2][0] + 1;
			if (current_way < arr[num][0])
			{
				arr[num][0] = current_way;
				arr[num][1] = num * 2;
			}
		}

		// 3로 나누어준 경우
		if (num * 3 <= N)
		{
			int current_way = arr[num * 3][0] + 1;
			if (current_way < arr[num][0])
			{
				arr[num][0] = current_way;
				arr[num][1] = num * 3;
			}
		}

	}

	// 횟수의 최솟값을 출력
	std::cout << arr[1][0] << "\n";
	// 1로 만드는 방법을 순차적으로 출력
	following(1, N, arr);

	return (0);
}
