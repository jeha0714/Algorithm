#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// score_len은 배열 score의 길이입니다.
int solution(int k, int m, int score[], size_t score_len) {
    int answer = 0;
    int	num_apple[k + 1];
    
    // 0. Init
    for (int i = 1; i <= k; i++) num_apple[i] = 0;
    for (int i = 0; i < score_len; i++)
        num_apple[score[i]]++;
    
    // 1. Calculate
    for (int i = k, cur = 0; i >= 1;) {
        if (num_apple[i] >= m - cur) {
            num_apple[i] -= m - cur;
            answer += i * m;
            cur = 0;
        }
        else {
            cur += num_apple[i];
            num_apple[i] = 0;
            i--;
        }
    }
    
    // 2. Return Answer
    return answer;
}