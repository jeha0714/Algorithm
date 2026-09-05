#include <string>
#include <vector>

using namespace std;

/*
3 9 27 81... 이렇게 풀어야 한다.
1 ~ 3 1자리
4 ~ 12 2자리 
13 ~ 39 3자리
40 ~ 120 4자리
121 ~ 363 5자리
-> 쪼개고 쪼개고 쪼갠다.
*/
string solution(int n) {
    string	answer = "";
    long long	prev, cur, i, tmp;
    
    // 0. Init
    answer.reserve(30);
    	// a. 최초의 값을 구한다.
    prev = 0;
    cur = 0;
    for (i = 1; ; i *= 3) {
        // 1) n이 범위내에 돌때까지 찾는다.
        for (int j = 0; j < 3; j++) {
            cur += i;
            if (prev < n && n <= cur) {
                if (j == 0) answer.push_back('1');
                else if (j == 1) answer.push_back('2');
                else if (j == 2) answer.push_back('4');
                break ;
            }
            prev = cur;
        }
        // 2) n이 범위 내라면 for문 탈출
        if (prev < n && n <= cur) {
            n -= prev;
            break ;
        }
    }
    
    // 1. Calculate
    i /= 3;
    while (i > 0) {
        tmp = (n - 1) / i;
        if (tmp == 0) answer.push_back('1');
        else if (tmp == 1) answer.push_back('2');
        else if (tmp == 2) answer.push_back('4');
        n = (n - 1) % i + 1;
        i /= 3;
    }
    
    // 2. Return Answer
    return answer;
}