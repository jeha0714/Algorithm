#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

bool	compare(const vector<int> & a, const vector<int> & b) {
    if (a[1] != b[1])
        return (a[1] > b[1]);
    else
        return (a[0] < b[0]);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<vector<vector<int>>>	level; // level; row는 각 level, col는 각 node
    vector<vector<int>>	path; // row는 각 node의 번호
    vector<int>			parent, child, tmp;
    stack<int>	s;
    int			num;
    
    // 0. Init
        
        // a. nodeinfo에 각자의 번호도 부여
	for (int i = 0; i < nodeinfo.size(); i++)
        nodeinfo[i].push_back(i + 1);
    
    	// b. nodeinfo[i][1] 내림차순 nodeinfo[i][0] 오림차순 정렬
    sort(nodeinfo.begin(), nodeinfo.end(), compare);
    
    	// c. 각 level에 위치시키기
   	level.resize(nodeinfo[0][1] + 1);
    for (int i = 0; i < nodeinfo.size(); i++)
        level[nodeinfo[i][1]].push_back(nodeinfo[i]);
    
    	// d. path 초기화
    path.resize(nodeinfo.size() + 1);
    for (int i = 0; i <= nodeinfo.size(); i++) {
        path[i].resize(2);
        path[i][0] = -1;
        path[i][1] = -1;
    }
    
    	// e. root node부터 아래로 이진 트리에 맞는 tree 구성 -> path만들기
    		// 1) nodeinfo에 자신의 left right 를 가질 수 있는 범위 구하기
    level[nodeinfo[0][1]][0].push_back(0);
    level[nodeinfo[0][1]][0].push_back(100000);
    for (int l_parent = nodeinfo[0][1], l_child; l_parent >= 1; l_parent--) {
            // 1) child level을 찾는다
        l_child = l_parent - 1;
        while (l_child >= 0 && level[l_child].size() == 0)
            l_child--;
        if (l_child < 0)
            break ;
        
            // 2) child와 parent를 연결한다
        for (int i = 0, j = 0; i < level[l_parent].size() && j < level[l_child].size();) {
            parent = level[l_parent][i];
            child = level[l_child][j];
            
            	// a) parent's left 
            if (parent[3] <= child[0] && child[0] < parent[0]) {
                path[parent[2]][0] = child[2];
                level[l_child][j].push_back(parent[3]);
                level[l_child][j].push_back(parent[0] - 1);
                j++;
            }
            	// b) parent's right
            else if (parent[0] < child[0] && child[0] <= parent[4]) {
                path[parent[2]][1] = child[2];
                level[l_child][j].push_back(parent[0] + 1);
                level[l_child][j].push_back(parent[4]);
                j++;
            }
            else
                i++;
        }
    }
    
    // 1. Calculate
    answer.resize(2);
    
    	// a. 전위 순회
    s.push(nodeinfo[0][2]);
    while (!s.empty()) {
        num = s.top();
        s.pop();
        
        answer[0].push_back(num);
        
        if (path[num][1] != -1)
            s.push(path[num][1]);
        if (path[num][0] != -1)
            s.push(path[num][0]);
    }
    
    	// b. 후위 순회
    vector<int> v(nodeinfo.size() + 1, 0);
    s.push(nodeinfo[0][2]);
    while (!s.empty()) {
        num = s.top();
        s.pop();
        
        if (v[num] == 0) {
            v[num] = 1;
            s.push(num);
            if (path[num][1] != -1)
                s.push(path[num][1]);
            if (path[num][0] != -1)
                s.push(path[num][0]);
        }
        else
            answer[1].push_back(num);
    }
    
    // 2. Return answer
    return answer;
}