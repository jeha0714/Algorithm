#include <iostream>
#include <algorithm>

int check(int L, char *current_pd)
{
	// 최소 하나의 모음, 최소 두개의 자음 구성인지 판단
	int vowel = 0, consonant = 0;
	for (int i = 0; i < L; i++)
	{
		if (current_pd[i] == 'a' || current_pd[i] == 'e' || current_pd[i] == 'i' || current_pd[i] == 'o' || current_pd[i] == 'u')
			vowel++;
		else
			consonant++;
	}
	if (vowel < 1 || consonant < 2)
		return (0);

	return (1);
}

void make_password(int C, char *arr_char, int pd_i, int L, char *current_pd, int min_pd_i)
{
	// 암호를 저장하는 배열의 인덱스를 나타내는 값이 L과 같다면
	// 암호가 가득 찼으므로 조건을 만족시킨다면 출력
	if (pd_i == L)
	{
		if (check(L, current_pd))
		{
			for (int i = 0; i < L; i++)
				std::cout << current_pd[i];
			std::cout << "\n";
		}
	}
	// 암호를 저장하는 배열이 가득 차지 않았다면
	// 재귀를 통해 암호 배열을 채워줌
	else
	{
		// min_pd_i를 통해 암호 값들 간의 오름차순과 중복이 되지 않도록 해준다.
		for (int i = min_pd_i; i < C; i++)
		{
			current_pd[pd_i] = arr_char[i];
			make_password(C, arr_char, pd_i + 1, L, current_pd, i + 1);
		}
	}
}

int main()
{
	// L, C, 사용되는 알파벳들을 입력받는다.
	int L, C; std::cin >> L >> C;
	char *arr_char = new char [C];
	for (int i = 0; i < C; i++)
		std::cin >> arr_char[i];

	// 알파벳들을 오름차순 정리한다.
	std::sort(arr_char, arr_char + C);

	// 암호가 저장될 배열을 생성
	char *current_pd = new char[L];

	// 재귀를 통한 암호 생성
	make_password(C, arr_char, 0, L, current_pd, 0);

	return (0);
}
