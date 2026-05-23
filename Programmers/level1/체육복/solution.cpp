#include <vector>

using namespace std;

enum {
    LOST,
    NONLOST,
    RESERVE,
    NONRESERVE
};

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int>	l(n + 2, NONLOST);
    vector<int>	r(n + 2, NONRESERVE);
    
    // 0. Init
    for (int i = 0; i < lost.size(); i++)
        l[lost[i]] = LOST;
    for (int i = 0; i < reserve.size(); i++)
        r[reserve[i]] = RESERVE;
    
    // 1. Calculate
    for (int i = 1; i <= n; i++) {
        if (l[i] == LOST && r[i] == NONRESERVE) {
            if (l[i - 1] == NONLOST && r[i - 1] == RESERVE) {
                r[i - 1] = NONRESERVE;
                answer++;
            }
            else if (l[i + 1] == NONLOST && r[i + 1] == RESERVE) {
                r[i + 1] = NONRESERVE;
                answer++;
            }
        }
        else if (l[i] == NONLOST || (l[i] == LOST && r[i] == RESERVE))
            answer++;
    }
    
    // 2. Return answer
    return answer;
}