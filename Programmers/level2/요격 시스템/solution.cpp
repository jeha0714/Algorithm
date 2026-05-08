#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool	compare(const vector<int> & a, const vector<int> & b) {
    return (a[1] < b[1]);
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    int	loc_last_shot = -1; // 여기서 +0.5라고 생각
    
    // 0. sort end first
    sort(targets.begin(), targets.end(), compare);
    
    // 1. Calculate
    for (size_t i = 0; i < targets.size(); i++) {
        // a. 만약 마지막으로 요격한 지점이 target의 시작지점보다 크다면 이미 요격당함
        if (loc_last_shot >= targets[i][0])
            continue;
        // b. 요격 당하지 않은 건 loc_last_shot을 e - 1로 설정
        else {
            loc_last_shot = targets[i][1] - 1;
            answer++;
        }
    }
    
    // 2. Return result
    return answer;
}