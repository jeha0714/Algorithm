#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// #define MAXK 1000000000000000000

int main(void) {
    long long           k;
    int                 num_swap;
    vector<long long>   v_power_of_two;
    long long           i;

    // 0. Init
    cin >> k;
    num_swap = 0;
    for (i = 1; i < k; i *= 2) {
        v_power_of_two.push_back(i);
    }
    v_power_of_two.push_back(i);

    // 1. Calculate result
    while (k != 1) {
        i = 0;
        while (k > v_power_of_two[i])
            i++;
        if (i % 2 == 1)
            num_swap++;
        k = (1 + v_power_of_two[i] - k);
    }

    // 2. Print result
    if (num_swap % 2 == 0)
        cout << 0;
    else
        cout << 1;

    return (0);
}