#include <iostream>
#include <algorithm>
#include <vector>

bool compare(std::vector<int> & a, std::vector<int> & b) {
    if (a[1] == b[1]) {
        return (a[0] < b[0]);
    }
    return (a[1] < b[1]);
}

int main(void) {
    int n;    
    std::vector<std::vector<int> > v;
    long long   total;

    // 0. Init
    std::cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        v[i].resize(2);
        std::cin >> v[i][0];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> v[i][1];
    }
    total = 0;

    // 1. Solve
    std::sort(v.begin(), v.end(), compare);
    for (int i = 0; i < n; i++) {
        total += (v[i][0] + v[i][1] * i);
    }

   // 2. Output 
   std::cout << total << "\n";

    return (0);
}