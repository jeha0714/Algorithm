#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int cur, i;
    
    // 0. Init
    cur = section[0];
    i = 0;
    
    // 1. Calculate
    while (1) {
        // a. Paint
        answer++;
        cur = cur + m;
        
        // b. Jump Next non paint
        while (i < section.size() && section[i] < cur)
            i++;
        
        // c. Break Condition
        if (i == section.size())
            break ;
        else
            cur = section[i];
    }
    
    // 2. Return Answer
    return answer;
}