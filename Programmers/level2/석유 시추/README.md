#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <cmath>

using namespace std;

void	set_oil_info(int r, int c, int num, const vector<vector<int>> & land, vector<vector<pair<int, int>>> & oil_info) {
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    queue<pair<int, int>>	q;
    pair<int, int>	cur;
    int				total = 0;
    
    // 1. set oil_num
    oil_info[r][c].first = num;
    q.push(make_pair(r, c));
    total = 1;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            if ((0 <= cur.first + dr[i] && cur.first + dr[i] < land.size()) && (0 <= cur.second + dc[i] && cur.second + dc[i] < land[cur.first + dr[i]].size()) && land[cur.first + dr[i]][cur.second + dc[i]] == 1  && oil_info[cur.first + dr[i]][cur.second + dc[i]].first == 0) {
                oil_info[cur.first + dr[i]][cur.second + dc[i]].first = num;
                q.push(make_pair(cur.first + dr[i], cur.second + dc[i]));
                total++;
            }
        }       
    }
    
    // 2. set oil amount
    oil_info[r][c].second = total;
    q.push(make_pair(r, c));
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            if ((0 <= cur.first + dr[i] && cur.first + dr[i] < land.size()) && (0 <= cur.second + dc[i] && cur.second + dc[i] < land[cur.first + dr[i]].size()) && land[cur.first + dr[i]][cur.second + dc[i]] == 1  && oil_info[cur.first + dr[i]][cur.second + dc[i]].second == 0) {
                oil_info[cur.first + dr[i]][cur.second + dc[i]].second = total;
                q.push(make_pair(cur.first + dr[i], cur.second + dc[i]));
            }
        }       
    }
}

int solution(vector<vector<int>> land) {
    // 각 land에 [i][j].first 는 해당 oli area number, second는 해당 oil 양
    vector<vector<pair<int, int>>>	oil_info(500, vector<pair<int, int>>(500, pair<int, int>(0, 0)));
    bitset<125001>	is_visit;
    int	num = 1;
    int answer = 0;
    
    // 0. Init
    	// 각 공간을 bfs 돌면서 석유에 해당하는 number 부여
    for (int r = 0; r < land.size(); r++) {
        for (int c = 0; c < land[r].size(); c++) {
            if (land[r][c] == 1 && oil_info[r][c].first == 0) {
                set_oil_info(r, c, num, land, oil_info);
                num++;
            }
        }
    }
   
    // 1. Calculator : Find Max
		// index 순회하면서 최대값 찾기
    for (int j = 0, cur; j < land[0].size(); j++) {
        cur = 0;
        is_visit = 0;
        for (int i = 0; i < land.size(); i++) {
            if (j < land[i].size() && land[i][j] == 1 && is_visit[oil_info[i][j].first] == 0) {
                cur += oil_info[i][j].second;
                is_visit[oil_info[i][j].first] = 1;
            }
        }
        answer = max(cur, answer);
    }
    
    // 2. Return Max
    return answer;
}