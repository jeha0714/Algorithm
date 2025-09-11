#include <iostream>
#include <vector>

using namespace std;

#define MAX2(x, y) (((x) > (y)) ? (x) : (y))

int main(void) {
	int 					N, K;
	vector<pair<int, int> >	info;
	int						w, v;
	vector<vector<int> >	dp;
	int						tmp;
	int						maxValue = 0;

	// 1. init input
	cin >> N >> K;
	info.resize(N);
	dp.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> w >> v;
		info[i] = make_pair(w, v);
		dp[i].resize(K + 1);
		for (int c = 0; c <= K; c++)
			dp[i][c] = 0;
	}

	// 2. calculate
	for (int i = 0; i < N; i++) {
		if (i == 0 && K - info[i].first >= 0) {
			dp[i][K - info[i].first] = info[i].second;
		}
		else if (i != 0) {
			// case a. current thing not include
			for (int c = 0; c <= K; c++) {
				dp[i][c] = dp[i - 1][c];
			}

			// case b. current thing include
			for (int c = 0; c <= K; c++) {
				if (c - info[i].first >= 0) { 
					tmp = c - info[i].first;
					dp[i][tmp] = MAX2(dp[i][tmp], dp[i - 1][c] + info[i].second);
				}
			}
		}
	}

	// 3. print result
	for (int r = 0; r < N; r++) {
		for (int c = 0; c <= K; c++) {
			if (maxValue < dp[r][c])
				maxValue = dp[r][c];
		}
	}
	cout << maxValue;

	return (0);
}
