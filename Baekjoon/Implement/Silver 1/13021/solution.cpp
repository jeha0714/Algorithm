#include <iostream>
#include <vector>
#include <bitset>

int main(void) {
    int N, M;
    unsigned long long  result;
    std::vector<int>    balls(1001, 0);
    std::bitset<1001>   bs;

    // 0. Init
    std::cin >> N >> M;
    for (int i = 1, s, e; i <= M; i++) {
        std::cin >> s >> e;

        for (int j = s; j <= e; j++)
            balls[j] = i;
    }
    result = 0;

    // 1. Calculate
    for (int i = 1; i <= N; i++) {
        bs[balls[i]] = 1;
    }
    for (int i = 1; i <= M; i++) {
        if (bs[i])
            result++;
    }
    result = 1ULL << result;

    // 2. Print result
    std::cout << result <<"\n";

    return (0);
}