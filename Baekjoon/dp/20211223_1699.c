#include <stdio.h>
#include <math.h>


int main() {
    
    int N; scanf("%d", &N);
    
    long long array[ N + 1 ];
    array[1] = 1;
    
    for (int now = 2 ; now < N + 1 ; now++ )
    {
        int int_Sqrt = (int)sqrt( now );
        
        if ( (double)int_Sqrt == sqrt( now ) )
            array[ now ] = 1;
        
        else
        {
            long long min_Result = 1 + array[ now - (int)sqrt( now ) * (int)sqrt( now ) ];
            
            for (int i = (int)sqrt( now ) - 1 ; i > 0 ; i-- )
            {
                if ( min_Result > array[ now - i * i ] + array[ i * i ] )
                    min_Result = array[ now - i * i ] + array[ i * i ];
            }
            
            array[ now ] = min_Result;
        }
    }
    
    printf("%lld", array[N] );
    
    
    return 0;
}