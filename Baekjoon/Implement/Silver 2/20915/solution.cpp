#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
    int T;

    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int n = s.length();

        // 6을 9로 변환 후 내림차순 정렬
        for (int i = 0; i < n; i++) {
            if (s[i] == '6') s[i] = '9';
        }
        sort(s.begin(), s.end(), greater<char>());

        // 비트마스크로 모든 분할 시도
        long long ans = 0;
        for (int mask = 1; mask < (1 << n) - 1; mask++) {
            long long a = 0, b = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i))
                    a = a * 10 + (s[i] - '0');
                else
                    b = b * 10 + (s[i] - '0');
            }
            ans = max(ans, a * b);
        }

        cout << ans << "\n";
    }
    return (0);
}