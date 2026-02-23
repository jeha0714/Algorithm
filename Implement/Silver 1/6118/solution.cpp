#include <iostream>
#include <vector>
#include <queue>

using namespace std;

enum {
    NONVISITED = 0,
};

vector<int>             visited;
vector<vector<int> >    routes;
queue<int>              q;

void    bfs(int cur_barn_num) {
    int num_connection = routes[cur_barn_num].size();
    int barn_num_connection;

    for (int i = 0; i < num_connection; i++) {
        barn_num_connection = routes[cur_barn_num][i];

        if (visited[barn_num_connection] == NONVISITED) {
            visited[barn_num_connection] = visited[cur_barn_num] + 1;
            q.push(barn_num_connection);
        }
    }
}

int main(void) {
    int N, M;
    int a, b;
    int barn_num = 1, dist = 0, total = 1;

    // 0. Init
    cin >> N >> M;
    visited.resize(N + 1);
    routes.resize(N + 1);
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        routes[a].push_back(b);
        routes[b].push_back(a);
    }
    for (int i = 1; i <= N; i++)
        visited[i] = NONVISITED;
    q.push(1);
    
    // 1. Calculate distance
    while (!q.empty()) {
        a = q.front();
        q.pop();
        bfs(a);
    }

    // 2. Find result
    for (int i = 2; i <= N; i++) {
        if (visited[i] != NONVISITED && dist < visited[i]) {;
            barn_num = i;
            dist = visited[i];
            total = 1;
        }
        else if (dist == visited[i]) {
            total++;
        }
    }

    // 3. Print result
    cout << barn_num << " " << dist << " " << total << "\n";

    return (0);
}