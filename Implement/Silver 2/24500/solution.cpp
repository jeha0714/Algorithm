#include <iostream>
#include <stack>
#include <bitset>

using namespace std;

int main(void) {
    long long           N;
    stack<long long>    st;
    bitset<64>          bt;
    long long           other;

    // 0. Init
    cin >> N;
    bt = N;
    st.push(N);
    other = 0;

    // 1. Find K
    for (long long i = 0, tmp = 1; i <= 63 && N >= tmp; i++, tmp = (tmp << 1)) {
        if (bt[i] == 0)
            other += tmp;
    }
    if (other != 0)
        st.push(other);

    // 2. Print result
    cout << st.size() << "\n";
    while (!st.empty()) {
        cout << st.top() << "\n";
        st.pop();
    }

    return (0);
}