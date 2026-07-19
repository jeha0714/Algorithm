#include <string>
#include <vector>

using namespace std;

#define INT_MAX 2147483647

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    vector<int>	dp('z' - 'a' + 1, INT_MAX);
    
    // 0. Init
    for (int i = 0; i < keymap.size(); i++) {
        for (int j = 0; j < keymap[i].length(); j++) {
            if (dp[keymap[i][j] - 'A'] > j + 1)
                dp[keymap[i][j] - 'A'] = j + 1;
        }
    }
    
    // 1. Calculate
    for (int i = 0; i < targets.size(); i++) {
        answer.push_back(0);
        for (int j = 0; j < targets[i].length(); j++) {
            if (dp[targets[i][j] - 'A'] != INT_MAX)
                answer[i] += dp[targets[i][j] - 'A'];
            else {
                answer[i] = -1;
                break ;
            }
        }
    }
    
    // 2. Return answer
    return answer;
}