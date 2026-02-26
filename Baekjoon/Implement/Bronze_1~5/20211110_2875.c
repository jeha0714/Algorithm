#include <stdio.h>

int main() {
    
    int n, m, k; scanf("%d %d %d", &n, &m, &k);
    
    int result = n / 2 > m ? m : n / 2;
    int left_PP = ( n - result * 2 ) + ( m - result );
    
    
    if ( left_PP > k )
        printf("%d", result );
        
    else
    {
        k -= left_PP;
        if ( k % 3 == 0)
            printf("%d", result - ( k / 3 ) );
        else
            printf("%d", result - ( k / 3 + 1 ) );
    }
    
    return 0;
}