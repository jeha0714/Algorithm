#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

int main(void) {
    int n;
    vector<int> amount_wine;
    vector<array<int, 3> > dp;
    int max_amount;

    // 0. Init
    cin >> n;
    amount_wine.resize(n);
    dp.resize(n);
    for (int i = 0; i < n; i++)
        cin >> amount_wine[i];
    dp[0][0] = 0;
    dp[0][1] = amount_wine[0];
    dp[0][2] = 0;
    max_amount = max({dp[0][0], dp[0][1], dp[0][2]});

    // 1. Calculate
    for (int cur = 1; cur < n; cur++) {
        // a. Non-select cur wine
        dp[cur][0] = max({dp[cur - 1][0], dp[cur - 1][1], dp[cur - 1][2]});

        // b. Select cur wine with first successive
        dp[cur][1] = dp[cur - 1][0] + amount_wine[cur];

        // c. Select cur wine with second successive
        dp[cur][2] = dp[cur - 1][1] + amount_wine[cur];
    }
    max_amount = max({max_amount, dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});

    // 2. Print result
    cout << max_amount << "\n";

    return (0);
}