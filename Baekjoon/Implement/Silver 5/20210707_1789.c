#include <stdio.h>

int main() { 
    
    long long S;
    scanf("%lld", &S);
    
    for (long long i = 1 ; ; i++) { //고등학교 수학 식을 이용 함.
        if ((i)*(i+1) / 2 > S) {
            printf("%lld", i-1);
            break;
        }
    }
    
    return 0;
}