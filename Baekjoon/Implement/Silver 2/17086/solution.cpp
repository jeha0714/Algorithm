#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int calc_safe_dist(int empty_r, int empty_c, int shark_r, int shark_c) {
    int safe_dist = 0;

    if(abs(empty_r - shark_r) < abs(empty_c - shark_c)) {
        safe_dist += abs(empty_r - shark_r);
        safe_dist += (abs(empty_c - shark_c) - safe_dist);
    }
    else {
        safe_dist += abs(empty_c - shark_c);
        safe_dist += (abs(empty_r - shark_r) - safe_dist);
    }
    
    return (safe_dist);
}

int main(void) {
    int                     N, M;
    vector<vector<int> >    space;
    vector<pair<int, int> > sharks;
    int                     cur_safe_dist, max_safe_dist;
    
    // 0. Init
    cin >> N >> M;
    space.resize(N);
    for (int r = 0; r < N; r++) {
        space[r].resize(M);
        for (int c = 0; c < M; c++) {
            cin >> space[r][c];
            if (space[r][c] == 1)
            sharks.push_back(make_pair(r, c));
        }
    }
    max_safe_dist = 0;
    
    // 1. Calcuate max_safe_dist
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (space[r][c] == 0) {
                cur_safe_dist = 2147483647;
                for (int ith = 0; ith < sharks.size(); ith++) {
                    cur_safe_dist = min(cur_safe_dist, calc_safe_dist(r, c, sharks[ith].first, sharks[ith].second));
                }
                max_safe_dist = max(max_safe_dist, cur_safe_dist);
            }
        }
    }

    // 2. Print result
    cout << max_safe_dist << "\n";

    return (0);
}