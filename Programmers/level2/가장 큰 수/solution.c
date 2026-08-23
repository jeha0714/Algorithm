#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 내름차순 정렬 비교함수
int comp(const void * a, const void * b) {
    char*	aa = *((char **)a);
    char*	bb = *((char **)b);
    char	s1[9];
    char	s2[9];
    int 	i, j;
    
    for (i = 0; aa[i] != '\0'; i++) s1[i] = aa[i];
    for (j = 0; bb[j] != '\0'; j++) s1[i + j] = bb[j];
    s1[i + j] = '\0';
    
    for (i = 0; bb[i] != '\0'; i++) s2[i] = bb[i];
    for (j = 0; aa[j] != '\0'; j++) s2[i + j] = aa[j];
    s2[i + j] = '\0';
    
    return ((atoi(s1) < atoi(s2)) - (atoi(s1) > atoi(s2)));
}

// numbers_len은 배열 numbers의 길이입니다.
char* solution(int numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char*	answer = (char*)malloc(4 * numbers_len + 1);
    char*	num[numbers_len];
    char*	tmp;
    int		j;
    
    // 0. Init
    	// a. numbers를 모두 string으로 변환
    for (int i = 0; i < numbers_len; i++) {
        tmp = malloc(5);
        snprintf(tmp, 5, "%d", numbers[i]);
        num[i] = tmp;
    }
    	// b. 앞자리수가 큰 순서대로 내림차순 정렬
    qsort(num, numbers_len, sizeof(char*), comp);
    
    // 1. Calcualte
    j = 0;
    for (int i = 0; i < numbers_len; i++) {
        for (int k = 0; num[i][k] != '\0'; k++, j++) {
            answer[j] = num[i][k];
        }
    }
    answer[j] = '\0';
    if (answer[0] == '0') answer[1] = '\0';
    
    // 2. Return Answer
    for (int i = 0; i < numbers_len; i++) free(num[i]);
    return answer;
}