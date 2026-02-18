#include <iostream>
#include <unordered_set>
#include <cmath>

using namespace std;

int main(void) {
    int                 N, M;
    unordered_set<int>  S;
    int                 tmp;
    int                 x, y, z;
    int                 bef, cur;
    int                 result;

    // 0. Init input
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> tmp;
        S.insert(tmp);
    }
    result = 2147483647;

    // 1. Calculate
    for (x = 1; x <= 1001; x++) {
        if (S.find(x) != S.end())
            continue ;
        for (y = 1; y <= 1001; y++) {
            if (S.find(y) != S.end())
                continue ;
            for (z = 1; z <= 1001; z++) {
                if (S.find(z) != S.end())
                    continue ;
                if (result > abs(N - x * y * z))
                    result = abs(N - x * y * z);
                if (abs(N - x * y * z) < abs(N - x * y * (z + 1)))
                    break ;
            }
        }
    }

    // 2. Print result
    cout << result << "\n";

    return (0);
}