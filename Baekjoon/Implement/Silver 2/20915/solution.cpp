#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
    int         T;
    vector<int> num;
    string      tmp;
    long long   num1, num2, result;

    cin >> T;
    for (int test_case = 0; test_case < T; test_case++) {
        // 0. Init
        cin >> tmp;
        num.clear();
        for (int i = 0; i < tmp.length(); i++) {
            if (tmp[i] == '6')
                num.push_back(9);
            else
                num.push_back(tmp[i] - '0');
        }
        sort(num.begin(), num.end(), greater<int>());
        result = 0;

        // 1. Calculate : 모든 경우의 수 파악 
        for (long long mask = 1 ; mask <= (1 << tmp.length()) - 1; mask++) {
            num1 = 0;
            num2 = 0;
            for (long long i = tmp.length() - 1; i >= 0; i--) {
                if (mask & (1 << i))
                    num1 = num1 * 10 + num[tmp.length() - 1 - i];
                else
                    num2 = num2 * 10 + num[tmp.length() - 1 - i];
            }
            result = max(result, num1 * num2);
        }

        // 2. Print result
        cout << result << "\n";
    }
    return (0);
}