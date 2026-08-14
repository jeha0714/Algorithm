#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int>	um;
    
    // 0. Init
    for (int i = 0; i < completion.size(); i++) {
        if (um.find(completion[i]) == um.end())
            um[completion[i]] = 1;
        else
            um[completion[i]]++;
    }
    
    // 1. Calculate
    for (int i = 0; i < participant.size(); i++) {
        if (um.find(participant[i]) == um.end() || um[participant[i]] == 0)
            return (participant[i]);
        else
            um[participant[i]]--;
    }
    
    // 2. Return Answer
    return answer;
}