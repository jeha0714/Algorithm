#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>

using namespace std;

int main(void) {
    int k, S;
    vector<int> weight;
    vector<int> masks;
    bitset<2600001> number_of_cases; 
    int left, right;
    int total_case;
    int result;

    // 1. Init
    cin >> k;
    S = 0;
    weight.resize(k);
    masks.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> weight[i];
        S += weight[i];
        masks[i] = 0;
    }

    // 2. Calcualte
    total_case = pow(3, k);
    for (int cur = 1; cur <= total_case; cur++) {
        // 1. First calculate current set
        left = 0;
        right = 0;
            // a) masks[i] == 0 -> non used
            // b) masks[i] == 1 -> left with water
            // c) masks[i] == 2 -> right
        for (int i = 0; i < k; i++) {
            if (masks[i] == 1) left += weight[i];
            else if (masks[i] == 2) right += weight[i];
        }

        // 2. update number_of_cases
        if (right - left > 0)
            number_of_cases[right - left] = 1;
        
        // 3. Add + 1
        masks[0]++;
        for (int i = 0; i < k; i++) {
            if (masks[i] == 3) {
                masks[i] = 0;
                masks[i + 1]++;
            }
            else
                break ;
        }
    }

    // 3. Print result
    result = 0;
    for (int i = 1; i <= S; i++) {
        if (!number_of_cases[i])
            result++;
    }
    cout << result << "\n";

    return (0);
}