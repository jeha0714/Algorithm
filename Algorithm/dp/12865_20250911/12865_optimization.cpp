#include <iostream>
#include <vector>

using namespace std;

#define MAX2(x, y) (((x) > (y)) ? (x) : (y))

int main(void) {
	int 					N, K;
	vector<pair<int, int> >	info;
	int						w, v;
	vector<int>				dp;
	int						tmp;
	int						maxValue = 0;

	// 1. init input
	cin >> N >> K;
	info.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> w >> v;
		info[i] = make_pair(w, v);
	}
	dp.resize(K + 1);
	for (int i = 0; i <= K; i++)
		dp[i] = 0;

	// 2. calculate
	for (int i = 0; i < N; i++) {
		if (i == 0 && K - info[i].first >= 0) {
			dp[K - info[i].first] = info[i].second;
		}
		else if (i != 0) {
			// case. current thing include
			for (int c = 0; c <= K; c++) {
				if (c - info[i].first >= 0) { 
					tmp = c - info[i].first;
					dp[tmp] = MAX2(dp[tmp], dp[c] + info[i].second);
				}
			}
		}
	}

	// 3. print result
	for (int c = 0; c <= K; c++) {
		if (maxValue < dp[c])
			maxValue = dp[c];
	}
	cout << maxValue;

	return (0);
}
