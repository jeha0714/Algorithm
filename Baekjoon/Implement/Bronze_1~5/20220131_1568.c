#include <stdio.h>


int main()
{
    int N; scanf("%d", &N );
    int result = 0;
    int fly_Bird = 1;
    
    while ( N > 0 )
    {
        result++;
        
        if ( fly_Bird <= N )
            N -= (fly_Bird++);
        else
        {
            fly_Bird = 1;
            N -= (fly_Bird++);
        }
        
    }

    printf("%d", result );

    return 0;
}
