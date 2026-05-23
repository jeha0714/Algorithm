#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>>	path;
    vector<int> v(n + 1, 0);
    queue<int>	q;
    int	cur_node, adjacent;
    
    // 0. Init
    path.resize(n + 1);
    for (int i = 0; i < edge.size(); i++) {
        path[edge[i][0]].push_back(edge[i][1]);
        path[edge[i][1]].push_back(edge[i][0]);
    }
    q.push(1);
    
    // 1. Calc
    	// a. set length each node
    while (!q.empty()) {
        cur_node = q.front();
        q.pop();
        
        for (int i = 0; i < path[cur_node].size(); i++) {
            adjacent = path[cur_node][i];
            if (v[adjacent] == 0 && adjacent != 1) {
                q.push(adjacent);
                v[adjacent] = v[cur_node] + 1;
            }
        }
    }
    	// b. find most far away node's num
    cur_node = 1;
    answer = 1;
    for (int i = 2; i <= n; i++) {
        if (v[cur_node] == v[i])
            answer++;
        else if (v[cur_node] < v[i]) {
            answer = 1;
            cur_node = i;
        }
    }
    
    // 2. Return answer
    return answer;
}