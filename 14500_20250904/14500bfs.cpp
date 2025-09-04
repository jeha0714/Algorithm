#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
	int						maxSum = 0;
	int						N, M, tmp;
	int						ctrR, ctrC;
	vector<vector<int> >	map;
	queue<vector<pair<int, int> > >		q;
	vector<pair<int, int> >				tmpQ; // block을 구성하는 칸의 좌표값들
	bool					flag = false;

	// 1. init input
	cin >> N >> M;
	map.resize(N);
	for (int r = 0; r < N; r++) {
		map[r].resize(M);
		for (int c = 0; c < M; c++) {
			cin >> tmp;
			map[r][c] = tmp;
		}
	}

	// 2. calculate
		// case1. shape isnt ㅗㅜㅓㅏ
	for (ctrR = 0; ctrR < N; ctrR++) {
		for (ctrC = 0; ctrC < M; ctrC++) {
			tmpQ.reserve(4);
			tmpQ.resize(0);
			tmpQ.push_back(make_pair(ctrR, ctrC));
			q.push(tmpQ);
		}
	}
	while (!q.empty()) {
		tmpQ = q.front();
		q.pop();

		// a. pass condition
		if (tmpQ.size() == 4) {
			tmp = 0;
			for (int i = 0; i < tmpQ.size(); i++)
				tmp += map[tmpQ[i].first][tmpQ[i].second];
			if (tmp > maxSum)
				maxSum = tmp;
			continue;
		}

		// b. branch condition
		ctrR = tmpQ[tmpQ.size() - 1].first;
		ctrC = tmpQ[tmpQ.size() - 1].second;
			// 1. go up
		if (ctrR > 0) {
			flag = false;
			for (int i = 0; i < tmpQ.size(); i++) {
				if (tmpQ[i].first == ctrR - 1 && tmpQ[i].second == ctrC) { 
					flag = true;
					break ;
				}
			}
			if (!flag) {
				vector tmptmp = tmpQ;
				tmptmp.push_back(make_pair(ctrR - 1, ctrC));
				q.push(tmptmp);
			}
		}
			// 2. go down
		if (ctrR < N - 1) {
			flag = false;
			for (int i = 0; i < tmpQ.size(); i++) {
				if (tmpQ[i].first == ctrR + 1 && tmpQ[i].second == ctrC){
					flag = true;
					break ;
				}
			}
			if (!flag) {
				vector tmptmp = tmpQ;
				tmptmp.push_back(make_pair(ctrR + 1, ctrC));
				q.push(tmptmp);
			}
		}
			// 3. go left 
		if (ctrC > 0)  {
			flag = false;
			for (int i = 0; i < tmpQ.size(); i++) {
				if (tmpQ[i].first == ctrR && tmpQ[i].second == ctrC - 1) {
					flag = true;
					break ;
				}
			}
			if (!flag) {
				vector tmptmp = tmpQ;
				tmptmp.push_back(make_pair(ctrR, ctrC - 1));
				q.push(tmptmp);
			}
		}
			// 4. go right
		if (ctrC < M - 1)  {
			flag = false;
			for (int i = 0; i < tmpQ.size(); i++) {
				if (tmpQ[i].first == ctrR && tmpQ[i].second == ctrC + 1) {
					flag = true;
					break ;
				}
			}
			if (!flag) {
				vector tmptmp = tmpQ;
				tmptmp.push_back(make_pair(ctrR, ctrC + 1));
				q.push(tmptmp);
			}
		}
	}

		// case2. shape is ㅗㅜㅓㅏ
	for (ctrR = 0; ctrR < N; ctrR++) {
		for (ctrC = 0; ctrC < M; ctrC++) {
			// skip if edge center
			if ((ctrR == 0 && ctrC == 0) || (ctrR == 0 && ctrC == M - 1) || (ctrR == N - 1 && ctrC == 0) || (ctrR == N - 1 && ctrC == M - 1))
				continue;

			// a. ㅗ
			if (0 < ctrR && 0 < ctrC && ctrC < M - 1) {
				if (map[ctrR][ctrC - 1] + map[ctrR][ctrC] + map[ctrR][ctrC + 1] + map[ctrR - 1][ctrC] > maxSum)
					maxSum = map[ctrR][ctrC - 1] + map[ctrR][ctrC] + map[ctrR][ctrC + 1] + map[ctrR - 1][ctrC];
			}
			// b. ㅜ
			if (ctrR < N - 1 && 0 < ctrC && ctrC < M - 1) {
				if (map[ctrR][ctrC - 1] + map[ctrR][ctrC] + map[ctrR][ctrC + 1] + map[ctrR + 1][ctrC] > maxSum)
					maxSum = map[ctrR][ctrC - 1] + map[ctrR][ctrC] + map[ctrR][ctrC + 1] + map[ctrR + 1][ctrC];
			}
			// c. ㅓ
			if (0 < ctrR && ctrR < N - 1 && 0 < ctrC) {
				if (map[ctrR][ctrC - 1] + map[ctrR][ctrC] + map[ctrR - 1][ctrC] + map[ctrR + 1][ctrC] > maxSum)
					maxSum = map[ctrR][ctrC - 1] + map[ctrR][ctrC] + map[ctrR - 1][ctrC] + map[ctrR + 1][ctrC];
			}
			// d. ㅏ
			if (0 < ctrR && ctrR < N - 1 && ctrC < M - 1) {
				if (map[ctrR][ctrC + 1] + map[ctrR][ctrC] + map[ctrR - 1][ctrC] + map[ctrR + 1][ctrC] > maxSum)
					maxSum = map[ctrR][ctrC + 1] + map[ctrR][ctrC] + map[ctrR - 1][ctrC] + map[ctrR + 1][ctrC];
			}
		}
	}

	// 3. output result
	cout << maxSum;

	return (0);
}
