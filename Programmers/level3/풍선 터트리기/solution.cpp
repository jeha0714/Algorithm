#include <vector>
#include <cmath>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    vector<int>	dp_left; // 현재 인덱스까지 좌측에서 가장 큰 값
    vector<int>	dp_right; // 현재 인덱스까지 우측에서 가장 큰 값
    
    // 0. Init
    answer = 0;
    dp_left.resize(a.size());
    dp_left[0] = a[0];
    for (int i = 1; i < a.size(); i++) dp_left[i] = min(dp_left[i - 1], a[i]);
    dp_right.resize(a.size());
    dp_right[a.size() - 1] = a[a.size() - 1];
    for (int i = a.size() - 2; i >= 0; i--) dp_right[i] = min(dp_right[i + 1], a[i]);
    
    // 1. Calculate
    	// a. i 과 양 끝은 무조건 남길 수 있음
    if (a.size() == 1)
        answer++;
    else
        answer += 2;
    	// b. i 과 양 끝이 아닌 경우
    for (int i = 1; i <= a.size() - 2; i++) {
        if (!(dp_left[i - 1] < a[i] && a[i] > dp_right[i + 1]))
            answer++;
    }
    
    // 2. Return Answer
    return answer;
}