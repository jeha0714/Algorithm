#include <iostream>
#include <vector>

int calculate(int N, std::vector<std::vector <int> > & l
    , std::vector<std::vector <int> > & r
    , std::vector<std::vector <int> > & u
    , std::vector<std::vector <int> > & B) {

    std::vector<std::vector <int> > cul_A;
    int value = 0;

    cul_A = B;
    for (int i = 0; i < l.size(); i++) {
        for (int j = 0; j < l[i].size(); j++) {
            cul_A[N - 1 - i - j][i] = l[i][j];
        }
    }
    for (int i = 0; i < r.size(); i++) {
        for (int j = 0; j < r[i].size(); j++) {
            cul_A[2 * i + j][i + j] = r[i][j];
        }
    }
    for (int i = 0; i < u.size(); i++) {
        for (int j = 0; j < u[i].size(); j++) {
            cul_A[N - 1 - i][N - 1 - 2 * i - j] = u[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            value += abs(cul_A[i][j] - B[i][j]);
        }
    }

    return (value);
}

void    reverse(std::vector<std::vector <int> > & l
    , std::vector<std::vector <int> > & r
    , std::vector<std::vector <int> > & u) {

    std::vector<std::vector <int> > tmp;

    tmp = l;
    for (int i = 0; i < l.size(); i++) {
        for (int j = 0; j < l[i].size(); j++) {
            l[i][j] = r[i][r[i].size() - 1 - j];
        }
    }
    for (int i = 0; i < r.size(); i++) {
        for (int j = 0; j < r[i].size(); j++) {
            r[i][j] = tmp[i][tmp[i].size() - 1 - j];
        }
    }

    tmp = u;
    for (int i = 0; i < u.size(); i++) {
        for (int j = 0; j < u[i].size(); j++) {
            u[i][j] = tmp[i][tmp[i].size() - 1 - j];
        }
    }
}

void    rotate(std::vector<std::vector <int> > & l
    , std::vector<std::vector <int> > & r
    , std::vector<std::vector <int> > & u) {
    
    std::vector<std::vector <int> > tmp;

    tmp = l;
    l = u;
    u = r;
    //r = tmp;
    for (int i = 0; i < r.size(); i++) {
        for (int j = 0; j < r[i].size(); j++) {
            r[i][j] = tmp[i][j];
        }
    }
}

int main(void) {
    int N;
    std::vector<std::vector <int> >   A, B;
    std::vector<std::vector <int> >   l, r, u; // left, right, under triangle
    int min;

    // 0. Init
    std::cin >> N;
    A.resize(N);
    for (int r = 0; r < N; r++) {
        A[r].resize(r + 1);
        for (int c = 0; c <= r; c++)
            std::cin >> A[r][c];
    }
    B.resize(N);
    for (int r = 0; r < N; r++) {
        B[r].resize(r + 1);
        for (int c = 0; c <= r; c++)
            std::cin >> B[r][c];
    }
    if (N % 3 == 0) {
        l.resize(N / 3);
        r.resize(N / 3);
        u.resize(N / 3);
    }
    else {
        l.resize(N / 3 + 1);
        r.resize(N / 3 + 1);
        u.resize(N / 3 + 1);
    }
    for (int i = 0; i < l.size(); i++) {
        l[i].resize(N - i * 3);
        for (int j = 0; j < l[i].size(); j++) {
            l[i][j] = A[N - 1 - i - j][i];
        }
    }
    for (int i = 0; i < r.size(); i++) {
        r[i].resize(N - i * 3);
        for (int j = 0; j < r[i].size(); j++) {
            r[i][j] = A[2 * i + j][i + j];
        }
    }
    for (int i = 0; i < u.size(); i++) {
        u[i].resize(N - i * 3);
        for (int j = 0; j < u[i].size(); j++) {
            u[i][j] = A[N - 1 - i][N - 1 - 2 * i - j];
        }
    }
    min = 2147483647;

    // 1. Calculate
    for (int n_rotate = 0; n_rotate < 3; n_rotate++) {
        min = std::min(min, calculate(N, l, r, u, B));
        reverse(l, r, u);
        min = std::min(min, calculate(N, l, r, u, B));
        reverse(l, r, u);

        rotate(l, r, u);
    }

    // 2. Print min
    std::cout << min << "\n";

    return (0);
}