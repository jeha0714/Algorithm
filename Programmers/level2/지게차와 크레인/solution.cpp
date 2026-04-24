#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

enum {
    outside,
    inside,
    will_outside,
    removed
};

void	adjust_adjacent(int r, int c, vector<vector<int>> & status) {
    int	dr[4] = {-1, 0, 1, 0};
    int	dc[4] = {0, 1, 0, -1};
    
    for (int i = 0; i < 4; i++) {
        if (0 <= r + dr[i] && r + dr[i] < status.size() 
           && 0 <= c + dc[i] && c + dc[i] < status[0].size()
           && status[r + dr[i]][c + dc[i]] == inside) {
            status[r + dr[i]][c + dc[i]] = will_outside;
        }
    }
}

void	bfs(int r, int c, vector<vector<int>> & status) {
    queue<pair<int, int>>	q;
    pair<int, int>	tmp;
    int	dr[4] = {-1, 0, 1, 0};
    int	dc[4] = {0, 1, 0, -1};
    
    q.push(make_pair(r, c));
    
    while (!q.empty()) {
        tmp = q.front();
        q.pop();
        r = tmp.first;
        c = tmp.second;
        
         for (int i = 0; i < 4; i++) {
            if (0 <= r + dr[i] && r + dr[i] < status.size() 
               && 0 <= c + dc[i] && c + dc[i] < status[0].size()
               && status[r + dr[i]][c + dc[i]] == inside) {
                status[r + dr[i]][c + dc[i]] = will_outside;
                q.push(make_pair(r + dr[i], c));
            }
        }   
    }
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    int len_r, len_c;
    char cmd;
    vector<vector<int>>	status(storage.size(), vector<int>(storage[0].length(), outside));
    
    // 0. Init
    len_r = storage.size();
    len_c = storage[0].length();
    for (int r = 1; r < len_r - 1; r++) {
        for (int c = 1; c < len_c - 1; c++) {
            status[r][c] = inside;
        }
    }
    
    // 1. Calculate
    for (int i_cmd = 0; i_cmd < requests.size(); i_cmd++) {
        cmd = requests[i_cmd][0];
            
        // a. remove
        if (requests[i_cmd].length() == 1) {
            for (int r = 0; r < len_r; r++) {
                for (int c = 0; c < len_c; c++) {
                    if (status[r][c] == outside && storage[r][c] == cmd) {
                        status[r][c] = removed;
                        adjust_adjacent(r, c, status);
                    }
                }
            }
        }
        else {
            for (int r = 0; r < len_r; r++) {
                for (int c = 0; c < len_c; c++) {
                    if (status[r][c] == outside && storage[r][c] == cmd) {
                        status[r][c] = removed;
                        adjust_adjacent(r, c, status);
                    }
                }
            }
            for (int r = 0; r < len_r; r++) {
                for (int c = 0; c < len_c; c++) {
                    if (storage[r][c] == cmd) {
                        if (status[r][c] == will_outside) {
                            bfs(r, c, status);
                        }
                    }
                }
            }
            for (int r = 0; r < len_r; r++) {
                for (int c = 0; c < len_c; c++) {
                    if (storage[r][c] == cmd) {
                        if (status[r][c] == will_outside)
                            adjust_adjacent(r, c, status);
                        status[r][c] = removed;
                    }
                }
            }
        }
        
        // b. set next status
        for (int r = 0; r < len_r; r++) {
            for (int c = 0; c < len_c; c++) {
                if (status[r][c] == will_outside)
                    status[r][c] = outside;
            }
        }
    }
    for (int r = 0; r < len_r; r++) {
        for (int c = 0; c < len_c; c++) {
            if (status[r][c] != removed)
                answer++;
        }
    }
    
    // 2. Return result
    return answer;
}
