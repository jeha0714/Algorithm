#include <stdio.h>

int main(void)
{
	int size = 0; scanf("%d", &size); // 수열의 크기 size
	int array[size]; // 수열이 저장될 배열
	for (int index = 0; index < size; index++) { scanf("%d", &array[index]); }
    
    // 인덱스 순서대로 자신 인덱스까지 오면서 최대로 증가하는 부분 수열의 길이 값을 저장함.
	int front_Max[size];
	for (int main_Index = 0; main_Index < size; main_Index++)
	{
		if (main_Index == 0)
			front_Max[main_Index] = 1;

		else
		{
			front_Max[main_Index] = 1;
			for (int sub_Index = main_Index - 1; sub_Index >= 0; sub_Index--)
			{
				if (array[sub_Index] < array[main_Index] && front_Max[sub_Index] >= front_Max[main_Index])
				{
					front_Max[main_Index] = front_Max[sub_Index] + 1;
				}
			}

		}

	}

    // 인덱스 뒤에서 앞으로 자신 인덱스까지 오면서 최대로 증가하는 부분 수열의 길이 값을 저장함.
	int back_Max[size];
	for (int main_Index = size - 1; main_Index >= 0; main_Index--)
	{
		if (main_Index == size - 1)
			back_Max[main_Index] = 1;

		else
		{
			back_Max[main_Index] = 1;
			for (int sub_Index = main_Index + 1; sub_Index < size; sub_Index++)
			{
				if (array[sub_Index] < array[main_Index] && back_Max[sub_Index] >= back_Max[main_Index])
				{
					back_Max[main_Index] = back_Max[sub_Index] + 1;
				}
			}

		}

	}
    
	int result = 0; // 가장 긴 바이토닉 수열의 길이를 저장한 변수값

    // front_Max와 back_Max를 합친값이 가장 큰 값을 찾는다.
	for (int index = 0; index < size; index++)
	{
		if (result < front_Max[index] + back_Max[index])
			result = front_Max[index] + back_Max[index];
	}

    // 결과값을 출력하는데 자기 자신을 두번 포함시켰으므로 한 번은 뺀다.
	printf("%d", result - 1 );

	return 0;
}