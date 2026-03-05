#include <iostream>

#define MOD 1000000009

using namespace std;

// f(n) = f(n - 1) + f(n - 3)
int main(void) {
    int n;
    int result[50001];

    // 0. Init
    cin >> n;
    result[1] = 1;
    result[2] = 1;
    result[3] = 2;

    // 1. Calculate
    for (int i = 4; i <= n; i++)
        result[i] = (result[i - 1] + result[i - 3]) % MOD;

    // 2. Print result
    cout << result[n] << "\n";

    return (0);
}