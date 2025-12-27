#include <iostream>

using namespace std;

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int	N;
	int	*stairs_score; // 각 계단의 점수
	int	**max_score; // N개의 행과 2개의 열이
	// 0열에는 연속으로 밟은 계단 수가 하나
	// 1열에는 연속으로 밟은 계단 수가 두개

	/* Set initial input */
	cin >> N;
	stairs_score = new int[N];
	max_score = new int*[N];
	for (int i = 0; i < N; i ++)
	{
		cin >> stairs_score[i];
		max_score[i] = new int[2];
	}

	/* Set max score in each stair */
	max_score[0][0] = stairs_score[0];
	max_score[0][1] = stairs_score[0];
	if (N > 1)
	{
		max_score[1][0] = stairs_score[1];
		max_score[1][1] = max_score[0][0] + stairs_score[1];
	}
	for (int i = 2; i < N; i++)
	{
		if (max_score[i - 2][0] > max_score[i - 2][1])
			max_score[i][0] = max_score[i - 2][0] + stairs_score[i];
		else
			max_score[i][0] = max_score[i - 2][1] + stairs_score[i];

		max_score[i][1] = max_score[i - 1][0] + stairs_score[i];
	}

	/* Print result */
	if (max_score[N - 1][0] > max_score[N - 1][1])
		cout << max_score[N - 1][0] << "\n";
	else
		cout << max_score[N - 1][1] << "\n";

	/* Free memory */
	for (int i = 0; i < N; i++)
		delete[] max_score[i];
	delete[] max_score;
	delete[] stairs_score;

	return (0);
}
