#include <iostream>

using namespace std;

int main(void) {
    int N;

    // 0. Init
    cin >> N;

    // 1. Solution
    for (int i = 1; i < N; i++)
        cout << "1 -1 ";
    cout << "-1 1\n";


    return (0);
}