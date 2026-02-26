#include <stdio.h>

int main() { // 몇 가지의 예시로 게임을 해볼 경우 아래와 같은 공식이 나옴!
    int N;
    
    scanf("%d", &N);
    
    if(N%2==0) {
        printf("CY");
    }
    else {
        printf("SK");
    }
    
    return 0;
}