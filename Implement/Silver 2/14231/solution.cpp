#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int                     n; // # of box
    vector<int>             size_box;
    vector<vector<int> >    dp; // [i][0]는 자신을 포함한 최대값, [i][1]은 자신을 포함하지 않았을 때 최대값

    // 0. Init input
    cin >> n;
    size_box.resize(n);
    dp.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> size_box[i];
        dp[i].resize(2);
    }

    // 1. Calculate
    dp[0][0] = 1;
    dp[0][1] = 0;
    for (int i = 1; i < n; i++) {
        dp[i][0] = 1;
        dp[i][1] = 0;
        // a. set dp[i][0]
        for (int j = i - 1; j >= 0; j--) {
            if (size_box[i] > size_box[j]) {
                if (dp[i][0] < dp[j][0] + 1)
                    dp[i][0] = dp[j][0] + 1;
            }
        }

        // b. set dp[i][1]
        for (int j = i - 1; j >= 0; j--) {
            if (dp[i][1] < dp[j][0])
                dp[i][1] = dp[j][0];
            if (dp[i][1] < dp[j][1])
                dp[i][1] = dp[j][1];
        }
    }

    // 2. Print result
    if (dp[n - 1][0] > dp[n - 1][1])
        cout << dp[n - 1][0] << "\n";
    else
        cout << dp[n - 1][1] << "\n";

    return (0);
}