#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
	int						M, N;
	vector< vector<int> >	tomato;	
	queue<pair<int, int> >	oddQ, evenQ;
	int						tmp, r, c;
	pair<int, int>			loc;
	int						day = -1;

	// 1. init input
	cin >> M >> N;
	tomato.resize(N);
	for (r = 0; r < N; r++) {
		tomato[r].resize(M);
		for (c = 0; c < M; c++) {
			cin >> tmp;
			tomato[r][c] = tmp;
			if (tmp == 1)
				oddQ.push(make_pair(r, c));
		}
	}
		// a. degenerate case
	if (oddQ.size() == M * N) {
		cout << 0;
		return (0);
	}
	
	// 2. calculate
	while (!oddQ.empty() || !evenQ.empty()) {
		if (day % 2 == 0) {
			while (!evenQ.empty()) {
				loc = evenQ.front();
				r = loc.first;
				c = loc.second;
				evenQ.pop();
				// case1. up
				if (r != 0 && tomato[r - 1][c] == 0) {
					oddQ.push(make_pair(r - 1, c));
					tomato[r - 1][c] = 1;
				}
				// case2. down
				if (r != N - 1 && tomato[r + 1][c] == 0) {
					oddQ.push(make_pair(r + 1, c));
					tomato[r + 1][c] = 1;
				}
				// case3. left
				if (c != 0 && tomato[r][c - 1] == 0) {
					oddQ.push(make_pair(r, c - 1));
					tomato[r][c - 1] = 1;
				}
				// case4. right
				if (c != M - 1 && tomato[r][c + 1] == 0) {
					oddQ.push(make_pair(r, c + 1));
					tomato[r][c + 1] = 1;
				}
			}
		}
		else {
			while (!oddQ.empty()) {
				loc = oddQ.front();
				r = loc.first;
				c = loc.second;
				oddQ.pop();
				// case1. up
				if (r != 0 && tomato[r - 1][c] == 0) {
					evenQ.push(make_pair(r - 1, c));
					tomato[r - 1][c] = 1;
				}
				// case2. down
				if (r != N - 1 && tomato[r + 1][c] == 0) {
					evenQ.push(make_pair(r + 1, c));
					tomato[r + 1][c] = 1;
				}
				// case3. left
				if (c != 0 && tomato[r][c - 1] == 0) {
					evenQ.push(make_pair(r, c - 1));
					tomato[r][c - 1] = 1;
				}
				// case4. right
				if (c != M - 1 && tomato[r][c + 1] == 0) {
					evenQ.push(make_pair(r, c + 1));
					tomato[r][c + 1] = 1;
				}
			}
		}
		day++;
	}

	// 3. print result
		// check tomato cant ripe case
	for (r = 0; r < N; r++) {
		for (c = 0; c < M; c++) {
			if (tomato[r][c] == 0) {
				cout << -1;
				return (0);
			}
		}
	}
	cout << day;

	return (0);
}
