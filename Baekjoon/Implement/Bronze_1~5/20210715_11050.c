#include <stdio.h>

int multiply (int num) { //num! 팩토리알 값 구하는 함수.
    
    int result = 1;
    
    for (int i = 2; i <= num ; i++) {
        result *= i;
    }
    
    return result;
    
}

int main(void) {
    
    scanf("%d %d", &N, &K);
    
    result = multiply(N) / (multiply(N - K) * multiply(K));
    
    printf("%d", result);
    
    
    return 0;
}