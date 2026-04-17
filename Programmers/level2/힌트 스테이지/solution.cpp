#include <string>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>

using namespace std;

int    cal_hint(int stage, bitset<16> & info, vector<vector<int>> & cost, vector<vector<int>> & hint) {
    int num_hint = 0;
    int    result = 0;

    // 1. fint stage's hint
    for (int i = 1; i <= stage - 1; i++) {
        // a. if bought i stage's hint
        if (info[i - 1] == 1) {
            for (int j = 1; j < hint[i - 1].size(); j++) {
                if (hint[i - 1][j] == stage)
                    num_hint++;
            }
        }
    }

    // 2. calculate current stage price
    if (num_hint < cost[stage - 1].size())
        result = cost[stage - 1][num_hint];
    else
        result = cost[stage - 1][cost[stage - 1].size() - 1];

    return (result);
}

int solution(vector<vector<int>> cost, vector<vector<int>> hint) {
    int answer = 2147483647;
    queue<pair<int, bitset<16> > >    q;
    pair<int, bitset<16> >    tmp1, tmp2;

    tmp1.first = cost[0][0];
    q.push(tmp1);
    for (int cur_stage = 1; cur_stage <= cost.size(); cur_stage++) {
        // 1. queue에 다음 stage 담기
        if (cur_stage != cost.size()) {
            for (int j = 0; j < pow(2, cur_stage - 1); j++) {
                tmp1 = q.front();
                tmp2 = q.front();
                q.pop();

                // tmp의 bitset을 바탕으로 구매한 힌트를 보고 다음 단계 최소값 계산
                    // b. 현재 힌트 번들을 구매하지 않은 경우 queue에 추가
                tmp1.second[cur_stage - 1] = 0;
                tmp1.first += cal_hint(cur_stage + 1, tmp1.second, cost, hint);
                q.push(tmp1);

                    // c. 현재 힌트 번들을 구매한 경우 queue에 추가
                tmp2.second[cur_stage - 1] = 1;
                tmp2.first += hint[cur_stage - 1][0];
                tmp2.first += cal_hint(cur_stage + 1, tmp2.second, cost, hint);
                q.push(tmp2);
            }
        }
        // 2. queue에 존재하는 것들 모두 계산
        else {
            while (!q.empty()) {
                tmp1 = q.front();
                q.pop();
                if (answer > tmp1.first)
                    answer = tmp1.first;
            }
        }
    }

    return answer;
}
