#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

enum {
    UNDER,
    ONNONVISIT,
    ONVISIT,
};

/*
    brute-force 기반 
    N을 2~100까지 모두 계산 후 max 값 도출
*/

void    bfs(int r, int c, int N, std::vector<std::vector<int> > & arr, std::queue<std::pair<int, int> > & q) {
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
        if (0 <= r + dr[i] && r + dr[i] < N 
            && 0 <= c + dc[i] && c + dc[i] < N
            && arr[r + dr[i]][c + dc[i]] == ONNONVISIT) {
                arr[r + dr[i]][c + dc[i]] = ONVISIT;
                q.push(std::make_pair(r + dr[i], c + dc[i]));
        }
    }
}

int main(void) {
    int                             N;
    std::vector<std::vector<int> >  area;
    std::vector<std::vector<int> >  arr;
    std::queue<std::pair<int, int> >   q;
    int                             max_safe_area;
    int cur_r, cur_c;

    // 0. Init
    std::cin >> N;
    area.resize(N);
    arr.resize(N);
    for (int r = 0; r < N; r++) {
        area[r].resize(N);
        arr[r].resize(N);
        for (int c = 0; c < N; c++) {
            std::cin >> area[r][c];
        }
    }
    max_safe_area = 0;

    // 1. Calculate N 2 ~ 100
    for (int n = 0, cur_area; n <= 100; n++) {
        // a. n보다 큰 영역 표시
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (area[r][c] > n)
                    arr[r][c] = ONNONVISIT;
                else
                    arr[r][c] = UNDER;
            }
        }

        // b. area 전체 순하면서 n보다 큰 영역 + non visit bfs
        cur_area = 0;
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (arr[r][c] == ONNONVISIT) {
                    cur_area++;
                    arr[r][c] = ONVISIT;
                    q.push(std::make_pair(r, c));

                    while (!q.empty()) {
                        cur_r = q.front().first;
                        cur_c = q.front().second;
                        q.pop();
                        bfs(cur_r, cur_c, N, arr, q);
                    }
                }
            }
        }

        // c. max 계산
        max_safe_area = std::max(max_safe_area, cur_area);
    }

    // 2. Print max safe area
    std::cout << max_safe_area << "\n";

    return (0);
}