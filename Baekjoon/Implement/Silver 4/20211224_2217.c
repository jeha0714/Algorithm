#include <stdio.h>
#include <stdlib.h>


int compare ( const void * first, const void * second )
{
    return  *(int *)first - *(int *)second;
}


int main() {
    
    int n; scanf("%d", &n);
    
    int max_W[ n ];
    for (int i = 0 ; i < n ; i++)
        scanf("%d", &max_W[ i ] );
    
    qsort( max_W, n, sizeof( max_W[ 0 ] ), compare );
    
    long long max = 0;
    for (int i = n - 1 ; i >= 0 ; i-- )
    {
        if ( max_W[ i ] * ( n - i ) > max )
            max = (long long)max_W[ i ] * (long long)( n - i );
    }
    
    printf("%lld", max );
    
    return 0;
}