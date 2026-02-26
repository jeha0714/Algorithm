#include <stdio.h>

int main() {
    
    int a,b;
    int max, min;
    scanf("%d %d", &a, &b);
    
    if(a>=b) {
        max = a, min = b;
    }
    else {
        max = b, min = a;
    }
    
    for(int i = min; i > 0; i--) { //최대공약수 찾기
        
        if(a % i == 0 && b % i == 0) {
            printf("%d\n", i);
            break;
        }
    }
    
    for(int i = 1; ; i++) { //최소공배수 찾기
        
        if((max*i) % a == 0 && (max*i) % b == 0) {
            printf("%d", max*i);
            break;
        }
    }
    
    return 0;
}