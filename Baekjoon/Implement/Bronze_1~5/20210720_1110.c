#include <stdio.h>

int main() {
    
    int N;
    int num1, num2, num3, num4;
    int findCode = 0;
    
    scanf("%d", &N);
    
    num4 = N;
    
    for (; ; findCode++){
        num1 = num4 / 10;
        num2 = num4 % 10;
        num3 = num1 + num2;
        num4 = (num2 * 10) + (num3%10);
        
        if (num4 == N) {
            findCode++;
            printf("%d", findCode);
            break;
        }
    }
    
    
    
    
    
    return 0;
}