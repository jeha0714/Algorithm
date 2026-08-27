#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
bool solution(const char* s) {
    bool answer = true;
    char * stack;
    int	len = strlen(s);
    int	i_st = 0;
    
    stack = (char *)malloc(sizeof(char) * len);
    for (int i = 0; i < len; i++) {
        if (s[i] == '(')
            stack[i_st++] = '(';
        else {
            if (i_st > 0) i_st--;
            else return (false);
        }
    }
    free(stack);
    if (i_st > 0) return (false);
    
    return answer;
}