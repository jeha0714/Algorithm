#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int						N, M, tmp;
vector<vector<int> >	map;
vector<vector<bool> >	visited;
int						maxSum = 0;

static void	dfs(int numVisited, int r, int c, int score) {
	// 1. degenerate case
	if (numVisited == 4) {
		if (maxSum < score)
			maxSum = score;
		return ;
	}

	// 2. branch case
		// case1. up
	if (r > 0 && !visited[r - 1][c]) {
		visited[r - 1][c] = true;
		dfs(numVisited + 1, r - 1, c, score + map[r - 1][c]);
		visited[r - 1][c] = false;
	}
		// case2. down
	if (r < N - 1 && !visited[r + 1][c]) {
		visited[r + 1][c] = true;
		dfs(numVisited + 1, r + 1, c, score + map[r + 1][c]);
		visited[r + 1][c] = false;
	}
		// case3. left
	if (c > 0 && !visited[r][c - 1]) {
		visited[r][c - 1] = true;
		dfs(numVisited + 1, r, c - 1, score + map[r][c - 1]);
		visited[r][c - 1] = false;
	}
		// case4. right
	if (c < M - 1 && !visited[r][c + 1]) {
		visited[r][c + 1] = true;
		dfs(numVisited + 1, r, c + 1, score + map[r][c + 1]);
		visited[r][c + 1] = false;
	}
}

int main(void) {

	// 1. init input
	cin >> N >> M;
	map.resize(N);
	visited.resize(N);
	for (int r = 0; r < N; r++) {
		map[r].resize(M);
		visited[r].resize(M);
		for (int c = 0; c < M; c++) {
			cin >> tmp;
			map[r][c] = tmp;
			visited[r][c] = false;
		}
	}

	// 2. calculate
		// case1. shape isnt ㅗㅜㅓㅏ
	for (int curR = 0; curR < N; curR++) {
		for (int curC = 0; curC < M; curC++) {
			visited[curR][curC] = true;
			dfs(1, curR, curC, map[curR][curC]);
			visited[curR][curC] = false;
		}
	}

		// case2. shape is ㅗㅜㅓㅏ
	for (int ctrR = 0; ctrR < N; ctrR++) {
		for (int ctrC = 0; ctrC < M; ctrC++) {
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
