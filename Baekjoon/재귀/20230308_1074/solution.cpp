#include <iostream>

// main의 exponent승 즉, 지수승을 구하는 함수
int power(int main, int exponent)
{
	if (exponent == 0)
		return 1;
	// 재귀를 통하여 반환값을 구한다.
	else
		return (main * power(main, exponent - 1));
}

int find_result(int flag_r, int flag_c, int r, int c, int size)
{
	// size == 2 즉, z가 만들어지는 제일 작은 size의 경우 
	if (size == 2)
	{
		// 4칸의 위치를 고려하여 flag들을 기준으로 값을 반환한다.
		return ((r - flag_r) * 2 + (c - flag_c));
	}
	else
	{
		// z영역을 1~4로 생각한다하면
		// size / 2의 크기를 기준으로 영역을 나눌 수 있다.

		// +flag값을 해주는 이유는 r과 c의 위치와 영역을 상대적으로 표시하기 위함
		int half_r = size / 2 + flag_r;
		int half_c = size / 2 + flag_c;

		// 4개의 영역으로 구분지어 해당되는 영역값은 이전에 지나쳐온 값들을 
		// 즉시 더해주고 함수를 다시 호출한다.
		if (r < half_r && c < half_c)
			return (find_result(flag_r, flag_c, r, c, size / 2));
		else if (r < half_r && c >= half_c)
			return (power(size / 2, 2) * 1 + find_result(flag_r, half_c, r, c, size / 2));
		else if (r >= half_r && c < half_c)
			return (power(size / 2, 2) * 2 + find_result(half_r, flag_c, r, c, size / 2));
		else // if (r > half_r && c > half_c)
			return (power(size / 2, 2) * 3 + find_result(half_r, half_c, r, c, size / 2));
	}
}

int main()
{
	// 입력으로 주어지는 3가지의 값을 받는다.
	int N, r, c; std::cin >> N >> r >> c;

	// 결과값을 출력한다.
	std::cout << find_result(0, 0, r, c, power(2, N));

	return (0);
}
