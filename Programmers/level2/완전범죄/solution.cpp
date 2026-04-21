#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;


int solution(vector<vector<int>> info, int n, int m) {
    int answer = 2147483647;
    vector<unordered_map<int, int> >    dp;

    // 0. Init
    dp.resize(info.size());
    if (info[0][0] < n)
        dp[0].insert(pair<int, int>(info[0][0], 0));
    if (info[0][1] < m)
        dp[0].insert(pair<int, int>(0, info[0][1]));

    // 1. Calculate
    for (int i = 1; i < info.size(); i++) {
        for (unordered_map<int, int>::iterator it = dp[i - 1].begin(); it != dp[i - 1].end(); it++) {
            int a, b;
            a = it->first + info[i][0];
            b = it->second + info[i][1];
            if (a < n) {
                if (dp[i].count(a) == 0) {
                    dp[i].insert(make_pair(a, it->second));
                }
                else {
                    if (dp[i][a] > it->second)
                        dp[i][a] = it->second;
                }
            }
            if (b < m) {
                if (dp[i].count(it->first) == 0) {
                    dp[i].insert(make_pair(it->first, b));
                }
                else {
                    if (dp[i][it->first] > b)
                        dp[i][it->first] = b;
                }
            }
        }
    }

    // 2. Find min
    for (unordered_map<int, int>::iterator it = dp[info.size() - 1].begin(); it != dp[info.size() - 1].end(); it++) {
        answer = min(answer, it->first);
    }

    if (answer == 2147483647)
        answer = -1;

    return answer;
}
