#include <stdio.h>

int main() { //for문이 아닌 삼항연산자를 사용해봄.
    
    int a,b,c;
    int max, mid, min;
    scanf("%d %d %d", &a, &b,&c);
    
    max = (a > b && a > c) ? a : (b > c && b > a) ? b : c;
    mid = ((b > a && a > c) || (c > a && a > b)) ? a : ((a > b && b > c) || (c > b && b > a)) ? b : c;
    min = (b > a && c > a) ? a : (a > b && c > b) ? b : c;
    
    printf("%d %d %d", min ,mid, max);
    
    return 0;
}