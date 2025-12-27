#include <stdio.h>

int main() {
    
    int N;
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
    
        int sum_All = 0;
        sum_All += i %1000000;
        
        for (int j = 1000000 ; j >= 10 ; j/=10) {
        
            sum_All += i % j / (j/10);
        
        }
     
        if (sum_All == N) {
     
            printf("%d", i);
            break;
        }
        else if (sum_All != N && i == N-1) {
        
            printf("0");
        }
    }
    
    return 0;
}