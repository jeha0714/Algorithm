#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void) {
    int w, h, n_store;
    pair<int, int>  tmp;
    vector<int>     loc;
    int             standard;
    int             total;

    // 0. Init
    cin >> w >> h >> n_store;
    for (int i = 0; i < n_store; i++) {
        cin >> tmp.first >> tmp.second;
        if (tmp.first == 1) loc.push_back(tmp.second);
        else if (tmp.first == 4) loc.push_back(w + tmp.second);
        else if (tmp.first == 2) loc.push_back(2 * w + h - tmp.second);
        else loc.push_back(2 * (w + h) - tmp.second);
    }
    cin >> tmp.first >> tmp.second;
    if (tmp.first == 1) standard = tmp.second;
    else if (tmp.first == 4) standard = w + tmp.second;
    else if (tmp.first == 2) standard = 2 * w + h - tmp.second;
    else standard = 2 * (w + h) - tmp.second;
    total = 0;

    // 1. Calculate distance
    for (int i = 0; i < loc.size(); i++) {
        if (standard < loc[i])
            total += min(abs(standard - loc[i]), standard + 2 * (w + h) - loc[i]);
        else
            total += min(abs(standard - loc[i]), loc[i] + 2 * (w + h) - standard);
    }

    // 2. Print result
    cout << total << "\n";

    return (0);
}