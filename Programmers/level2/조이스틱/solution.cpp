#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string name) {
    int answer = 0;
    int	n_updown = 0;
    int tmp1, tmp2;
    int s, e;
    
    // 0. Init
    answer = name.length() - 1;
    for (int i = 0; i < name.length(); i++) {
        if (name[i] != 'A') {
            tmp1 = name[i] - 'A';
            tmp2 = 'Z' - 'A' - tmp1 + 1;
            n_updown += min(tmp1, tmp2);
        }
    }
    
    // 1. Calculate
    for (int i = 0, j; i < name.length(); i++) {
        if (name[i] == 'A') {
            for (j = i; name[j] == 'A'; j++);
            s = i;
            e = j - 1;
            if (s == 0)
                answer = min(answer, static_cast<int>(name.length()) - 1 - e);
            else if (e == name.length() - 1)
                answer = min(answer, s - 1);
            else {
                if (s - 1 <= name.length() - 1 - e)
                    answer = min(answer, (s - 1) * 2 + static_cast<int>(name.length() - 1 - e));
                else
                    answer = min(answer, (s - 1) + static_cast<int>(name.length() - 1 - e) * 2);
            }
        }
    }
    answer += n_updown;
    
    // 2. Return answer
    return answer;
}