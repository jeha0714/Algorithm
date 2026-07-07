#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<string> maps) {
    int answer = -1;
    vector<vector<int>>	is_visited;
    queue<pair<int, int>>	q;
    int	dr[4] = {-1, 0, 1, 0};
    int	dc[4] = {0, 1, 0, -1};
    char			aim;
    pair<int, int>	tmp;
    
    // 0. Init
    is_visited.resize(maps.size());
    for (int r = 0; r < is_visited.size(); r++) {
        is_visited[r].resize(maps[r].size());
        for (int c = 0; c < is_visited[r].size(); c++) {
            is_visited[r][c] = -1;
            if (maps[r][c] == 'S') {
                q.push(make_pair(r, c));
                is_visited[r][c] = 0;
            }
        }
    }
    aim = 'L';
    
    // 1. Calculate
    while (!q.empty()) {
        tmp = q.front();
        q.pop();
        
        for (int i = 0, r, c; i < 4; i++) {
            r = tmp.first + dr[i];
            c = tmp.second + dc[i];
            
            if ((0 <= r && r < maps.size()) 
                && (0 <= c && c < maps[r].size()) 
                && maps[r][c] != 'X'
                && is_visited[r][c] == -1) {
                
                q.push(make_pair(r, c));
                is_visited[r][c] = is_visited[tmp.first][tmp.second] + 1;
                
                if (aim == 'L' && maps[r][c] == 'L') {
                    while (!q.empty()) q.pop();
                    aim = 'E';
                    answer = is_visited[r][c];
                    
					for (int rr = 0; rr < is_visited.size(); rr++) {
                        for (int cc = 0; cc < is_visited[r].size(); cc++) {
                            is_visited[rr][cc] = -1;
                            if (maps[rr][cc] == 'L') {
                                q.push(make_pair(rr, cc));
                                is_visited[rr][cc] = 0;
                            }
                        }
                    }
                    break ;
                }
                else if (aim == 'E' && maps[r][c] == 'E') {
                    answer += is_visited[r][c];
                    return (answer);
                }
            }
        }
    }
    if (maps[tmp.first][tmp.second] != 'E')
        answer = -1;
    
    // 2. Return Answer
    return answer;
}