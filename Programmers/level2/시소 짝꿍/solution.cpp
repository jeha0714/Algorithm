#include <vector>

using namespace std;

long long solution(vector<int> weights) {
    long long			answer = 0;
    vector<long long>	v(1001, 0); // i-kg 등장 수 저장
    
    // 0. Init
    for (int i = 0; i < weights.size(); i++) {
        v[weights[i]]++;
    }
    
    // 1. Calculate
    for (int cur = 100, comp; cur <= 1000; cur++) {
        // a. 현재 weight가 2이상인 경우 -> 현재 weight와 비교
        if (v[cur] >= 2)
            answer += ((v[cur] * (v[cur] - 1)) / 2);
        
        // b. 현재 weight와 다른 무게와 연산 3 : 2
        comp = cur * 3;
        if (comp % 2 == 0 && comp <= 2000 && v[comp / 2] > 0)
            answer += (v[cur] * v[comp / 2]);
        
        // c. 현재 weight와 다른 무게와 연산 4 : 2
        comp = cur * 4;
        if (comp % 2 == 0 && comp <= 2000 && v[comp / 2] > 0)
            answer += (v[cur] * v[comp / 2]);
        
        // d. 현재 weight와 다른 무게와 연산 4 : 3
        comp = cur * 4;
        if (comp % 3 == 0 && comp <= 3000 && v[comp / 3] > 0)
            answer += (v[cur] * v[comp / 3]);
    }
    
    // 2. Return Answer
    return answer;
}