#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MIN2(x, y) ((x) < (y) ? (x) : (y));

int					N, K;
vector<int>			dp(200001, -1);

struct	myComparison {
	bool operator() (const int &a, const int &b) {
		return (dp[a] > dp[b]);
	}
};

priority_queue<int, vector<int>, myComparison >	pq;

int main(void) {
	int	tmp;

	// 1. init input
	cin >> N >> K;
	dp[N] = 0;
	pq.push(N);

	// 2. calculate
	while(!pq.empty()) {
		tmp = pq.top();
		pq.pop();

		if (dp[K] != -1 && dp[K] <= dp[tmp])
			break ;

		if (tmp - 1 >= 0) {
			if (dp[tmp - 1] == -1) {
				dp[tmp - 1] = dp[tmp] + 1;
				pq.push(tmp - 1);
			}
			else if (dp[tmp - 1] > dp[tmp] + 1) {
				dp[tmp - 1] = dp[tmp] + 1;
				pq.push(tmp - 1);
			}
		}
		if (tmp + 1 <= 100000) {
			if (dp[tmp + 1] == -1) {
				dp[tmp + 1] = dp[tmp] + 1;
				pq.push(tmp + 1);
			}
			else if (dp[tmp + 1] > dp[tmp] + 1) {
				dp[tmp + 1] = dp[tmp] + 1;
				pq.push(tmp + 1);
			}
		}
		if (2 * tmp <= 200000) {
			if (dp[2 * tmp] == -1) {
				dp[2 * tmp] = dp[tmp];
				pq.push(2 * tmp);
			}
			else if (dp[2 * tmp] > dp[tmp]) {
				dp[2 * tmp] = dp[tmp];
				pq.push(2 * tmp);
			}
		}
	}

	// 3. print result
	cout << dp[K];

	return (0);
}

