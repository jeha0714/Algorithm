#include <vector>
#include <cmath>

using namespace std;

/*
브루트포스로 풀면 어떻게 해결이 가능할까
모든 구간을 살펴보겠지?
-> 첫번째 아들의 l(0~2000)과 m(0~2000)을 모두 둘러본 후 
-> 두번째 아들이 m+1에서 값이 같을 때까지 r을 늘려나가는거지. 같은 경우가 없고 늘어난다면 해당 경우는 패스하는거고

------
1차원 벡터 dp 
l = 0일 때 0 ~ end까지 누적합을 구해둔다.
l이 증가할 때마다 이전 l의 위치 값을 빼면 된다
m + 1 ~ r을 구할 때는 매번 구해야 한다 -> l의 값이 매번 다르기에 2000 * 2000을 저장하지 않는 이상 저장해도 사용힘듦
*/

int	bns(const int & cmp, int s, int e, const vector<int> & dp2) {
    int	m = (s + e) / 2;
    
    if (s > e)
        return (e);
    
    if (dp2[m] <= cmp) {
        return (bns(cmp, m + 1, e, dp2));
    }
    else {
        return (bns(cmp, s, m - 1, dp2));
    }
}

int solution(vector<int> cookie) {
    int answer = 0;
    vector<int>	dp(cookie.size(), 0);
    
    // 0. Init
    dp[0] = cookie[0];
    for (int i = 1; i < cookie.size(); i++) {
        dp[i] = dp[i - 1] + cookie[i];
    }
    
    // 1. Calculate
    for (int l = 0, sub, r; l < cookie.size() - 1; l++) {
        r = bns(dp[l], l + 1, cookie.size() - 1, dp);
        if (l != 0)
            sub = dp[l - 1];
        for (int m = l; m < cookie.size() - 1; m++) {
            if (dp[m] <= answer)
                continue ;
            while (r < cookie.size() - 1 && dp[r] - dp[m] < dp[m] - sub)
                r++;
            if (dp[r] - dp[m] == dp[m] - sub) {
                answer = max(answer, dp[r] - dp[m]);
            }
            else if (r == cookie.size() - 1 && dp[r] - dp[m] < dp[m] - sub)
                break ;
        }
    } 
    
    // 2. Return Answer
    return answer;
}