#include <stdio.h>


int main()
{
    // 아이들의 수
    int num_Child; scanf("%d", &num_Child );
    
    // 아이들이 서있는 번호의 순서가 적힌 배열
    int sequence_Child[ num_Child ];
    for ( int i = 0 ; i < num_Child ; i++ )
        scanf("%d", &sequence_Child[ i ] );
    
    
    /* < 가장 길게 증가하는 부분수열의 길이를 찾는다. > */
    
    
    // 해당 인덱스까지 오면서 가장 길었던 부분수열 길이값을 저장하는 배열 
    int DP[ num_Child ];
    for (int i = 0 ; i < num_Child ; i++)
        DP[ i ] = 1; // 초기값 1로 설정.
    
    
    // 인덱스가 1인 시점부터 순차적으로 해당 인덱스까지오면서 만들 수 있는 가장 긴 부분수열의 길이를 찾고 저장한다.
    for (int main = 1 ; main < num_Child ; main++ )
    {
        // main 인덱스 이전 값을 돌아다니면서
        for ( int sub = main - 1 ; sub >= 0 ; sub-- )
        {
            // main 값보다 번호가 작고 자신보다 저장된 부분수열의 길이값이 큰 경우를 찾는다.
            if ( sequence_Child[ sub ] < sequence_Child[ main ] && DP[ sub ] >= DP[ main ] )
                DP[ main ] = DP[ sub ] + 1;
        }
        
    }
    
    // 부분수열의 길이가 가장 긴 경우의 값을 저장.
    int most_Long_Len = 0;
    for ( int i = 0 ; i < num_Child ; i++ )
    {
        if ( most_Long_Len < DP[ i ] )
            most_Long_Len = DP[ i ];
    }
    
    // 옮겨야 하는 최소의 경우는 전체 아이들 수에서 부분수열의 길이가 가장 컸던 값을 빼면 된다.
    printf("%d", num_Child - most_Long_Len );
    
    
    return 0;
}
