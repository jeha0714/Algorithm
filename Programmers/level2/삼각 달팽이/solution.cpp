#include <vector>

using namespace std;

enum {
    TOP,
    BOT,
    RIGHT,
};

/*
전체적인 큰 동작은 아래를 반복
1. 내려간다.
2. 우측으로 이동한다.
3. 올라간다.
*/
vector<int> solution(int n) {
    vector<vector<int>>	info; // 각 위치별 순서 저장
    int cur_status; // 현재 방향을 알려주는 변수
    int cur_r; // 현재 높이를 알려주는 변수
    int cur_c; // 현재 좌우 위치를 알려주는 변수
    int num; // 현재 값
    vector<int> answer;
    
    // 0. Init
    info.resize(n);
    for (int r = 0; r < n; r++) {
        info[r].resize(r + 1);
        for (int c = 0; c < r + 1; c++) {
            info[r][c] = -1;
        }
    }
    cur_status = BOT;
    cur_r = 0;
    cur_c = 0;
    num = 1;
    
    // 1. Calculate
    while (true) {
        // a. go bot
        if (cur_status == BOT) {
            // 1) 내려가면서 info를 수정한다.
            for (; cur_r < n && info[cur_r][cur_c] == -1; cur_r++)
                info[cur_r][cur_c] = num++;
            cur_r--;
            // 2-1) 더 갈 곳이 없거나 방향 전환 하는 곳이 이미 값이 존재하는 경우 stop
            if (cur_r == 0 || info[cur_r][cur_c + 1] != -1)
                break ;
            // 2-2) 방향 전환
            else {
                cur_c++;
                cur_status = RIGHT;
            }
        }
        // b. go right
        else if (cur_status == RIGHT) {
            // 1) 우측 이동하면서 info를 수정한다.
            for (; cur_c <= cur_r && info[cur_r][cur_c] == -1; cur_c++)
                info[cur_r][cur_c] = num++;
            cur_c--;
            // 2-1) 방향 전환 하는 곳이 이미 값이 존재하는 경우 stop
            if (info[cur_r - 1][cur_c - 1] != -1)
                break ;
            // 2-2) 방향 전환
            else {
                cur_r--;
                cur_c--;
                cur_status = TOP;
            }
        }
        // c. go top
        else if (cur_status == TOP) {
            // 1) 위로 이동하면서 info를 수정한다.
            for (; cur_r >= 0 && info[cur_r][cur_c] == -1; cur_r--, cur_c--)
                info[cur_r][cur_c] = num++;
            cur_r++;
            cur_c++;
            // 2-1) 방향 전환 하는 곳이 이미 값이 존재하는 경우 stop
            if (info[cur_r + 1][cur_c] != -1)
                break ;
            // 2-2) 방향 전환
            else {
                cur_r++;
                cur_status = BOT;
            }
        }
    }
    
    // 2. Move
    for (int r = 1; r <= n; r++) {
        for (int c = 0; c < r; c++) {
            answer.push_back(info[r - 1][c]);
        }
    }
    
    // 3. Return answer
    return answer;
}