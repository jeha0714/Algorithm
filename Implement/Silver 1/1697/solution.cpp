#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void    bfs(int tmp, vector<int> & v, queue<int> & q) {
    if (tmp < 0 || tmp > 100000)
        return ;
    
    if (tmp * 2 <= 100000 && v[tmp * 2] == -1) {
        q.push(tmp * 2);
        v[tmp * 2] = v[tmp] + 1;
    }
    if (0 <= tmp - 1 && v[tmp - 1] == -1) {
        q.push(tmp - 1);
        v[tmp - 1] = v[tmp] + 1;
    }
    if (tmp + 1 <= 100000 && v[tmp + 1] == -1) {
        q.push(tmp + 1);
        v[tmp + 1] = v[tmp] + 1;
    }
}

int main(void) {
    int         N, K;
    vector<int> v(100001, -1);
    queue<int>  q;
    int         tmp;

    // 0. Init
    cin >> N >> K;
    v[N] = 0;
    q.push(N);

    // 1. Calcualte ( do bfs! )
    while (!q.empty()) {
        tmp = q.front();
        q.pop();
        if (tmp == K)
            break ;
        bfs(tmp, v, q);
    }

    // 2. Print result
    cout << v[K] << "\n";

    return (0);
}