#include <stdio.h>

int main()
{
    int N; scanf("%d", &N );
    
    int day_per_pay[ N + 1 ][ 2 ];
    for (int now = 1 ; now <= N ; now++ )
        scanf("%d %d", &day_per_pay[ now ][ 0 ], &day_per_pay[ now ][ 1 ] );
    
    int DP[ N + 1 ];
    for (int i = 0 ; i <= N; i++)
        DP[ i ] = 0;
        
    for (int i = 1 ; i <= N ; i++)
    {
        if ( day_per_pay[ i ][ 0 ] + i - 1 <= N )
        {
            // 당일까지 모은 급여와 당일 주어진 상담급여를 합친 금액이 상담이 끝났을 때 당일날 까지의 급여보다 작을경우
            if ( DP[ i - 1 ] + day_per_pay[ i ][ 1 ] >= DP[ day_per_pay[ i ][ 0 ] + i - 1 ] )
                DP[ day_per_pay[ i ][ 0 ] + i - 1 ] = DP[ i - 1 ] + day_per_pay[ i ][ 1 ];
                
        }
        
        if ( DP[ i ] <= DP[ i - 1 ] )
            DP[ i ] = DP[ i - 1 ];
        
    }
    
    
    
    printf("%d", DP[ N ] );

    return 0;
}
