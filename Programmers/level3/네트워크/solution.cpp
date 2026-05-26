#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool>	visited(n, false);
    queue<int>		q;
    int				tmp;
    
    // 1. Calculate
    for (int i = 0; i < n; i++) {
        // a. visited하지 않은 컴터를 찾는다
        if (!visited[i]) {
            // b. 상태 업데이트
            visited[i] = true;
            
            // c. answer 증가
            answer++;
            
            // d. 해당 컴퓨터와 이어진 모든 컴퓨터를 방문처리한다.
            q.push(i);
            while (!q.empty()) {
                tmp = q.front();
                q.pop();
                
                for (int j = 0; j < computers[tmp].size(); j++) {
                    if (computers[tmp][j] == 1 && visited[j] == false) {
                        visited[j] = true;
                        q.push(j);
                    }
                }
            }
        }
    }
    
    // 2. Return answer
    return answer;
}