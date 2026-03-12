#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int bns(int s, int e, int tmp, deque<pair<int, int> > & q) {
    int m = (s + e) / 2;

    if (s > e)
        return (e);
    
    if (tmp < q[m].first)
        return (bns(s, m - 1, tmp, q));
    else
        return (bns(m + 1, e, tmp, q));
}

int main(void) {
    int             N, Q;
    vector<int>     dist;
    deque<pair<int, int> > q;
    int             tmp;

    // 0. Init
    ios_base::sync_with_stdio(false);                                        
    cin.tie(NULL);
    cin >> N;
    dist.resize(N);
    for (int i = 0; i < N; i++)
        cin >> dist[i];
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        dist[i] -= tmp;
    }
    
    // 1. Calculate
    q.push_back(make_pair(dist[0] + 1, 0));
    for (int cur = 1; cur < N; cur++) {
        // 현재 가장 앞 gap보다 크다면 추가할 필요 x -> 어차피 통과 못함
        if(q.front().first > dist[cur]) {
            q.push_front(make_pair(dist[cur] + 1, cur));
        }
    }

    // 2. Print result
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> tmp;
        tmp = bns(0, q.size() - 1, tmp, q);
        if (tmp == -1)
            cout << N << "\n";
        else
            cout << q[tmp].second << "\n";
    }

    return (0);
}