#include <stdio.h>

int factorial (int N) {
    if (N == 0) {
        return 1;
    }
    else if (N == 1) {
        return 1;
    }
    else {
        return N * factorial(N-1);
    }
}

int main() {
    
    int N;
    scanf("%d", &N);
    
    printf("%d", factorial(N));
    
    return 0;
}