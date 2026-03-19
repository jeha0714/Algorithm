#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

#define RANGE ('z' - 'a' + 1)

int main(void) {
    int T;
    string  s_ori, s_rev;
    vector<int> v_ori(RANGE, 0), v_rev(RANGE, 0);
    int l, r;
    int matched;

    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        cin >> s_rev >> s_ori;

        memset(v_ori.data(), 0, v_ori.size() * sizeof(v_ori[0]));
        memset(v_rev.data(), 0, v_rev.size() * sizeof(v_rev[0]));

        for (int i = 0; i < s_ori.length(); i++) {
            v_ori[s_ori[i] - 'a']++;
        }
        matched = 0;
        for (int i = 0; i < RANGE; i++) {
            if (v_ori[i] == 0) matched++;
        }


        for (r = 0, l = 0; r < s_ori.length(); r++) {
            v_rev[s_rev[r] - 'a']++;
            if (v_rev[s_rev[r] - 'a'] - v_ori[s_rev[r] - 'a'] == 1)
                matched--;
            else if (v_rev[s_rev[r] - 'a'] == v_ori[s_rev[r] - 'a'])
                matched++;
        }
        for (; r < s_rev.length() && matched != RANGE; r++, l++) {
            v_rev[s_rev[r] - 'a']++;
            if (v_rev[s_rev[r] - 'a'] - v_ori[s_rev[r] - 'a'] == 1)
                matched--;
            else if (v_rev[s_rev[r] - 'a'] == v_ori[s_rev[r] - 'a'])
                matched++;

            v_rev[s_rev[l] - 'a']--;
            if (v_rev[s_rev[l] - 'a'] - v_ori[s_rev[l] - 'a'] == -1)
                matched--;
            else if (v_rev[s_rev[l] - 'a'] == v_ori[s_rev[l] - 'a'])
                matched++;
        }

        if (matched == RANGE)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return (0);
}