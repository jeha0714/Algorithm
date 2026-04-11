#include <iostream>
#include <vector>

int main(void) {
    int K, a, b, x, y;
    std::vector<std::vector<int> >  v1 = {{1, 1}, {1, 1}};
    std::vector<std::vector<int> >  v2 = {
        {-1, 1, 2, 2},
        {1, 1, 3, 2},
        {4, 3, 3, 5},
        {4, 4, 5, 5}
    };
    std::vector<std::vector<int> >  v3 = {
        {1, -1, 2, 2},
        {1, 1, 3, 2},
        {4, 3, 3, 5},
        {4, 4, 5, 5}
    };
    std::vector<std::vector<int> >  v4 = {
        {1, 1, 2, 2},
        {1, -1, 3, 2},
        {4, 3, 3, 5},
        {4, 4, 5, 5}
    };
    std::vector<std::vector<int> >  v5 = {
        {1, 1, 2, 2},
        {-1, 1, 3, 2},
        {4, 3, 3, 5},
        {4, 4, 5, 5}
    };
    std::vector<std::vector<int> >  v_type;
    int                             order_type;

    // 0. Init
    std::cin >> K >> a >> b;
    x = K * 2 - b;
    y = a - 1;

    // 1. Calculate
    if (K == 1) {
        v1[x][y] = -1;
    }
    else {
        if ((x == 0 && y == 0) || (x == 0 && y == 3) || (x == 3 && y == 3) || (x == 3 && y == 0)) {
            v_type = v2;
        }
        else if ((x == 0 && y == 1) || (x == 1 && y == 3) || (x == 3 && y == 2) || (x == 2 && y == 0)) {
            v_type = v3;
        }
        else if ((x == 1 && y == 1) || (x == 1 && y == 2) || (x == 2 && y == 2) || (x == 2 && y == 1)) {
            v_type = v4;
        }
        else if ((x == 1 && y == 0) || (x == 0 && y == 2) || (x == 2 && y == 3) || (x == 3 && y == 1)) {
            v_type = v5;
        }
        if (x <= 1 && y <= 1)
            order_type = 1;
        else if (x <= 1 && y <= 3)
            order_type = 2;
        else if (x <= 3 && y <= 1)
            order_type = 4;
        else
            order_type = 3;
    }

    // 2. Print result
    if (K == 1) {
        for (int r = 0; r < 2 * K; r++) {
            for (int c = 0; c < 2 * K; c++) {
                std::cout << v1[r][c] << " ";
            }
            std::cout << "\n";
        }
    }
    else {
        if (order_type == 1) {
            for (int r = 0; r < 2 * K; r++) {
                for (int c = 0; c < 2 * K; c++) {
                    std::cout << v_type[r][c] << " ";
                }
                std::cout << "\n";
            }
        }
        else if (order_type == 2) {
            for (int c = 0; c < 2 * K; c++) {
                for (int r = 2 * K - 1; r >= 0; r--) {
                    std::cout << v_type[r][c] << " ";
                }
                std::cout << "\n";
            }
        }
        else if (order_type == 3) {
            for (int r = 2 * K - 1; r >= 0; r--) {
                for (int c = 2 * K - 1; c >= 0; c--) {
                    std::cout << v_type[r][c] << " ";
                }
                std::cout << "\n";
            }
        }
        else if (order_type == 4) {
            for (int c = 2 * K - 1; c >= 0; c--) {
                for (int r = 0; r < 2 * K; r++) {
                    std::cout << v_type[r][c] << " ";
                }
                std::cout << "\n";
            }
        }
    }

    return (0);
}