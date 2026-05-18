#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    vector<vector<int>>	path(n + 1);
    vector<int>	depth(n + 1, 0);
    vector<vector<int>> v_depth(101);
    queue<int>	q;
    vector<int>	num_nodes(n + 1, 1);
    int	tmp;
    int answer = 2147483647;
    
    // 0. Init
    	// a. path를 만든다
    for (int i = 0; i < wires.size(); i++) {
        path[wires[i][0]].push_back(wires[i][1]);
        path[wires[i][1]].push_back(wires[i][0]);
    }
    	// b. #1을 root node로 depth를 구한다.
    q.push(1);
    depth[1] = 1;
    v_depth[1].push_back(1);
    while (!q.empty()) {
        tmp = q.front();
        q.pop();
        
        for (int i = 0; i < path[tmp].size(); i++) {
            if (depth[path[tmp][i]] == 0) {
                q.push(path[tmp][i]);
                depth[path[tmp][i]] = depth[tmp] + 1;
                v_depth[depth[tmp] + 1].push_back(path[tmp][i]);
            }
        }
    }
    	// c. 가장 하단 depth에서 거슬러 올라오면서 num_nodes 계산
    for (int cur_depth = 100; cur_depth >= 1; cur_depth--) {
        for (int i = 0, node; i < v_depth[cur_depth].size(); i++) {
            node = v_depth[cur_depth][i];
            for (int j = 0; j < path[node].size(); j++) {
                if (depth[path[node][j]] < depth[node])
                    num_nodes[path[node][j]] += num_nodes[node];
            }
        }
    }

    // 1. Calculate
    for (int i = 1; i <= n; i++) {
        answer = min(answer, abs((n - num_nodes[i]) - num_nodes[i]));
    }
   
    // 2. Return
    return answer;
}