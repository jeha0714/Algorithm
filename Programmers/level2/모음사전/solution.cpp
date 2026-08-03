#include <string>

using namespace std;

/*
우선순위 고려대상
- aeiou
- 길이

우선순위 순위
1. aeiou
2. 길이
*/

void	inc_s(string & s) {
    string	cmp = "AEIOU";
    
    // 1. 길이가 5가 아닌 경우 맨 뒤에 a를 붙인다.
    if (s.length() != 5) {
        s.push_back('A');
    }
    // 2. 길이가 5인 경우
    else {
        // a. 가장 끝이 'U'가 아니라면 하나 증가한다.
        if (s[4] != 'U') {
            for (int i = 0; i < 4; i++) {
                if (s[4] == cmp[i]) {
                    s[4] = cmp[i + 1];
                    break ;
                }
            }
        }
        // b. 가장 끝이 'U'라면 그 자리를 줄이고 그 앞자리를 하나 증가시킨다.
        else {
            while (s[s.length() - 1] == 'U')
                s.pop_back();
            for (int i = 0; i < 4; i++) {
                if (s[s.length() - 1] == cmp[i]) {
                    s[s.length() - 1] = cmp[i + 1];
                    break ;
                }
            }
        }
    }
}

int solution(string word) {
    int answer;
    string	s;
    
    // 0. Init
    s = 'A';
    answer = 1;
    
    // 1. Calculate
    while (s.compare(word) != 0) {
        answer++;
        inc_s(s);
    }
    
    // 2. Return Answer
    return answer;
}