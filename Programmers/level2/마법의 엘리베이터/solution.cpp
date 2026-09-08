#include <vector>
#include <queue>

using namespace std;

#define NONSET -1

/*
가장 간단하게 생각해볼 수 있는건 
- queue를 돌리면서 연산 시 이미 값이 존재하는 경우라면 pass
- 값이 없는 경우라면 값 설정 후 queue에 삽입
*/
int solution(int storey) {
    int			answer = 0;
    vector<int>	v; // 10의 0제곱부터 1억까지 저장
    vector<int>	dp(100000001, NONSET);
    queue<int>	q;
    int			tmp, calc;
    
    // 0. Init
    	// a. v를 init
    for (size_t i = 1; i <= 100000000; i *= 10) v.push_back(i);
    
    	// b. queue에 0층을 기준으로 삽입
    dp[0] = 0;
    for (size_t i = 0; i < v.size(); i++) {
        dp[v[i]] = 1;
        q.push(v[i]);
    }
    
    // 1. Calculate
    // storey가 나올때까지 반복
    while (1) {
        // a. q의 front를 꺼낸다.
        tmp = q.front();
        q.pop();
        
        // b. q에 새로 삽입한다.
        for (size_t i = 0; i < v.size(); i++) {
            // 1). + version
            calc = tmp + v[i];
            if (calc <= 100000000 && dp[calc] == NONSET) {
                dp[calc] = dp[tmp] + 1;
                q.push(calc);
            }
            // 2). - version
            calc = tmp - v[i];
            if (calc >= 0 && dp[calc] == NONSET) {
                dp[calc] = dp[tmp] + 1;
                q.push(calc);
            }
            // 3). check storey
            if (dp[storey] != NONSET) break ;
        }
        // c. check storey
        if (dp[storey] != NONSET) break ;
    }
    answer = dp[storey];
    
    // 2. Return Answer
    return answer;
}