#include <iostream>
#include <string>
#include <bitset>

using namespace std;

enum {
    UNUSED,
    USED
};

/*
Backtracking 함수
    // i_cur : 현재 자릿수에 해당하는 N의 index
    // N : input N
    // num_set : 사용한 수인지 판별할 수 있는 정보
*/
long long search_min_diff(long long calculating, int i_cur, string & N, long long num_N, bitset<10> num_set) {
    long long  calculated = 0, tmp = 0;

    if (i_cur == N.length() || i_cur >= 10) {
        return (calculating);
    }
    
    for (int i = 0; i <= 9; i++) {
        if (num_set[i] == UNUSED) {
            num_set[i] = USED;
            if (calculated == 0) {
                calculated = search_min_diff(calculating * 10 + i, i_cur + 1, N, num_N, num_set);
            }
            else {
                tmp = search_min_diff(calculating * 10 + i, i_cur + 1, N, num_N, num_set);
                if (abs(num_N - calculated) > abs(num_N - tmp))
                    calculated = tmp;
                else if (abs(num_N - calculated) == abs(num_N - tmp)) {
                    calculated = calculated < tmp ? calculated : tmp;
                }
            }
            num_set[i] = UNUSED;
        }
    }
    
    return (calculated);
}

int main(void) {
    string      N;
    long long   result;
    bitset<10>  num_set(UNUSED);

    // 0. Init
    cin >> N;
        // a. Early stop case
    if (stoll(N) >= 9876543210) {
        cout << 9876543210 << "\n";
        return (0);
    }

    // 1. Calculate
    result = search_min_diff(0, 0, N, stoll(N), num_set);

    // 2. Print result
    cout << result << "\n";

    return (0);
}