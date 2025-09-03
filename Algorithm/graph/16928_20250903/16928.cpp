#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
	int			tmp1, tmp2;
	int 		N, M;
	vector<int>	ladderInfo(100, -1);
	vector<int>	snakeInfo(100, -1);
	vector<int>	minReachCount(101, 100);
	queue<int>	q;

	// 1. init input
	cin >> N >> M;
	ladderInfo.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> tmp1 >> tmp2;
		ladderInfo[tmp1] = tmp2;
	}
	snakeInfo.resize(M);
	for (int i = 0; i < M; i++) {
		cin >> tmp1 >> tmp2;
		snakeInfo[tmp1] = tmp2;
	}

	/*
	for (int i = 0; i < 100; i++)
		cout << i << " " <<  ladderInfo[i] << "\n";

	for (int i = 0; i < 100; i++)
		cout << i << " " <<  snakeInfo[i] << "\n";
		*/

	// 2. calculate
	minReachCount[1] = 0;
	q.push(1);
	while (!q.empty()) {
		tmp1 = q.front();
		q.pop();

		// a. 사다리 여부  확인
		if (ladderInfo[tmp1] != -1) {
			tmp2 = minReachCount[ladderInfo[tmp1]];
			if (tmp2 > minReachCount[tmp1]) {
				minReachCount[ladderInfo[tmp1]] = minReachCount[tmp1];
				q.push(ladderInfo[tmp1]);
			}
			continue;
		}

		// b. 뱀 여부 확인
		if (snakeInfo[tmp1] != -1) {
			tmp2 = minReachCount[snakeInfo[tmp1]];
			if (tmp2 > minReachCount[tmp1]) {
				minReachCount[snakeInfo[tmp1]] = minReachCount[tmp1];
				q.push(snakeInfo[tmp1]);
			}
			continue;
		}

		// c. 일반 다이스를 굴렸을 때
		for (int i = 1; i <= 6; i++) {
			if (tmp1 + i <= 100 && minReachCount[tmp1 + i] > minReachCount[tmp1] + 1) {
				minReachCount[tmp1 + i] = minReachCount[tmp1] + 1;
				if (tmp1 + i < 100)
					q.push(tmp1 + i);
			}
		}
	}


	// 3. return result
	cout << minReachCount[100] << "\n";

	return (0);
}

