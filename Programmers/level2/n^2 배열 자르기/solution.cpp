#include <vector>
#include <cmath>

using namespace std;

/*
left, right를 n으로 나눈 몫과 나머지를 통해 몇번째 행,열우터 시작하고 끝내는지 알 수 있다.
*/

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    long long	s_r, s_c, e_r, e_c;
    
    // 0. Init
    s_r = left / n;
    s_c = left % n;
    e_r = right / n;
    e_c = right % n;
    
    // 1. Calculate
    for (long long r = s_r, c = s_c; !(r == e_r && c == e_c + 1); c++) {
        // 0. Set r & c
        if (c == n) {
            r++;
            c = 0;
        }
        
        // 1. push value to answer
        answer.push_back(max(r + 1, c + 1));
    }
    
    // 2. Return Answer
    return answer;
}