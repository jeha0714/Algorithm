#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    queue<int>    q;
    int         cur_max_user;
    int            more_server, quit_server;

    // 0. Init
    for (int i = 0; i < k; i++)
        q.push(0);
    cur_max_user = m - 1;

    // 1. Calcualte
    for (int time = 0; time < players.size(); time++) {
        // a. pop queue front
        quit_server = q.front();
        q.pop();

        // b. calcualte cur_max_user
        cur_max_user -= quit_server * m;

        // c. compare
        if (players[time] <= cur_max_user)
            q.push(0);
        else {
            more_server = (players[time] - cur_max_user) / m;
            if ((players[time] - cur_max_user) % m != 0)
                more_server++;
            q.push(more_server);
            cur_max_user += m * more_server;
            answer += more_server;
        }
    }

    // 2. Return result
    return answer;
}
