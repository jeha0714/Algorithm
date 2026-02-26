#include <iostream>
#include <vector>
#include <queue>

using namespace std;

enum {
    WATERHOLE = -2,
    NONVISITED = -1,
};

int                      X, Y, N;
vector<vector<int> >     visited(1003, vector<int>(1003, NONVISITED));
queue<pair<int, int> >   q; 
int                      dy[] = {1, 0, -1, 0};
int                      dx[] = {0, 1, 0, -1};

/*
    Parameter Info
    cur_x : 현재 x좌표
    cur_y : 현재 y좌표
*/
void    bfs(int cur_x, int cur_y) {
    int next_x, next_y;

    // 1. Search
    for (int i = 0; i < 4; i++) {
        next_x = cur_x + dx[i];
        next_y = cur_y + dy[i];

        // x, y가 맵 내에 존재하고 방문한적 없고 웅덩이 위치가 아니라면
        if (0 <= next_x && next_x <= 1002 
            && 0 <= next_y && next_y <= 1002
            && visited[next_y][next_x] == NONVISITED
            && visited[next_y][next_x] != WATERHOLE) {

                visited[next_y][next_x] = visited[cur_y][cur_x] + 1;
                q.push(make_pair(next_x, next_y));
        }
    }
}

int main(void) {
    int x, y;

    // 0. Init
    cin >> X >> Y >> N;
    X += 501;
    Y += 501;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        visited[y + 501][x + 501] = WATERHOLE;
    }
    visited[501][501] = 0;
    q.push(make_pair(501, 501));
    
    // 1. Find min route
    while (!q.empty()) {
        // a. Early Stop Condition
        if (visited[Y][X] != NONVISITED)
            break ;

        x = q.front().first;
        y = q.front().second;
        q.pop();
        bfs(x, y);
    }

    // 2. Print result
    cout << visited[Y][X] << "\n";

    return (0);
}