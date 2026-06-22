#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int	dr[4] = {-1, 0, 1, 0};
    int	dc[4] = {0, 1, 0, -1};
    
    // 1. Calculate
    for (int i = 0; i < 4; i++) {
        // a. Check boundary
        if ((0 <= h + dr[i] && h + dr[i] < board.size())
           && (0 <= w + dc[i] && w + dc[i] < board[0].size())) {
            // b. Check is same color
            if (board[h][w].compare(board[h + dr[i]][w + dc[i]]) == 0)
                answer++;
       }
        
    }
    
    // 2. Return answer
    return answer;
}