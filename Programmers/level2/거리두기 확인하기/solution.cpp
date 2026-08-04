#include <string>
#include <vector>
#include <queue>

using namespace std;

/*
가장 간단하게 접근할 수 있는 방법은 5*5를 순회하면서 P일 때 다른 P간의 위치를 파악하는거지.

계산한걸 또 하나? P간에 서로 만난 경우 값이 몇인지 기록은 할 수 있겠는데 안만난 P를 위해 결국은 움직여야 함.

P일 떄 움직이는데 거리가 3초과면 멈추자.
*/

bool	is_covid(const vector<string> & area, int r, int c) {
    int	dr[4] = {-1, 0, 1, 0};
    int	dc[4] = {0, 1, 0, -1};
    vector<vector<bool>>	is_visited(5, vector<bool>(5, false));
    queue<pair<int, pair<int, int>>>	q;
    pair<int, pair<int, int>>			loc;
    int									dist;
    
    q.push(make_pair(0, make_pair(r, c)));
    is_visited[r][c] = true;
    
    while (!q.empty()) {
        loc = q.front();
        dist = loc.first;
        r = loc.second.first;
        c = loc.second.second;
        q.pop();
        
        if (dist <= 1) {
            for (int i = 0; i < 4; i++) {
                if ((0 <= r + dr[i] && r + dr[i] < 5)
                   && (0 <= c + dc[i] && c + dc[i] < 5)
                   && !is_visited[r + dr[i]][c + dc[i]]) {
                    if (area[r + dr[i]][c + dc[i]] == 'P')
                        return (true);
                    else if (area[r + dr[i]][c + dc[i]] == 'O') {
                        q.push(make_pair(dist + 1, make_pair(r + dr[i], c + dc[i])));
                        is_visited[r + dr[i]][c + dc[i]] = true;
                    }
                }
            }
        }
    }
    return (false);
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    bool		flag;
    
    // 1. Calculate
    for (int test_case = 1; test_case <= places.size(); test_case++) {
        flag = false;
        for (int r = 0; r < 5 && !flag; r++) {
            for (int c = 0; c < 5 && !flag; c++) {
                if (places[test_case - 1][r][c] == 'P') {
                    if (is_covid(places[test_case - 1], r, c)) {
                        flag = true;
                        break ;
                    }
                }
            }
        }
        if (flag) answer.push_back(0);
        else answer.push_back(1);
    }
    
    // 2. Return Answer
    return answer;
}