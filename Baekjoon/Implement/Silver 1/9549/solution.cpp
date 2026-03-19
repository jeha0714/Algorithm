#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <bitset>

using namespace std;

#define RANGE ('z' - 'a' + 1)

/*
사이에 뭐도 없어야 하는거 아닌가?
-> 이걸 어떻게 판별 할 것이냐?
= 다 붙어 있으면 됨.
-> 순서관계 없이 다 붙어있는지 확인해야함.
=> two pointer로 옮겨다니면서 확인하면 될듯!
*/
int main(void) {
    int T;
    string ori, rev;
    vector<int> v_ori(RANGE, 0), v_rev(RANGE, 0);
    bitset<RANGE>   same;
    int l, r;
    long long i, j;

    cin >> T;

    for (int test_case = 1; test_case <= T; test_case++) {
        // 0. Init
        cin >> rev >> ori;
        memset(v_ori.data(), 0, v_ori.size() * sizeof(v_ori[0]));
        memset(v_rev.data(), 0, v_rev.size() * sizeof(v_rev[0]));
        for (i = 0; i < ori.length(); i++)
            v_ori[ori[i] - 'a']++;
        same = 0;
        for (i = 0; i < RANGE; i++) {
            if (v_ori[i] != 0)
                same[i] = 1;
        }

        // 1. Calculate
        for (l = 0, r = 0; same.count() && r < rev.length() ; r++) {
            // r 포함시키기
            i = rev[r] - 'a';
            v_rev[i]++;

            // a. r 포함시킨 후 v_rev[r] 값이 v_ori[r] 값보다 작다면 r 계속 이동
            if (v_rev[i] <= v_ori[i]) {
                if (v_rev[i] == v_ori[i])
                    same[i] = 0;
                continue ;
            }
            // b. r 포함시킨 후 v_rev[r] 값이 v_ori[r] 값과 크다면 같아질때까지 l이동
            else {
                for (; v_rev[i] != v_ori[i]; l++) {
                    j = rev[l] - 'a';
                    v_rev[j]--;
                    if (v_rev[j] != v_ori[j])
                        same[j] = 1;
                }
                same[i] = 0;
            }
        }

        // 2. Print result
        if (!same.count())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return (0);
}