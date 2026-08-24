#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

enum {
    APPEAR,
    DISAPPEAR,
};

/*
1. 2차원 배열을 설계하고,
2. [r][c]일 때 r부터 시작해서 c만큼 이동한 거리의 값을 저장한다.
3. is_appear에 등록을 한 후에 확인한다.
*/
// elements_len은 배열 elements의 길이입니다.
int solution(int elements[], size_t elements_len) {
    int answer = 0;
    int	is_appear[1000001];
    int	dp[elements_len][elements_len + 1];
    
    // 0. Init
    	// a. is_appear 초기화
    for (int i = 0; i <= 1000000; i++) is_appear[i] = DISAPPEAR;
    	// b. init dp
    for (int r = 0; r < elements_len; r++) {
        dp[r][1] = elements[r];
    }
    
    // 1. Calculate
    	// a. set dp
    for (int c = 2; c <= elements_len; c++) {
        for (int r = 0; r < elements_len; r++) {
            if (r + c - 1 < elements_len)
                dp[r][c] = dp[r][c - 1] + dp[r + c - 1][1];
            else
                dp[r][c] = dp[r][c - 1] + dp[r + c - 1 - elements_len][1];
        }
    }
    	// b. register APPEAR
    for (int r = 0; r < elements_len; r++) {
        for (int c = 1; c <= elements_len; c++) {
            is_appear[dp[r][c]] = APPEAR;
        }
    }
    	// c. check APPEAR
    for (int i = 1; i <= 1000000; i++) {
        if (is_appear[i] == APPEAR) {
            //printf("%d ", i);
            answer++;
        }
    }
    
    // 2. Return Answer
    return answer;
}