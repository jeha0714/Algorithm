#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.  
int solution(const char* s) {
    int answer = 0;
    int num_x, num_other;
	char	x;

	// 0. Init
    x = '0';

	// 1. Calculate
	for (int i = 0; s[i] != '\0'; i++) {
		if (x == '0') {
			x = s[i];
            num_x = 1;
            num_other = 0;
		}
        else {
            if (s[i] == x) num_x++;
            else {
                num_other++;
                if (num_other == num_x) {
                    x = '0';
                    answer++;
                }
            }
        }
	}
	if (x != '0') answer++;
	
	// 2. Return Answer
    return answer;
}