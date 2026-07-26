#include <vector>
#include <queue>
#include <cmath>

using namespace std;

/*
MST 문제
1. 경로를 모두 한 pq에 저장한다.
2. 경로를 하나씩 꺼내면서 union-find를 진행한다.
*/

class union_find {
private:
    vector<vector<pair<int, int>>>	group;
    
public:
    union_find(const vector<vector<int>> & land) {
        group.resize(land.size());
        for (int r = 0; r < land.size(); r++) {
            group[r].resize(land[r].size());
            for (int c = 0; c < land[r].size(); c++) {
                group[r][c].first = r;
                group[r][c].second = c;
            }
        }
    }
    
    pair<int, int>	find(int x1, int y1) {
        if (group[x1][y1].first != x1 || group[x1][y1].second != y1) {
            group[x1][y1] = find(group[x1][y1].first, group[x1][y1].second);
        }
        return (group[x1][y1]);
    }
    
    void	unions(int x1, int y1, int x2, int y2) {
        pair<int, int> root1, root2;
        
        root1 = find(x1, y1);
        root2 = find(x2, y2);
        
        group[root2.first][root2.second].first = root1.first;
        group[root2.first][root2.second].second = root1.second;
    }
};

class cmp {
public:
    bool	operator() (const pair<int, vector<int>> & a, const pair<int, vector<int>> & b) {
        return (a.first > b.first);
    }
};

int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    	// pq.first = path cost
    	// pq.second = [0][1]은 first node location
    	// pq.second = [2][3]은 second node location
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, cmp>	pq;
    vector<int>	tmp(4);
    union_find	uf(land);
    vector<vector<int>>	group;
    int	total = 0; // total path를 의미
    pair<int, int>	loc1, loc2;
    
    // 0. Init
    	// a. 경로를 모두 init -> 우측 아래만 확인
    for (int r = 0; r < land.size(); r++) {
        for (int c = 0, cost; c < land[r].size(); c++) {
            tmp[0] = r;
            tmp[1] = c;
            // 우측 확인
            if (c < land[r].size() - 1) {
                tmp[2] = r;
                tmp[3] = c + 1;
                cost = abs(land[r][c] - land[r][c + 1]);
                if (cost <= height)
                    pq.push(make_pair(0, tmp));
                else
                    pq.push(make_pair(cost, tmp));
            }
            // 하단 확인
            if (r < land.size() - 1 && c < land[r + 1].size()) {
                tmp[2] = r + 1;
                tmp[3] = c;
                cost = abs(land[r][c] - land[r + 1][c]);
                if (cost <= height)
                    pq.push(make_pair(0, tmp));
                else
                    pq.push(make_pair(cost, tmp));
            }
        }
        // b. total 초기화
        total += land[r].size();
    }
    
    // 1. Calculate
    	// a. 경로를 하나씩 꺼내면서 MST를 채운다.
    for (int num_path = 0, x1, y1, x2, y2, cost; num_path < total - 1;) {
        // 1) pq 정보 저장
        x1 = pq.top().second[0];
        y1 = pq.top().second[1];
        x2 = pq.top().second[2];
        y2 = pq.top().second[3];
        cost = pq.top().first;
        
        // 2) pq pop
        pq.pop();
        
        // 3) pass condition
        loc1 = uf.find(x1, y1);
        loc2 = uf.find(x2, y2);
        if (loc1.first == loc2.first && loc1.second == loc2.second)
            continue;
        // 4) union-find
        else {
            uf.unions(x1, y1, x2, y2);
            answer += cost;
            num_path++;
        }
    }
    
    // 2. Return Answer
    return answer;
}