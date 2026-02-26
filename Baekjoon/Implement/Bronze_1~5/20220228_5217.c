#include <stdio.h>


int main()
{
    int test_Case; scanf("%d", &test_Case );
    
    while ( test_Case-- > 0 )
    {
        int n; scanf("%d", &n );
        
        printf("Pairs for %d:", n );
        
        for (int i = 1 ; i <= n / 2 ; i++ )
        {
            if ( i == n - i )
                continue;
            
            printf(" %d %d", i, n - i );
            if ( i + 1 <= n / 2 && i + 1 != n - i - 1 )
                printf(",");
        }
        
        printf("\n");
    }
    
    
    return 0;
}
