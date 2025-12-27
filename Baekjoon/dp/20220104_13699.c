#include <stdio.h>

int main()
{
    int N; scanf("%d", &N );
    
    long long t_Array[ N + 1 ];
    t_Array[ 0 ] = 1;
    
    for (int now = 1 ; now < N + 1 ; now++ )
    {
        t_Array[ now ] = 0;
        
        for (int calculate = now - 1 ; calculate >= 0 ; calculate-- )
        {
            t_Array[ now ] += ( t_Array[ calculate ] * t_Array[ now - calculate - 1 ]);
        }

    }
    
    
    printf("%lld", t_Array[ N ] );

    return 0;
}
