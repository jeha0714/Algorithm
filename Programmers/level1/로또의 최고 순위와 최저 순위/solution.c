#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// lottos_len은 배열 lottos의 길이입니다.
// win_nums_len은 배열 win_nums의 길이입니다.
int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * 2);
    bool	is_appear[46];
    int	match, num_zero;
    int	rank[7] = {6, 6, 5, 4, 3, 2, 1};
    
    // 0. Init
    for (int i = 1; i < 46; i++) is_appear[i] = false;
    for (int i = 0; i < win_nums_len; i++) {
        is_appear[win_nums[i]] = true;
    }
    match = 0;
    num_zero = 0;
    
    // 1. Calculate
    for (int i = 0; i < lottos_len; i++) {
        if (lottos[i] == 0) num_zero++;
        else if (is_appear[lottos[i]]) match++;
    }
    answer[0] = rank[match + num_zero];
    answer[1] = rank[match];
    
    // 2. Return Answer
    return answer;
}