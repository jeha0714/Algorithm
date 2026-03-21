#include <iostream>
#include <vector>

int main(void) {
    int                 N;
    std::vector<int>    v;
    int                 result;
    std::vector<int>    i_descending;

    // 0. Init
    std::cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++)
        std::cin >> v[i];
        
    // 1. Calculate
    result = 0;

    for (int i = 1, tmp = 0; i < N; i++) {
        if (v[i - 1] > v[i]) {
            i_descending.push_back(i);
        }
    }
    // a. 만약 이전 수보다 큰 index가 2개이상이라면 수 하나만 버려서는 정렬된 배열을 만들 수 없음
    if (i_descending.size() == 0) {
        result = N;
    }
    else if (i_descending.size() == 1) {
        result = 0;
        // 1) i_descending[0] 나를 뺀 경우
        if (i_descending[0] == N - 1)
            result++;
        else if (v[i_descending[0] - 1] <= v[i_descending[0] + 1])
            result++;

        // 2) i_descending[0]의 앞인 나보다 큰 경우를 뺀 경우
        if (i_descending[0] == 1)
            result++;
        else {
            if (v[i_descending[0] - 2] <= v[i_descending[0]])
                result++;
        }
    }

    // 2. Print result
    std::cout << result << "\n";

    return (0);
}