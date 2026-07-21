#include <string>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    for (int s = 0, flag; s <= t.length() - p.length(); s++) {
        flag = -1;
        for (int i = 0; i < p.length(); i++) {
            if (t[s + i] > p[i]) {
                flag = -2;
                break ;
            }
            else if (t[s + i] < p[i])
                break ;
            else
                flag = i;
        }
        
        if (-1 <= flag && flag <= static_cast<int>(p.length() - 1))
            answer++;
    }
    
    return answer;
}