#include <stdio.h>
#include <math.h>

int main() {
    
    int M, N;
    scanf("%d %d", &M, &N);
    
    for(int i = M ; i <= N ; i++) {
        int help_Code = 0;
        
        if (i == 1) { //1은 소수가 아님!
            continue;
        }
        
        for (int j = 2; j <= (int)sqrt(i) ; j++) { //제곱근 까지만 범위를 좁혀도 되는 이유는 예로 2*8 3*6 4*4 등 을 생각해보자.
            if(i % j == 0) {
                help_Code = 1;
                break;
            }
        }
        
        if (help_Code == 0) {
            printf("%d\n", i);
        }
    }
    
    return 0;
}