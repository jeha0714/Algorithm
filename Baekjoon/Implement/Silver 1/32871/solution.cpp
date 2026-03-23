#include <iostream>

int main(void) {
    std::ios::sync_with_stdio(false);                                             
    std::cin.tie(NULL);   

    int T;
    long long   n, m;

    std::cin >> T;
    for (int cur_t = 1; cur_t <= T; cur_t++) {
        std::cin >> n >> m;

        if (n == 1 || m == 1)
            std::cout << "YES\n";
        else {
            if (abs(n - m) % 2 == 0)
                std::cout << "NO\n";
            else
                std::cout << "YES\n";
        }
    }

    return (0);
}