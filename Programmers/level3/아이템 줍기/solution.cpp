#include <vector>
#include <queue>

using namespace std;

#define MIN2(x, y) ((x) < (y) ? (x) : (y))

enum {
    WALL = false,
    ROAD = true,
};

bool	is_inside(const int & x, const int & y, const vector<vector<int>> & rectangle){
    int x1, y1, x2, y2;
    
    for (int i = 0; i < rectangle.size(); i++) {
        x1 = rectangle[i][0];
        y1 = rectangle[i][1];
        x2 = rectangle[i][2];
        y2 = rectangle[i][3];
        
        if ((x1 * 2 < x && x < x2 * 2) && (y1 * 2 < y && y < y2 * 2)) {
            return (true);
        }
    }
    return (false);
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    int	target = 0;
    vector<vector<bool>>	board(110, vector<bool>(110, false));
    int x1, y1, x2, y2;
    queue<pair<int, int>>	q;
    pair<int, int>	cur;
    int	dx[4] = {0, 1, 0, -1};
    int	dy[4] = {1, 0, -1, 0};
    
    /* Init */
    // 1. board에서 직사각형의 외곽을 모두 길로 만든다
    for (int i = 0; i < rectangle.size(); i++) {
        x1 = rectangle[i][0];
        y1 = rectangle[i][1];
        x2 = rectangle[i][2];
        y2 = rectangle[i][3];
        
        // a. 윗변
        for (int r = x1 * 2; r <= x2 * 2; r++)
            board[r][y2 * 2] = ROAD;
        // b. 우측
        for (int c = y1 * 2; c <= y2 * 2; c++)
            board[x2 * 2][c] = ROAD;
        // c. 밑변
        for (int r = x1 * 2; r <= x2 * 2; r++)
            board[r][y1 * 2] = ROAD;
        // d. 좌측
        for (int c = y1 * 2; c <= y2 * 2; c++)
            board[x1 * 2][c] = ROAD;
    }
    q.push(make_pair(characterX * 2, characterY * 2));
    board[characterX * 2][characterY * 2] = WALL;
    
    /* Calculate */
    /*
    	길 전체를 순회하면서 target_len VS total - target_len 비교
        도형 내부는 길이 아니므로 만났을 경우 무시 + WALL 변환
    */
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        
        if (cur.first == itemX * 2 && cur.second == itemY * 2) {
            target = answer;
        }
        answer++;
        
        for (int i = 0; i < 4; i++) {
            // a. 범위가 벗어나지 않는지 + 길인지 확인
            if ((0 <= cur.first + dx[i] && cur.first + dx[i] < 110)
               && (0 <= cur.second + dy[i] && cur.second + dy[i] < 110)
               && board[cur.first + dx[i]][cur.second + dy[i]] == ROAD) {
                // b. 길이 도형 내부라면 무시 + WALL
                if (is_inside(cur.first + dx[i], cur.second + dy[i], rectangle)) {
					board[cur.first + dx[i]][cur.second + dy[i]] = WALL;
                }
                // c. 길이 도형 외부라면 q에 push + WALL
                else {
                    q.push(make_pair(cur.first + dx[i], cur.second + dy[i]));
                    board[cur.first + dx[i]][cur.second + dy[i]] = WALL;
                    break ;
                }
            }
        }
    }
    
    /* Return Answer */
    answer = MIN2(target, answer - target);
    return (answer / 2);
}