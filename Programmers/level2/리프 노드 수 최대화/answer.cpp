#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int dist_limit, int split_limit) {
    long long answer = 1;  // 최소: 루트의 자식 리프 1개

    long long pow2 = 1;
    for (int a = 0; pow2 <= (long long)split_limit; a++) {
        long long pow3 = 1;
        for (int b = 0; pow2 * pow3 <= (long long)split_limit; b++) {
            long long n = pow2 * pow3;
            // dist_full(a, b) = (2^a - 1) + 2^a * (3^b - 1) / 2
            long long dist_inner = (pow2 - 1) + pow2 * (pow3 - 1) / 2;

            if (dist_inner <= (long long)dist_limit) {
                // 후보 1: 완전 확장으로 끝 → 리프 n개
                answer = max(answer, n);

                long long B = (long long)dist_limit - dist_inner;

                // 후보 2, 3: c_last ∈ {2, 3}로 마지막 한 스테이지 부분 확장
                for (int c_last : {2, 3}) {
                    if (n * (long long)c_last > (long long)split_limit) continue;
                    long long e = min(n, B);
                    answer = max(answer, n + e * (long long)(c_last - 1));
                }
            }

            if (pow3 > (long long)split_limit / 3) break;
            pow3 *= 3;
        }

        if (pow2 > (long long)split_limit / 2) break;
        pow2 *= 2;
    }

    return (int)answer;
}
