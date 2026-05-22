#include <vector>
#include <cmath>

using namespace std;

enum {
    SHEEP = 0,
    WOLF = 1,
    CANT = false,
    CAN = true,
};

void	dfs(int cur, int sheep, int wolf, vector<int> & info, vector<bool> & next, vector<vector<int>> & path, int & answer) {
    
    // 0. 정보 최신화
    if (info[cur] == SHEEP)
        sheep++;
    else
        wolf++;
    
    // 1. 현재 노드에 도착 했을 때 양의 수 == 늑대 수 라면 종료
    if (sheep == wolf)
        return ;
    
    // 2. 현재 노드에서 갈 수 있는 노드 for문으로 다시 dfs
    	// a. 가능한 구역 추가
    for (int i = 0; i < path[cur].size(); i++)
        next[path[cur][i]] = CAN;
    	// b. 가능한 구역 전체 순회
    for (int i = 0; i < next.size(); i++) {
        if (next[i] == CAN) {
            next[i] = CANT;
            dfs(i, sheep, wolf, info, next, path, answer);
            next[i] = CAN;
        }
    }
    
    // 3. 되돌리기전 현재의 최선 값을 저장
    answer = max(answer, sheep);
    
    // 4. 현재를 되돌림
    for (int i = 0; i < path[cur].size(); i++)
        next[path[cur][i]] = CANT;
    
    if (info[cur] == SHEEP)
        sheep--;
    else
        wolf--;
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    int	sheep, wolf;
    vector<bool>	next(info.size(), CANT); // 다음에 갈 수 있는 Node num 저장
    vector<vector<int>>	path(info.size()); // row index 별로 갈 수 있는 곳 저장
    
    // 0. Init
    sheep = 0;
    wolf = 0;
    for (int i = 0; i < edges.size(); i++)
        path[edges[i][0]].push_back(edges[i][1]);
    
    // 1. dfs
    dfs(0, sheep, wolf, info, next, path, answer);
    
    // 2. Return answer
    return answer;
}