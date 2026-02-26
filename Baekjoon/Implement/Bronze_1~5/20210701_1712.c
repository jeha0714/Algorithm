#include <stdio.h>

int main() {
    
    int A,B,C; // 세 수는 모두 자연수라는 조건.
    scanf("%d %d %d", &A, &B, &C);
    
    if((C - B) <= 0 ) {//손익 분기점이 존재하지 않는 조건.
        printf("-1");
    }
    
    else { 
        
        printf("%d", A / (C - B) + 1);
    }
    
    return 0;
}