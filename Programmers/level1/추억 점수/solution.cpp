#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    unordered_map<string, int>	um;
    
    // 0. Init
    for (int i = 0; i < name.size(); i++)
        um[name[i]] = yearning[i];
    
    // 1. Calculate
    for (int i = 0; i < photo.size(); i++) {
        answer.push_back(0);
        for (int j = 0; j < photo[i].size(); j++)
            answer[i] += um[photo[i][j]];
    }
    
    // 2. Return answer
    return answer;
}