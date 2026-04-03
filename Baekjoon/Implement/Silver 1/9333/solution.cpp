#include <iostream>

int main(void) {
    int         total_testcase;
    long long   input[3][2];
    int         month;
    char        c;
    long long   R, B, M, before;

    std::cin >> total_testcase;
    for (int cur_testcase = 0; cur_testcase < total_testcase; cur_testcase++) {
        // 0. Init
        for (int i = 0; i < 3; i++) {
            input[i][0] = 0;
            while(1) {
                std::cin >> c;
                if (c == '.')
                    break;
                input[i][0] *= 10;
                input[i][0] += (c - '0');
            }

            input[i][1] = 0;
            for (int j = 0; j < 2; j++) {
                std::cin >> c;
                input[i][1] *= 10;
                input[i][1] += (c - '0');
            }
        }

        // 1. Calculate
        for (month = 1; month <= 1200; month++) {
            // a. interest
            R = 10000 + input[0][0] * 100 + input[0][1];
            B = input[1][0] * 100 + input[1][1];
            B *= R;
            if (B % 10000 >= 5000) {
                B += 10000;
            }
            input[1][0] = B / 1000000;
            B %= 1000000;
            input[1][1] = B / 10000;

            // b. pay
            B = input[1][0] * 100 + input[1][1];
            M = input[2][0] * 100 + input[2][1];
            B -= M;
            if (B <= 0)
                break;
            else if (month != 1 && before <= B) {
                month = 1201;
                break ;
            }
            else {
                before = B;
                input[1][0] = B / 100;
                input[1][1] = B % 100;
            }
        }

        // 2. Print result
        if (month > 1200)
            std::cout << "impossible\n";
        else
            std::cout << month << "\n";
    }

    return (0);
}