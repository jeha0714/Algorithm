#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*

설계를 어떻게 하면 좋을까?
1. 모든 경우의 수를 파악해야하는거 아니야? -> 중복은 여기서 제거한다.
- 결국은 n번째에 배치되는 순서는 달라도 전체 순열은 유지된다. 
- 이를 통해 중복은 제거 될 수 있어. 그렇다면 모든 중복을 제거해야겠지

그런데 시간복잡도가 계산될까?
path의 수를 생각해보자. -> 모든 Path를 한 번 돈다고 염두하면
- 500 * 500의 path 수는 4 * 500 * 500 - 2 * 500 * 500 = 500,000
- 그런데 진입 로는 모두 다르다. 500 * 4 = 2000
=> 총합은 10^9 => 10억
=> worst case의 test 시간복잡도가 10억이다

시작은 최외각에서 항상 시작해야함
우리가 저장해야하는 정보는 현재 노드가 어딘지. 그리고 어떤 방향에서 왔는지를 계속 추적해야 함.

*/

enum {
    U = 0,
    D = 1,
    L = 2,
    R = 3,
};

// 고려해야할 것들
// 범위를 벗어나면 반대편에서 나와야 함.
// from을 바탕으로 계산해야 함. -> 3 * 4를 계산해야할까?
pair<int, int>	calc_loc(int & from, const pair<int, int> & loc, 
                         const vector<string> & grid) {
    pair<int, int>	next_loc;
    
    if (grid[loc.first][loc.second] == 'S') {
        if (from == U) {
            from = U;
            next_loc.first = loc.first + 1;
            next_loc.second = loc.second;
            if (next_loc.first == grid.size())
                next_loc.first = 0;
        }
        else if (from == D) {
            from = D;
            next_loc.first = loc.first - 1;
            next_loc.second = loc.second;
            if (next_loc.first == -1)
                next_loc.first = grid.size() - 1;
        }
        else if (from == L) {
            from = L;
            next_loc.first = loc.first;
            next_loc.second = loc.second + 1;
            if (next_loc.second == grid[next_loc.first].length())
                next_loc.second = 0;
        }
        else if (from == R) {
            from = R;
            next_loc.first = loc.first;
            next_loc.second = loc.second - 1;
            if (next_loc.second == -1)
                next_loc.second = grid[next_loc.first].length() - 1;
        }
    }
	else if (grid[loc.first][loc.second] == 'L') {
        if (from == U) {
            from = L;
            next_loc.first = loc.first;
            next_loc.second = loc.second + 1;
            if (next_loc.second == grid[next_loc.first].length())
                next_loc.second = 0;
        }
        else if (from == D) {
            from = R;
            next_loc.first = loc.first;
            next_loc.second = loc.second - 1;
            if (next_loc.second == -1)
                next_loc.second = grid[next_loc.first].length() - 1;
        }
        else if (from == L) {
            from = D;
            next_loc.first = loc.first - 1;
            next_loc.second = loc.second;
            if (next_loc.first == -1)
                next_loc.first = grid.size() - 1;
        }
        else if (from == R) {
            from = U;
            next_loc.first = loc.first + 1;
            next_loc.second = loc.second;
            if (next_loc.first == grid.size())
                next_loc.first = 0;
        }
    }
 	else if (grid[loc.first][loc.second] == 'R') {
         if (from == U) {
            from = R;
            next_loc.first = loc.first;
            next_loc.second = loc.second - 1;
            if (next_loc.second == -1)
                next_loc.second = grid[next_loc.first].length() - 1;
        }
        else if (from == D) {
            from = L;
            next_loc.first = loc.first;
            next_loc.second = loc.second + 1;
            if (next_loc.second == grid[next_loc.first].length())
                next_loc.second = 0;
        }
        else if (from == L) {
            from = U;
            next_loc.first = loc.first + 1;
            next_loc.second = loc.second;
            if (next_loc.first == grid.size())
                next_loc.first = 0;
        }
        else if (from == R) {
            from = D;
            next_loc.first = loc.first - 1;
            next_loc.second = loc.second;
            if (next_loc.first == -1)
                next_loc.first = grid.size() - 1;
        }       
    }   
    
    return (next_loc);
}

int	calc(int from, const pair<int, int> loc,
        const vector<string> & grid, vector<vector<vector<bool>>> & dp) {
    pair<int, int>	next_loc;
    int	ori_from = from;
    int	n_pass;
    
    // 0. Init
    dp[loc.first][loc.second][from] = true;
    next_loc = calc_loc(from, loc, grid);
    n_pass = 1;
    
    // 1. Calculate
    while (dp[next_loc.first][next_loc.second][from] == false) {
        dp[next_loc.first][next_loc.second][from] = true;
        next_loc = calc_loc(from, next_loc, grid);
        n_pass++;
    }
    
    // 2. Return Answer
    if (loc.first == next_loc.first && loc.second == next_loc.second 
        && from == ori_from)
        return (n_pass);
    else
        return (-1);
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    // dp의 row/col은 grid의 각 노드를 의미
    // dp[r][c][n]의 n은 0~3의 Index로 상하좌우 방문 여부를 기록
    vector<vector<vector<bool>>>	dp;
    
    // 0. Init
    dp.resize(grid.size());
    for (int r = 0; r < dp.size(); r++) {
        dp[r].resize(grid[r].length());
        for (int c = 0; c < dp[r].size(); c++) {
            dp[r][c].resize(4);
            for (int i = 0; i < 4; i++)
                dp[r][c][i] = false;
        }
    }
    
    // 1. Calculate
    // 상하좌우 4방향으로 진행해야 함.
    for (int r = 0, tmp; r < dp.size(); r++) {
        for (int c = 0; c < dp[r].size(); c++) {
            for (int i = 0; i < 4; i++) {
                tmp = calc(i, make_pair(r, c), grid, dp);
                if (tmp != -1) answer.push_back(tmp);
            }
        }
    }
   
    // 2. Return Answer
    sort(answer.begin(), answer.end(), less<int>());
    return answer;
}