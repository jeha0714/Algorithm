#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int calc_dist(int w, int h, pair<int, int> & main, pair<int, int>  & store) {
    if (main.first == store.first)
        return (abs(main.second - store.second));

    if (main.first == 1) {
        if (store.first == 2)
            return (h + min(main.second + store.second, w - main.second + w - store.second));
        else if (store.first == 3)
            return (main.second + store.second);
        else if (store.first == 4)
            return (w - main.second + store.second);
    }
    else if (main.first == 2) {
        if (store.first == 1)
            return (h + min(main.second + store.second, w - main.second + w - store.second));
        else if (store.first == 3)
            return (main.second + h - store.second);
        else if (store.first == 4)
            return (w - main.second + h - store.second);
    }
    else if (main.first == 3) {
        if (store.first == 1)
            return (main.second + store.second);
        else if (store.first == 2)
            return (h - main.second + store.second);
        else if (store.first == 4)
            return (w + min(main.second + store.second, h - main.second + h - store.second));
    }
    else { // main.first == 4
        if (store.first == 1)
            return (main.second + w - store.second);
        else if (store.first == 2)
            return (h - main.second + w - store.second);
        else if (store.first == 3)
            return (w + min(main.second + store.second, h - main.second + h - store.second));
    }
    return (-1);
}

int main(void) {
    int width, height, n_store;
    vector<pair<int, int> > loc_store;
    pair<int, int>          loc_main;
    int                     total;

    // 0. Init
    cin >> width >> height >> n_store;
    for (int i = 0; i < n_store; i++) {
        cin >> loc_main.first >> loc_main.second;
        loc_store.push_back(loc_main);
    }
    cin >> loc_main.first >> loc_main.second;
    total = 0;

    // 1. Calculate distance
    for (int i = 0; i < loc_store.size(); i++) {
        total += calc_dist(width, height, loc_main, loc_store[i]);
    }

    // 2. Print result
    cout << total << "\n";

    return (0);
}