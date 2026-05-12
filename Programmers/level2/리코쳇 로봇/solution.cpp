#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<string> board) {
    int	r_len = board.size();
    int	c_len = board[0].length();
    pair<int, int>	s, e;
    vector<vector<int>>	dp(r_len, vector<int>(c_len, 2147483647));
    queue<pair<int, int>>	q;
    int	wall;
    int answer = 0;
    
    // 0. Init
    for (int r = 0; r < r_len; r++) {
        for (int c = 0; c < c_len; c++) {
            if (board[r][c] == 'R')
                s = make_pair(r, c);
            if (board[r][c] == 'G')
                e = make_pair(r, c);
        }
    }
    q.push(s);
    dp[s.first][s.second] = 0;
    
    // 1. Calculate
    while (!q.empty()) {
        // a. pop from queue
        s = q.front();
        q.pop();
        
        // b. move
        	// 1) up
        if (s.first > 0) {
            for (wall = s.first; wall >= 0; wall--) {
                if (board[wall][s.second] == 'D')
                    break ;
            }
            if (dp[wall + 1][s.second] > dp[s.first][s.second] + 1) {
                dp[wall + 1][s.second] = dp[s.first][s.second] + 1;
                q.push(make_pair(wall + 1, s.second));
            }
        }
        	// 2) down 
        if (s.first < r_len - 1) {
            for (wall = s.first; wall < r_len; wall++) {
                if (board[wall][s.second] == 'D')
                    break ;
            }
            if (dp[wall - 1][s.second] > dp[s.first][s.second] + 1) {
                dp[wall - 1][s.second] = dp[s.first][s.second] + 1;
                q.push(make_pair(wall - 1, s.second));
            }
        }
        	// 3) left 
        if (s.second > 0) {
            for (wall = s.second; wall >= 0; wall--) {
                if (board[s.first][wall] == 'D')
                    break ;
            }
            if (dp[s.first][wall + 1] > dp[s.first][s.second] + 1) {
                dp[s.first][wall + 1] = dp[s.first][s.second] + 1;
                q.push(make_pair(s.first, wall + 1));
            }
        }       
            // 4) right
        if (s.second < c_len - 1) {
            for (wall = s.second; wall < c_len; wall++) {
                if (board[s.first][wall] == 'D')
                    break ;
            }
            if (dp[s.first][wall - 1] > dp[s.first][s.second] + 1) {
                dp[s.first][wall - 1] = dp[s.first][s.second] + 1;
                q.push(make_pair(s.first, wall - 1));
            }
        }
    }       	
    answer = dp[e.first][e.second];
    if (answer == 2147483647)
        answer = -1;
    
    // 2. Return Result
    return answer;
}