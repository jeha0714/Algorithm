#include <vector>

using namespace std;

#define MOD 1000000007

int solution(int n, vector<int> money) {
    int answer = 0;
    vector<long long>	dp(n + 1, 0);
    
    // 1. Init
    
    // 2. Calculate
    for (int i = 0; i < money.size(); i++) {
        for (int j = 1; j <= n; j++) {
            if (j == money[i])
                dp[j] += 1;
            else if (j - money[i] > 0) {
                dp[j] += dp[j - money[i]];
                dp[j] %= MOD;
            }
        }
    }
    answer = dp[n];
    
    // 3. Return answer
    return answer;
}