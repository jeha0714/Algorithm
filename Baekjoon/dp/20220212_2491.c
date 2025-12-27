#include <stdio.h>

int main() {
    
    // 수열의 길이
    int N; scanf("%d", &N);
    
    // 수열이 순서대로 주어짐.
    int seq_Array[ N ];
    for (int i = 0 ; i < N ; i++)
        scanf("%d", &seq_Array[ i ] );
    
    // 해당 인덱스까지 오면서 가장 길었던 길이를 저장.
    int Up[ N ], Down[ N ];
    Up[ 0 ] = 1, Down[ 0 ] = 1; // 인덱스 0은 1로 초기화.
    for (int i = 1 ; i < N ; i++)
    {
        // 초기값은 1로 설정
        Up[ i ] = 1, Down[ i ] = 1;
        
        // 전 값이 현재 값보다 더 작은 경우
        if ( seq_Array[ i - 1 ] < seq_Array[ i ] )
        {
            Up[ i ] = Up[ i - 1 ] + 1;
            Down[ i ] = 1;
        }
        
        // 전 값이 현재 값보다 더 큰 경우
        else if ( seq_Array[ i - 1 ] > seq_Array[ i ] )
        {
            Up[ i ] = 1;
            Down[ i ] = Down[ i - 1 ] + 1;
        }
        
        else // seq_Array[ i - 1 ] == seq_Array[ i ]로 같은 경우
        {
            Up[ i ] = Up[ i - 1 ] + 1;
            Down[ i ] = Down[ i - 1 ] + 1;
        }
        
    }
    
    // DP로 저장된 값중 가장 큰 값을 찾는다.
    int max = 1 ;
    for ( int i = 1; i < N ; i++ )
    {
        if ( max < Up[ i ])
            max = Up[ i ];
        if ( max < Down[ i ] )
            max = Down[ i ];
    }
    
    printf("%d", max);
    
    return 0;
}