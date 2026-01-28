#include <vector>

enum AreaType {
    SAFE,
    BOOM,
    DANGER
};

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size();
    
    // 상하좌우, 대각선 Location variable
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    int curX, curY;
    
    // 1. Set Danger Area
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (board[r][c] == BOOM) {
                for (int i = 0; i < 8; i++) {
                    curX = r + dx[i];
                    curY = c + dy[i];
                    
                    if (0 <= curX && curX < n 
                        && 0 <= curY && curY < n 
                        && board[curX][curY] == SAFE)
                        board[curX][curY] = DANGER;
                }
            }
        }
    }
    
    // 2. Count Safe Area
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (board[r][c] == SAFE)
                answer++;
        }
    }
    
    return answer;
}
