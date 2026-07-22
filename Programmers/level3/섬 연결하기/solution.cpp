#include <vector>
#include <algorithm>

using namespace std;

bool	compare(const vector<int> & a, const vector<int> & b) {
    return (a[2] < b[2]);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<int>	groups(n, 0);
    int	num, a, b, cost;
    int	big, small;
    
    // 0. Init
    	// cost가 작은 path 순서로 오름차순
    sort(costs.begin(), costs.end(), compare);
    num = 1;
    
    // 1. Calculate
    for (int i = 0; i < costs.size(); i++) {
        a = costs[i][0];
        b = costs[i][1];
        cost = costs[i][2];
        
        if (groups[a] == 0 && groups[b] == 0) {
            groups[a] = num;
            groups[b] = num;
            num++;
            answer += cost;
        }
        else if (groups[a] == 0) {
            groups[a] = groups[b];
            answer += cost;
        }
        else if (groups[b] == 0) {
            groups[b] = groups[a];
            answer += cost;
        }
        else if (groups[a] != groups[b]) {
            small = groups[a] < groups[b] ? groups[a] : groups[b];
            big = groups[a] > groups[b] ? groups[a] : groups[b];
            
            for (int i = 0; i < n; i++) {
                if (groups[i] == big)
                    groups[i] = small;
            }
            answer += cost;
        }
		// 같은 그룹의 경우 pass
    }
    
    // 2. Return Answer
    return answer;
}