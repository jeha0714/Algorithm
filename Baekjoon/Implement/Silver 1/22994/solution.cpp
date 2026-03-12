#include <iostream>
#include <vector>
#include <string>

using namespace std;

int find_max_n(vector<vector<int> > & dup_row) {

    for (int n = 1000; ; n--) {
        for (int r = 0; r < dup_row.size(); r++) {
            for (int c = 0; c < dup_row[r].size(); c++) {
                if (dup_row[r][c] % n != 0) {
                    n--;
                    r = 0;
                    c = -1;
                    continue;
                }
            }
        }
        return (n);
    }
}
int find_max_m(vector<vector<int> > & dup_col) {
    int flag = 1;

    for (int m = 1000; ; m--) {
        for (int r = 0; r < dup_col.size(); r++) {
            for (int c = 0; c < dup_col[r].size(); c++) {
                if (dup_col[r][c] % m != 0) {
                    m--;
                    r = 0;
                    c = -1;
                    continue;
                }
            }
        }
        return (m);
    }
}


int main(void) {
    int ni, mj;
    vector<string>          extend_img;
    vector<vector<int> >    dup_row;
    vector<vector<int> >    dup_col;
    int                     i, j, tmp;
    int                     n, m;
    vector<vector<char> >   ori_img;

    // 0. Init
    cin >> ni >> mj;
    extend_img.resize(ni);
    for (int i = 0; i < ni; i++) {
        cin >> extend_img[i];
    }

    // 1. Calculate
    dup_row.resize(mj);
    for (j = 0; j < mj; j++) {
        tmp = 0;
        for (i = 1; i < ni; i++) {
            if (extend_img[tmp][j] != extend_img[i][j]) {
                dup_row[j].push_back(i - tmp);
                tmp = i;
            }
        }
        dup_row[j].push_back(i - tmp);
    }
    n = find_max_n(dup_row);

    dup_col.resize(ni);
    for (i = 0; i < ni; i++) {
        tmp = 0;
        for (j = 1; j < mj; j++) {
            if (extend_img[i][tmp] != extend_img[i][j]) {
                dup_col[i].push_back(j - tmp);
                tmp = j;
            }
        }
        dup_col[i].push_back(j - tmp);
    }
    m = find_max_m(dup_col);

    // 2. Copy
    ori_img.resize(ni / n);
    for (i = 0; i < ni / n; i++) {
        ori_img[i].resize(mj / m);
        for (j = 0; j < mj / m; j++) {
            ori_img[i][j] = extend_img[i * n][j * m];
        }
    }

    // 3. Print result
    cout << ni / n << " " << mj / m << "\n";
    for (i = 0; i < ni / n; i++) {
        for (j = 0; j < mj / m; j++) {
            cout << ori_img[i][j];
        }
        cout << "\n";
    }

    return (0);
}