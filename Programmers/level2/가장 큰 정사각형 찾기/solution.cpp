#include<vector>
#include <cstdlib>

using namespace std;

/*
dp[r][c]에 최대 정사각형 크기를 저장해둔다.
*/
int solution(vector<vector<int>> board)
{
    int					answer = 0;
    vector<vector<int>>	dp;

    // 0. Init
    	// a. resize dp
    dp.resize(board.size());
    for (size_t r = 0; r < board.size(); r++)
        dp[r].resize(board[r].size());
    
    // 1. Calculate
    	// a. dp를 초기화하면서 answer도 초기화
    for (size_t r = 0; r < board.size(); r++) {
        for (size_t c = 0; c < board[r].size(); c++) {
            // 0). 현재 위치가 0인 경우
            if (board[r][c] == 0) dp[r][c] = 0;
            
            // 1). 현재 위치가 1인 경우
            else {
                // a). r이 최상단 or 최좌측인 경우
                if (r == 0 || c == 0) dp[r][c] = 1;
                // b). 그렇지 않은 경우
                else {
                    dp[r][c] = min(min(dp[r - 1][c - 1], dp[r- 1][c]), dp[r][c - 1]) + 1;
                }
                
                // a). 현재 위치를 answer와 대조
                answer = max(answer, dp[r][c] * dp[r][c]);
            }
        }
    }
    
    // 2. Return Answer
    return answer;
}