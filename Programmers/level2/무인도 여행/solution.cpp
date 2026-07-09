#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    queue<pair<int, int>>	q;
    int	dr[4] = {-1, 0, 1, 0};
    int	dc[4] = {0, 1, 0, -1};
    int	tmp;
    pair<int, int>	cur;
    
    // 0. Init
    
    // 1. Calculate
    for (int r = 0; r < maps.size(); r++) {
        for (int c = 0; c < maps[r].length(); c++) {
            if (maps[r][c] != 'X') {
                
                tmp = maps[r][c] - '0';
                maps[r][c] = 'X';
                q.push(make_pair(r, c));
                while (!q.empty()) {
                    cur = q.front();
                    q.pop();
                    
                    for (int i = 0, rr, cc; i < 4; i++) {
                        rr = cur.first + dr[i];
                        cc = cur.second + dc[i];
                        
                        if ((0 <= rr && rr < maps.size())
                           && (0 <= cc && cc < maps[rr].length())
                           && maps[rr][cc] != 'X') {
                            tmp += maps[rr][cc] - '0';
                            maps[rr][cc] = 'X';
                            q.push(make_pair(rr, cc));
                        }
                    }
                    
                }
                
                answer.push_back(tmp);
            }
        }
    }
    
    	// b. sort
    if (answer.size() == 0)
        answer.push_back(-1);
	else
        sort(answer.begin(), answer.end(), less<int>());
    
    // 2. Return Answer
    return answer;
}