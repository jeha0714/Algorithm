#include <iostream>

long long calculate_ate_patty(int N, long long X, long long level_total_pattys[51], long long level_total_length[51] )
{
	if (N == 0)
	{
		if (X == 0)
			return (0);
		else
			return (1);
	}
	else if (X == 0 || X == 1)
		return (0);
	else if (X < level_total_length[N] - (level_total_length[N - 1] + 1))
	{
		return (calculate_ate_patty((N - 1), X - 1, level_total_pattys, level_total_length));
	}
	else if ( X == level_total_length[N] - (level_total_length[N - 1] + 1))
	{
		return (level_total_pattys[N - 1] + 1);
	}
	else //if ( X > level_total_length[N] - (level_total_length[N - 1] + 1))
	{
		return ((level_total_pattys[N - 1] + 1) + calculate_ate_patty((N - 1), (X - (level_total_length[N - 1] + 2)), level_total_pattys, level_total_length));
	}
}

int main()
{
	// N은 레벨-N버거, X는 버거 아래에서부터 X장 먹음.
	int N;
	long long X;
	std::cin >> N >> X;
	
	// 버거의 레벨별 총 패티 개수와 버거의 레벨별 총 크기
	long long *level_total_pattys = new long long[51];
	long long *level_total_length = new long long[51];
	level_total_pattys[0] = 1;
	level_total_length[0] = 1;

	// 레벨-N까지의 총 패티 개수를 계산하는 과정
	for (int now_level = 1; now_level <= N; now_level++ )
	{
		level_total_pattys[now_level] = 1 + 2 * level_total_pattys[now_level - 1];
		level_total_length[now_level] = 3 + 2 * level_total_length[now_level - 1];
	}

	// N이 최대로 주어진 경우로 인하여 자료형 long long
	long long ate_patty = 0; 

	// 총 먹은 패티수를 계산하는 과정
	ate_patty = calculate_ate_patty(N, X, level_total_pattys, level_total_length);

	delete[] level_total_pattys;
	std::cout << ate_patty;
}
