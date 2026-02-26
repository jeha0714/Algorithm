#include <stdio.h>

int main()
{
    int N, K; scanf("%d %d", &N, &K );
    
    int array[ N ];
    for (int i = 0 ; i < N ; i++)
        scanf("%d", &array[ i ] );
    
    // 누적합을 저장 할 배열
    int accumulate_Array[ N ];
    accumulate_Array[0] = array[ 0 ];
    for ( int now_Index = 1 ; now_Index < N ; now_Index++ )
    {
        accumulate_Array[ now_Index ] = 0;
        
        if ( now_Index <= K - 1 )
            accumulate_Array[ now_Index ] = accumulate_Array[ now_Index - 1 ] + array[ now_Index ];
        else
            accumulate_Array[ now_Index ] = accumulate_Array[ now_Index - 1 ] + array[ now_Index ] - array[ now_Index - K ];
    }
    
    int max = accumulate_Array[ K - 1 ] ;
    for ( int now_Index = K ; now_Index < N ; now_Index++ )
    {
        if ( max < accumulate_Array[ now_Index ] )
            max = accumulate_Array[ now_Index ];
    }
    
    printf("%d", max );
    

    return 0;
}
