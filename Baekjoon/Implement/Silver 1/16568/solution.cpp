#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
    int N, a, b;
    vector<int> dp(1000002, 2147483647);
    queue<int>  q;
    int cur, next;

    // 0. Init
    cin >> N >> a >> b;
    dp[N + 1] = 0;
    q.push(N + 1);

    // 1. Calculate dp
    while (!q.empty()) {
        // a. 큐의 가장 앞 원소를 빼냄
        cur = q.front();
        q.pop();
        next = cur - 1;

        // b. 기본적으로 한 칸 앞은 가기
        if (next >= 1) {
            // 1) 기다리기
            if (dp[next] > dp[cur] + 1) {
                q.push(next);
                dp[next] = dp[cur] + 1;
            }
            // 2) a 명 앞으로 새치기 하기
            if (next - a >= 1 && dp[next - a] > dp[cur] + 1) {
                q.push(next - a);
                dp[next - a] = dp[cur] + 1;
            }
            // 3) b 명 앞으로 새치기 하기
            if (next - b >= 1 && dp[next - b] > dp[cur] + 1) {
                q.push(next - b);
                dp[next - b] = dp[cur] + 1;
            }
        }
    }

    // 2. Print result
    cout << dp[1] << "\n";

    return (0);
}
