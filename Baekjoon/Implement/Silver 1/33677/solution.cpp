#include <iostream>
#include <vector>
#include <queue>

#define INFINITE 2147483647

void give1(int cur, std::vector<std::vector<int> > & dp, std::queue<int> & q) {
    if (cur + 1 < dp[0].size()) {
        if (dp[0][cur + 1] == INFINITE) {
            dp[0][cur + 1] = dp[0][cur] + 1;
            dp[1][cur + 1] = dp[1][cur] + 1;
            q.push(cur + 1);
        }
        else if (dp[0][cur] + 1 < dp[0][cur + 1]) {
            dp[0][cur + 1] = dp[0][cur] + 1;
            dp[1][cur + 1] = dp[1][cur] + 1;
            q.push(cur + 1);
        }
        else if (dp[0][cur] + 1 == dp[0][cur + 1] && dp[1][cur] + 1 < dp[1][cur + 1]) {
            dp[1][cur + 1] = dp[1][cur] + 1;
            q.push(cur + 1);
        }
    }
}

void give3(int cur, std::vector<std::vector<int> > & dp, std::queue<int> & q) {
    if (cur * 3 < dp[0].size()) {
        if (dp[0][cur * 3] == INFINITE) {
            dp[0][cur * 3] = dp[0][cur] + 1;
            dp[1][cur * 3] = dp[1][cur] + 3;
            q.push(cur * 3);
        }
        else if (dp[0][cur] + 1 < dp[0][cur * 3]) {
            dp[0][cur * 3] = dp[0][cur] + 1;
            dp[1][cur * 3] = dp[1][cur] + 3;
            q.push(cur * 3);
        }
        else if (dp[0][cur] + 1 == dp[0][cur * 3] && dp[1][cur] + 3 < dp[1][cur * 3]) {
            dp[1][cur * 3] = dp[1][cur] + 3;
            q.push(cur * 3);
        }
    }
}

void give5(int cur, std::vector<std::vector<int> > & dp, std::queue<int> & q) {
    if (((long long)cur) * cur < dp[0].size()) {
        if (dp[0][cur * cur] == INFINITE) {
            dp[0][cur * cur] = dp[0][cur] + 1;
            dp[1][cur * cur] = dp[1][cur] + 5;
            q.push(cur * cur);
        }
        else if (dp[0][cur] + 1 < dp[0][cur * cur]) {
            dp[0][cur * cur] = dp[0][cur] + 1;
            dp[1][cur * cur] = dp[1][cur] + 5;
            q.push(cur * cur);
        }
        else if (dp[0][cur] + 1 == dp[0][cur * cur] && dp[1][cur] + 5 < dp[1][cur * cur]) {
            dp[1][cur * cur] = dp[1][cur] + 5;
            q.push(cur * cur);
        }
    }
}


int main(void) {
    int N;
    std::vector<std::vector<int> >  dp;
    std::queue<int>                 q;
    int                             cur;

    // 0. Init
    std::cin >> N;
    dp.resize(2);
    dp[0].resize(N + 1);
    dp[1].resize(N + 1);
    dp[0][0] = 0;
    dp[1][0] = 0;
    for (int i = 1; i <= N; i++) {
        dp[0][i] = INFINITE;
        dp[1][i] = INFINITE;
    }
    q.push(0);

    // 1. Calculate
    while (!q.empty()) {
        cur = q.front();
        q.pop();

        give1(cur, dp, q);
        give3(cur, dp, q);
        give5(cur, dp, q);
    }

    // 2. Print result
    std::cout << dp[0][N] << " " << dp[1][N] << "\n";


    return (0);
}