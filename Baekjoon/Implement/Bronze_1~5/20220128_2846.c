#include <stdio.h>

int main()
{
    int N; scanf("%d", &N);
    
    int array[N];
    for( int i = 0 ; i < N ; i++ )
        scanf("%d", &array[ i ] );
    
    int max = 0, now = 0;
    for ( int i = 0 ; i < N - 1; i++ )
    {
        if ( array[ i ] < array[ i + 1 ] )
            now += ( array[ i + 1 ] - array[ i ] );
        
        else
        {
            if ( max < now )
                max = now;
            now = 0;
        }
    }
    if ( max < now )
            max = now;
        now = 0;
    
    printf("%d", max);

    return 0;
}
