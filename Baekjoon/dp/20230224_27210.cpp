#include <iostream>

int main()
{
	// N입력
	int N; std::cin >> N;

	// 각 돌상이 바라보고 있는 방향을 배열에 저장
	int *n_arr = new int [N]();
	for (int i = 0; i < N; i++)
		std::cin >> n_arr[i];

	// 구간(왼쪽과 오른쪽이 연속하는 구간)의 누적 횟수를 저장하는 배열을 정의
	int *accumulate_arr = new int[N]();
	int index = 0;
	// 구간별 누적합을 구한다.
	for (int i = 0 ; i < N; i++)
	{
		// 맨 앞의 돌상은 예외로 초기화
		// 누적 횟수를 왼쪽(1)은 양수로 정의. 오른쪽(2)은 음수로 정의
		if (i == 0)
		{
			if (n_arr[i] == 1)
				accumulate_arr[index] = 1;
			else
				accumulate_arr[index] = -1;
		}
		else
		{
			// 구간이 연속된다면 값을 ++ or --해주고 
			// 구간이 변경된다면 index + 1에 새롭게 구간을 시작
			if (n_arr[i] == 1)
			{
				if (accumulate_arr[index] > 0)
					accumulate_arr[index]++;
				else
					accumulate_arr[++index] = 1;
			}
			else //n_arr[i] == 2
			{
				if (accumulate_arr[index] < 0)
					accumulate_arr[index]--;
				else
					accumulate_arr[++index] = -1;
			}
		}
	}

	//구간별 합을 구했으니 가장큰 양수 값과 가장큰 움수 값을 구하면 됨.
	int max = 0, min = 0;
	int left = 0, right = 0;
	for (int i = 0 ; i <= index ; i++)
	{
		// 구간이 변경되는 시점 즉,
		// left의 값 (양수)가 음수로 전환되거나
		// right의 값 (음수)가 양수로 전환된다면
		// 그 구간은 건너뛴다.

		// 구간이 양수(왼쪽)인 경우
		if (accumulate_arr[i] > 0)
		{
			if (right + accumulate_arr[i] < 0)
				right += accumulate_arr[i];
			else
				right = 0;
			
			left += accumulate_arr[i];
		}
		// 구간이 음수(오른쪽)인 경우
		else
		{
			if (left + accumulate_arr[i] > 0)
				left += accumulate_arr[i];
			else
				left = 0;
			
			right += accumulate_arr[i];
		}

		//매 경우에 max, min을새롭게 초기화 해준다.
		if (left > max)
			max = left;
		if (right < min)
			min = right;
	}

	// 동적할당한 배열 free
	delete[] n_arr;
	delete[] accumulate_arr;
	
	// min의 절대값과 max값을 비교하여 큰 값 출력
	if (max < min * -1)
		std::cout << min * -1;
	else
		std::cout << max;
}
