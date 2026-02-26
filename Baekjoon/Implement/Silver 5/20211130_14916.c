#include <stdio.h>


int main() {
    
    int n; scanf("%d", &n);
    
    if ( n == 1 || n == 3 )
    {
        printf("-1");
        return 0;
    }
    else if ( n == 2 )
    {
        printf("1");
        return 0;
    }
    else if ( n == 4 )
    {
        printf("2");
        return 0;
    }
    else if ( n >= 5 )
    {
        long long array[ n + 1 ];
        array[0] = 0; array[2] = 1; array[4] = 2;
        
        for ( int now = 5; now < n + 1 ; now++ )
        {
            if ( now % 5 % 2 == 0) // now를 5로 나눈 나머지가 짝수 일 경우
            {
                array[ now ] = array[ now % 5 ] + ( now / 5 );
            }
            
            else // now를 5로 나눈 나머지가 홀수 일 경우
            {
                array[ now ] = ( ( now % 5 + 5 ) / 2 ) + ( now / 5 - 1 );
            }
            
        }
        
        printf("%lld", array[ n ] );
    }
    
    
    
    
    
    
    
    return 0;
}