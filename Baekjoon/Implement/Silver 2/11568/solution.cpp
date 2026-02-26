#include <iostream>
#include <vector>

using namespace std;

int bns(int s, int e, int comp, vector<int> & ascending) {
    int m = (s + e) / 2;

    if (s > e)
        return (s);

    if (comp <= ascending[m]) {
        return (bns(s, m - 1, comp, ascending));
    }
    else {  // ascending[m] < comp
        return (bns(m + 1, e, comp, ascending));
    }
}

int main(void) {
    int         N;
    vector<int> v;
    vector<int> ascending;

    // 0. Init
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];
    
    // 1. Find most long length
    ascending.push_back(v[0]);
    for (int i = 1; i < N; i++) {
        if (ascending[ascending.size() - 1] < v[i])
            ascending.push_back(v[i]);
        else
            ascending[bns(0, ascending.size() - 1, v[i], ascending)] = v[i];
    }

    // 2. Print result
    cout << ascending.size() << "\n";

    return (0);
}