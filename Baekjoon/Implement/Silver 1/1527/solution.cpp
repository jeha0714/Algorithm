#include <iostream>
#include <string>

using namespace std;

// 현재 num보다 큰 '금민수' 반환
int greater_count(int n_index_len_count[10], string num, int len) {
    if (len == 1) {
        if (num[0] <= '3')
            return (2);
        else if (num[0] <= '6')
            return (1);
        else
            return (0);
    }

    if (num[0] <= '3')
        return (n_index_len_count[len]);
    else if (num[0] == '4') {
        return ((n_index_len_count[len] >> 1) + greater_count(n_index_len_count, num.substr(1, len - 1), len - 1));
    }
    else if (num[0] == '7') {
        return (greater_count(n_index_len_count, num.substr(1, len - 1), len - 1));
    }
    else if ('8' <= num[0]) {
        return (0);
    }
    else { // 5 <= num[0] <= 6
        return (n_index_len_count[len] >> 1);
    }
}

// 현재 num보다 작은 '금민수' 반환
int less_count(int n_index_len_count[10], string num, int len) {
    if (len == 1) {
        if (num[0] <= '4')
            return (0);
        else if (num[0] <= '7')
            return (1);
        else
            return (2);
    }

    if (num[0] <= '3')
        return (0);
    else if (num[0] == '4') {
        return (less_count(n_index_len_count, num.substr(1, len - 1), len - 1));
    }
    else if (num[0] == '7') {
        return ((n_index_len_count[len] >> 1) + less_count(n_index_len_count, num.substr(1, len - 1), len - 1));
    }
    else if ('8' <= num[0]) {
        return (n_index_len_count[len]);
    }
    else { // 5 <= num[0] <= 6
        return (n_index_len_count[len] >> 1);
    }
}

int main(void) {
    string  A, B;
    int     n_index_len_count[10]; // 자릿수별 '금문수' 수
    int     result = 0;

    // 0. Init
    cin >> A >> B;
    n_index_len_count[0] = 1;
    for (int i = 1; i < 10; i++)
        n_index_len_count[i] = n_index_len_count[i - 1] << 1;
    result = 0;

    // 1. Calculate "금민수"
        // a. Add A's length count and B's length count
    for (int i = A.length(); i <= B.length(); i++)
        result += n_index_len_count[i];
        // b. Delete less than A value
    result -= less_count(n_index_len_count, A, A.length());
        // c. Delete greater than B value
    result -= greater_count(n_index_len_count, B, B.length());

    // 2. Print result
    cout << result << "\n";

    return (0);
}