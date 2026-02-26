#include <stdio.h>
#include <math.h>

int main() {
    
    int M, N;
    int result = 0, min;
    double root_M, root_N;
    scanf("%d %d", &M, &N);
    
    root_N = pow(N, 0.5);
    root_M = pow(M, 0.5);
    
    if (root_M - (int)root_M != 0) {
        for (int i = (int)root_M + 1 ; i <= (int)root_N ; i++) {
        
            result += i * i;;
        }
    }
    else { //root_M - (int)root_M == 0
        
        for (int i = (int)root_M ; i <= (int)root_N ; i++) {
        
            result += i * i;;
        }
    }
    
    
    if (root_M - (int)root_M != 0) {
        
        min = ((int)root_M + 1) * ((int)root_M + 1);
    }
    else { //root_M - (int)root_M == 0
        
        min = ((int)root_M) * ((int)root_M);
    }

    
    if (result == 0) {
        printf("-1");
    }
    else {
        printf("%d\n%d", result, min);
    }
    
    return 0;
}