#include <stdio.h>
#include <stdlib.h>


int compare(const void * first, const void * second) {
    
    return ((*(short *)first) - (*(short *)second));
    
}



int main() {
    
    int N, sum_All = 0; // N은 수의 개수. sum_All은 최솟값.
    scanf("%d", &N);
    short array_A[N], array_B[N]; //정수 배열 A와 B.
    
    for (int i = 0 ; i < N ;i++) { //배열 A 입력
        
        scanf("%hd", &array_A[i]);
    }
    for (int i = 0 ; i < N ;i++) { //배열 B 입력
        
        scanf("%hd", &array_B[i]);
    }
    
    
    qsort(array_A, N, sizeof(array_A[0]), compare); //정렬
    qsort(array_B, N, sizeof(array_B[0]), compare); //정렬
    
    
    for (int i = 0; i < N; i++) { //정렬된 수를 A의 가장 작은 수와 B의 가장 큰 수를 곱하는 식으로 진행.
        
        sum_All += (array_A[i] * array_B[N - 1 - i]);
    }
    
    
    printf("%d", sum_All); //정답 출력
    
    
    return 0;
}