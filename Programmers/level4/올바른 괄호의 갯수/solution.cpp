#include <vector>

using namespace std;

void	bt(int n_open, int n_close, int & n, int & answer) {
    
    // 0. Degenerate Case
    if (n_open == 0 && n_close == 0) {
        answer++;
        return ;
    }
    
    // 1. bt
    if (n_open > 0) {
        bt(n_open - 1, n_close + 1, n, answer);
    }
    if (n_close > 0) {
        bt(n_open, n_close - 1, n, answer);
    }
}


int solution(int n) {
    int answer = 0;
    
    // 1. Calculate
    bt(n, 0, n, answer);
    
    // 2. Return answer
    return answer;
}