#include <stdio.h>

int main() {
    
    int N, B, C; scanf("%d", &N);
    int array[ N ];
    for (int i = 0 ; i < N ; i++ )
        scanf("%d", &array[i] );
    
    scanf("%d %d", &B, &C);
    
    long long result = 0;
    
    for (int i = 0 ; i < N; i++ )
    {
        array[ i ] = array[ i ] - B; result++;
        
        if ( array[ i ] > 0)
        {
            if ( array[ i ] % C == 0 )
                result += ( array[ i ] / C );
            else
                result += ( array[ i ] / C + 1 );
        }
        else
            continue;
        
    }
    
    printf("%lld", result );
    
    
    return 0;
}