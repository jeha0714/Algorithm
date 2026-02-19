#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;


int main(void) {
    double         N, L, Q;
    vector<double> len_tab;
    vector<double> loc_center;
    double         cur_len, total_len = 0;
    int num_click_tab;

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    // 0. Init
    cin >> N;
    len_tab.resize(N);
    loc_center.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> len_tab[i];
        total_len += len_tab[i];
    }
    cin >> L >> Q;
    cur_len = 0;

    // 2. Calculate and Print result
    for (int i = 0; i < N; i++) {
        if (cur_len + len_tab[i] / 2 < L / 2 
            || total_len < L) {
            loc_center[i] = 0.0;
        }
        else if (total_len - cur_len - len_tab[i] / 2 < L / 2) {
            loc_center[i] = total_len - L;
        }
        else {
            loc_center[i] = cur_len - L / 2 + len_tab[i] / 2;
        }
        cur_len += len_tab[i];
    }

    // 3. Print result
    for (int i = 0; i < Q; i++) {
        cin >> num_click_tab;
        cout << std::fixed << std::setprecision(2) << loc_center[num_click_tab - 1] << "\n";
    }

    return (0);
}