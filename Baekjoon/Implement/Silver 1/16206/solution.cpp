#include <iostream>
#include <vector>
#include <algorithm>

bool    compare(int & a, int & b) {
    if (a % 10 == 0 && b % 10 == 0) {
        return (a < b);
    }
    else if (a % 10 == 0)
        return (true);
    else if (b % 10 == 0)
        return (false);
    else
        return (a < b);
}


int main(void) {
    int N, M;
    std::vector<int>    v;
    int num_remain_nonzero;
    int tmp;
    int result = 0;

    // 0. Init
    std::cin >> N >> M;
    v.resize(N);
    for (int i = 0; i < N; i++)
        std::cin >> v[i];
    std::sort(v.begin(), v.end(), compare);
    num_remain_nonzero = 0;
    
    // 1. Calculate
    for (int i = 0, value; i < N; i++) {
        value = v[i];
        if (M > 0) {
            if (value % 10 == 0) {
                if (value == 10) {
                    result++;
                }
                else {
                    tmp = value / 10;
    
                    if (M >= tmp - 1) {
                        M -= (tmp - 1);
                        result += (tmp);
                    }
                    else {
                        if (tmp == 2)
                            result += (M + 1);
                        else
                            result += M;
                        M = 0;
                    }
                }
            }
            else {
                num_remain_nonzero += value / 10;
            }
        }
    }
    if (M > 0) {
        if (M >= num_remain_nonzero)
            result += num_remain_nonzero;
        else
            result += M;
    }

    // 2. Print result
    std::cout << result << "\n";

    return (0);
}