#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    
    // 0. Init
    
    // 1. Calculate
    for (int i = 0; i < absolutes.size(); i++) {
        if (signs[i]) answer += absolutes[i];
        else answer -= absolutes[i];
    }
    
    // 2. Return Answer
    return answer;
}