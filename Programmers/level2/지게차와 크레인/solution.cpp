#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

enum {
    outside,
    inside,
    will_outside,
    removed_no_outside,
    removed_yes_outside,
};

void	bfs(int r, int c, vector<vector<int>> & status);

bool	is_valid_range(int r, int c, int max_r, int max_c) {
    if (0 <= r && r < max_r && 0 <= c && c < max_c)
        return (true);
   	else
        return (false);
}

void	adjust_adjacent(int r, int c, vector<vector<int>> & status) {
    int	dr[4] = {-1, 0, 1, 0};
    int	dc[4] = {0, 1, 0, -1};
    
    for (int i = 0; i < 4; i++) {
        if (is_valid_range(r + dr[i], c + dc[i], status.size(), status[0].size())) {
            if (status[r + dr[i]][c + dc[i]] == inside) {
            	status[r + dr[i]][c + dc[i]] = will_outside;
            }
            else if (status[r + dr[i]][c + dc[i]] == removed_no_outside) {
                status[r + dr[i]][c + dc[i]] = removed_yes_outside; 
                bfs(r + dr[i], c + dc[i], status);
            }
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
            if (is_valid_range(r + dr[i], c + dc[i], status.size(), status[0].size())){
                if (status[r + dr[i]][c + dc[i]] == removed_no_outside) {
                    status[r + dr[i]][c + dc[i]] = removed_yes_outside; 
                    q.push(make_pair(r + dr[i], c + dc[i]));
                }
                else if (status[r + dr[i]][c + dc[i]] == inside) {
                    status[r + dr[i]][c + dc[i]] = will_outside;
                }
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
    
    // 1. Calculate block
    for (int i_cmd = 0; i_cmd < requests.size(); i_cmd++) {
        cmd = requests[i_cmd][0];
            
        // a. remove
        if (requests[i_cmd].length() == 1) {
            for (int r = 0; r < len_r; r++) {
                for (int c = 0; c < len_c; c++) {
                    if (status[r][c] == outside && storage[r][c] == cmd) {
                        status[r][c] = removed_yes_outside;
                        adjust_adjacent(r, c, status);
                    }
                }
            }
        }
        else {
            // 1) remove inside first
            for (int r = 0; r < len_r; r++) {
                for (int c = 0; c < len_c; c++) {
                    if (status[r][c] == inside && storage[r][c] == cmd) {
                        status[r][c] = removed_no_outside;
                    }
                }
            }
            // 2) remove outside next
            for (int r = 0; r < len_r; r++) {
                for (int c = 0; c < len_c; c++) {
                    if (status[r][c] == outside && storage[r][c] == cmd) {
                        status[r][c] = removed_yes_outside;
                        adjust_adjacent(r, c, status);
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
    
    // 2. Calculate answer
    for (int r = 0; r < len_r; r++) {
        for (int c = 0; c < len_c; c++) {
            //cout << status[r][c];
            if (status[r][c] != removed_no_outside && status[r][c] != removed_yes_outside)
                answer++;
        }
        //cout << "\n";
    }
    
    // 3. Return result
    return answer;
}