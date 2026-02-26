#include <stdio.h>

int main() { //피보나치를 for문으로 정리해본 코드랄까. n의 범위가 작아서 가능한 듯했다.
    int n;
    long long num1 = 0, num2 = 1, num3 = 1;
    
    scanf("%d", &n);
    
    for(int i = 3; i <= n + 1  ; i++) {
        
        if (i % 3 == 0) {
            num3 = num1 + num2;
        }
        else if (i % 3 == 1 ) {
            num1 = num2 + num3;
        }
        else {
            num2 = num3 + num1;
        }
        
    }
    
    if (n == 0) {
        printf("%lld", num1);
    }
    else if(n == 1) {
        printf("%lld", num2);
    }
    else if(n == 2) {
        printf("%lld", num3);
    }
    else if (n % 3 == 0) {
        printf("%lld", num1);
    }
    else if (n % 3 == 1 ) {
        printf("%lld", num2);
    }
    else {
        printf("%lld", num3);
    }
    
    
    return 0;
}