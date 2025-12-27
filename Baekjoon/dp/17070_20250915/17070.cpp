#include <iostream>
#include <vector>

using namespace std;

#define HORIZONTAL 0
#define VERTICAL 1
#define DIAGONAL 2

int main(void) {
	int N;
	int	tmp;

	// 1. init
	cin >> N;
	vector<vector<int> >	map(N + 1, vector<int>(N + 1, 0));
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cin >> tmp;
			map[r][c] = tmp;
		}
	}
	vector<vector<vector<int> > >	dp(N + 1, vector<vector<int> >(N + 1, vector<int>(3, 0)));
	dp[1][2][HORIZONTAL] = 1;

	// 2. calculate
	for (int r = 1; r <= N; r++) {
		for (int c = 3; c <= N; c++) {
			if (map[r][c] == 1) continue;

			// 고려해야할것 : 이동할부분이 맵의 끝인지 혹은 벽인지

			// case a. move horizontal
			dp[r][c][HORIZONTAL] = dp[r][c - 1][DIAGONAL] + dp[r][c - 1][HORIZONTAL];

			// case b. move vertical 
			dp[r][c][VERTICAL] = dp[r - 1][c][DIAGONAL] + dp[r - 1][c][VERTICAL];

			// case c. move diagonal
			if (map[r - 1][c] != 1 && map[r][c - 1] != 1)
				dp[r][c][DIAGONAL] = dp[r - 1][c - 1][DIAGONAL] + dp[r - 1][c - 1][HORIZONTAL]
									+ dp[r - 1][c - 1][VERTICAL];
		}
	}
		
	// 3. print result
	int result = dp[N][N][HORIZONTAL] + dp[N][N][VERTICAL] + dp[N][N][DIAGONAL];
	cout << result;

	return (0);
}
