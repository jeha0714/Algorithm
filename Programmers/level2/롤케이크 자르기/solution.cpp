#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
전체 등장 횟수를 체크
index 0에서 우로 가면서 증가/감소 시킴. 
1. 0에서 증가하는 경우는 현재 토핑 수를 체크
2. 감소해서 0이 된 경우 현재 토핑 수를 체크
*/
// topping_len은 배열 topping의 길이입니다.
int solution(int topping[], size_t topping_len) {
    int answer = 0;
    int amount_a[10001], amount_b[10001];
    int	num_a, num_b;
    
    // 0. Init
    for (int i = 0; i < 10001; i++) {
        amount_a[i] = 0;
        amount_b[i] = 0;
    }
        // a. 전체 등장 횟수를 체크
    for (int i = 0; i < topping_len; i++)
        amount_b[topping[i]]++;
    	// b. num_@ 초기화
    num_a = 0;
    num_b = 0;
    for (int i = 1; i < 10001; i++) {
        if (amount_b[i] != 0) num_b++;
    }
    
    // 1. Calculate
    for (int i = 0; i < topping_len; i++) {
		// a. 0에서 증가하는 경우는 현재 토핑 수를 체크
        if (amount_a[topping[i]] == 0) num_a++;
        amount_a[topping[i]]++;
		// b. 감소해서 0이 된 경우 현재 토핑 수를 체크
        if (amount_b[topping[i]] == 1) num_b--;
        amount_b[topping[i]]--;
        // c. num_@
        if (num_a == num_b) answer++;
    }
    
    // 2. Return Answer
    return answer;
}