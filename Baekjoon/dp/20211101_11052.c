#include <stdio.h>

int main() {
    
    int N; scanf("%d", &N); // 민규가 구매하려고 하는 카드의 개수 N
    int card_P[ N + 1 ]; // 1부터 N장의 카드가 들어있는 각 카드팩의 가격이 주어짐.
    for ( int in_Card = 1; in_Card < N + 1 ; in_Card++ )
        scanf("%d", &card_P[ in_Card ] );
        
    int solution_DP[ N + 1 ]; // i장을 고를 때 지불해야 하는 금액의 최댓값을 저장.
    
    // 1장을 선택할 때의 금액의 최댓값
    solution_DP[ 1 ] = card_P[ 1 ];
    
    // K장의 카드를 구매할 때 지불할 수 있는 금액의 최댓값 구하기
    for ( int now_Card = 2; now_Card < N + 1 ; now_Card++ )
    {
        solution_DP[ now_Card ] = 0; // now_Card장을 고를 때 지불값을 0으로 초기화.
        
        for (int start_Card = 1 ; start_Card < now_Card ; start_Card++ )
        {
            if ( solution_DP[ start_Card ] + solution_DP[ now_Card - start_Card ] > solution_DP[ now_Card ] )
                solution_DP[ now_Card ] = solution_DP[ start_Card ] + solution_DP[ now_Card - start_Card ];
        }
        
        if ( solution_DP[ now_Card ] < card_P[ now_Card ] )
            solution_DP[ now_Card ] = card_P[ now_Card ];
        
    }
    
    // 결과를 출력
    printf("%d", solution_DP[ N ] );
    
    return 0;
}