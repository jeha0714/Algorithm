#include <vector>
#include <queue>
#include <climits>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<vector<pair<int, int>>>	path(N + 1);
    vector<int>				cost(N + 1, INT_MAX);
    queue<int>				q;
    int	a, b, time;
    
    // 0. Init
    	// a. path를 등록
    for (size_t i = 0; i < road.size(); i++) {
        a = road[i][0];
        b = road[i][1];
        time = road[i][2];
        path[a].push_back(make_pair(b, time));
        path[b].push_back(make_pair(a, time));
    }
    cost[1] = 0;
    q.push(1);
    
    // 1. Calculate
    while (!q.empty()) {
    	// a. queue head처리
        a = q.front();
        q.pop();
        
        // b. queue head와 연결된 마을 cost 초기화
        for (size_t i = 0; i < path[a].size(); i++) {
            b = path[a][i].first;
            time = path[a][i].second;
            
            // 1). cost가 a + time이 현재 저장된 값보다 작다면
            // cost값 최신화 및 queue 삽입
            if (cost[a] + time < cost[b]) {
                cost[b] = cost[a] + time;
                q.push(b);
            }
        }
    }
    // c. cost가 k보다 같거나 작은 값들 파악
    for (size_t i = 1; i < cost.size(); i++) {
        if (cost[i] <= K) answer++;
    }
    
    // 2. Return Answer
    return answer;
}