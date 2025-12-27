#include <stdio.h>

long long DP[68] = {1,1,2,4,0,};

long long find_Fibo( int num )
{
    if ( DP[ num ] == 0 )
    {
        DP[ num ] = find_Fibo( num - 1 ) + find_Fibo( num - 2 ) + find_Fibo( num - 3 ) + find_Fibo( num - 4 );
        return DP[ num ];
    }
    
    else
        return DP[ num ];
    
    return DP[ num ];
}


int main() {
    
    int t; scanf("%d", &t);
    
    while( t-- > 0 )
    {
        int num; scanf("%d", &num );
        long long result = find_Fibo( num );
        
        printf("%lld\n", result );
    }
    
    return 0;
}