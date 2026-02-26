#include <stdio.h>

int fibo(int n) { //백준 10870번 문항에서는 0번째 피보나치 수가 0 1번째 피보나치 수가 1이라 정의함.
    if (n==0) {
        return 0;
    }
    else if (n ==1) {
        return 1;
    }
    else {
        return fibo(n-2) + fibo(n-1);
    }
}

int main() {
    
    int N;
    scanf("%d", &N);
    
    printf("%d", fibo(N));
    
    return 0;
}