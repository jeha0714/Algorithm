#include <stdio.h>

int main() {
    
    int N, F; scanf("%d %d", &N, &F);
    N = N / 100 * 100;
    
    for ( int i = 0 ; ;N++, i++ )
    {
        if ( N % F == 0 )
        {
            if ( i < 10 )
                printf("0%d", i);
            else
                printf("%d", i);
            break;
        }
    }    
    
    return 0;
}