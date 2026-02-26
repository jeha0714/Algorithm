#include <stdio.h>

int main() {
    
    int T; //테스터 데이터의 개수
    
    scanf("%d", &T);
    
    for(int i = 0; i < T ; i++) {//알고리즘을 T번 진행.
        
        int H,W,N; //H는 층수 W는 층마다 방 개수 N은 몇번째 손님을 의미 
        scanf("%d %d %d", &H, &W, &N);
        
        if(N % H == 0) {//예외인 경우가 생김. 다음과 같은 조건이 나올 경우 0값이 나와서 조건을 수정해줘야 함.
            printf("%d%02d \n", (H), (N / H) );
            
        }
        else {
        
            printf("%d%02d \n", (N % H), (N/H)+1); //예제 보면 방정식 바로 이해 가능.    
        }
        
        
    }
    
    
    
    
    return 0;
}