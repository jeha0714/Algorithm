#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int N, M;
    vector<long long> v;
    int r, l;
    int result;

    // 0. Init
    cin >> N >> M;
    v.resize(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];
    sort(v.begin(), v.end(), greater<long long>());
    l = 0;
    r = N - 1;
    result = 0;

    // 1. Greedy
    while (l < r) {
        if (v[l] + v[r] >= M) {
            l++;
            r--;
            result++;
        }
        else {
            r--;
        }
    }

    // 2. Print result
    cout << result << "\n";

    return (0);
}