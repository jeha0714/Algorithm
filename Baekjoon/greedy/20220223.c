#include <stdio.h>
#include <stdlib.h>


int compare( const void * first, const void * second )
{
    return *(int *)first - *(int *)second;
}


int main()
{
    int N; scanf("%d", &N);
    
    int array_Price[ N ];
    for (int i = 0 ; i < N ; i++ )
        scanf("%d", &array_Price[ i ] );
    
    qsort( array_Price, N, sizeof( array_Price[0] ), compare );
    
    int code = 3;
    long long min = 0;
    for (int i = N - 1 ; i >= 0 ; i--)
    {
        if ( code == 3 || code == 2 )
        {
            code--;
            min += array_Price[i];
        }
        
        else if ( code == 1 )
            code = 3;
        
    }
    
    
    printf("%lld", min );
    
    return 0;
}