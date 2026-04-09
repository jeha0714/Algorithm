#include <iostream>
#include <vector>
#include <queue>

int N, M, X;
std::vector<std::vector<int> >  opposite_path;
std::vector<int>                visited;
std::queue<int>                 q;
int result, tmp;

enum {
    NONVISIT,
    VISITED,
};

void    bfs(int num) {
    for (int i = 0; i < opposite_path[num].size(); i++) {
        if (visited[opposite_path[num][i]] == NONVISIT) {
            visited[opposite_path[num][i]] = VISITED;
            result++;
            q.push(opposite_path[num][i]);
        }
    }
}

int main(void) {
    // 0. Init
    std::cin >> N >> M;
    opposite_path.resize(N + 1);
    for (int i = 0, s, e; i < M; i++) {
        std::cin >> s >> e;
        opposite_path[e].push_back(s);
    }
    std::cin >> X;
    visited.resize(N + 1);
    for (int i = 1; i <= N; i++)
        visited[i] = NONVISIT;
    result = 0;

    // 1. Calculate
    for (int i = 0; i < opposite_path[X].size(); i++) {
        if (visited[opposite_path[X][i]] == NONVISIT) {
            visited[opposite_path[X][i]] = VISITED;
            result++;
            q.push(opposite_path[X][i]);
        }
    }
    while (!q.empty()) {
        tmp = q.front();
        q.pop();
        bfs(tmp);
    }

    // 2. Print result
    std::cout << result << "\n";

    return (0);
}