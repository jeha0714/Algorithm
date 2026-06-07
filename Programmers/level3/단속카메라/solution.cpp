#include <vector>
#include <algorithm>

using namespace std;

bool	comp(vector<int> & a, vector<int> & b) {
    return (a[1] < b[1]);
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int last_cctv = -30001;
    
    // 0. Init
    sort(routes.begin(), routes.end(), comp);
    
    // 1. Calculate
    for (int i = 0; i < routes.size(); i++) {
        if (!(routes[i][0] <= last_cctv && last_cctv <= routes[i][1])) {
            answer++;
            last_cctv = routes[i][1];
        }
    }
    
    // 2. Return answer
    return answer;
}