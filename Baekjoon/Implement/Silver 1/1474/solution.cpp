#include <iostream>
#include <vector>
#include <string>

using namespace std;

// bool    compare(string & a, string & b) {

// }

int main(void) {
    int N, M;
    vector<string>  v_str;
    int     len_max_dash, len_min_dash;
    int     n_max_dash, n_min_dash;
    string  max_dash = "", min_dash = "";
    string  result = "";

    // 0. Init
    cin >> N >> M;
    v_str.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v_str[i];
        M -= v_str[i].length();
    }
    len_min_dash = M / (N - 1);
    if (M % (N - 1) == 0)
        len_max_dash = len_min_dash;
    else
        len_max_dash = len_min_dash + 1;
    n_max_dash = M % (N - 1);
    n_min_dash = N - 1 - n_max_dash;
    for (int i = 0; i < len_max_dash; i++) max_dash.push_back('_');
    for (int i = 0; i < len_min_dash; i++) min_dash.push_back('_');

    
    // 1. Calculate
    result.append(v_str[0]);
    for (int i = 1; i < N; i++) {
        if ('A' <= v_str[i][0] && v_str[i][0] <= 'Z') {
            if (n_min_dash > 0) {
                result.append(min_dash);
                n_min_dash--;
            }
            else {
                result.append(max_dash);
                n_max_dash--;
            }
        }
        else { // 'a' <= v_str[i][0] && v_str[i][0] <= 'z'
            if (n_max_dash > 0) {
                result.append(max_dash);
                n_max_dash--;
            }
            else {
                result.append(min_dash);
                n_min_dash--;
            }
        }
        result.append(v_str[i]);
    }

    // 2. Print result
    cout << result << "\n";

    return (0);
}