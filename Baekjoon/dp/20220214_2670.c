#include <stdio.h>


int main() {
    
    int N; scanf("%d", &N );
    
    double array[ N ];
    for (int i = 0 ; i < N; i++)
        scanf("%lf", &array[i] );
    
    
    double DP[ N ];
    DP[0] = array[0];
    for (int i = 1 ; i < N ; i++ )
    {
        if ( DP[i- 1] * array[i] > array[i] )
            DP[i] = DP[i - 1] * array[i];
        
        else
            DP[i] = array[i];
    }
    
    double max = 0;
    for (int i = 0 ; i < N ; i++)
    {
        if ( max < DP[i] )
            max = DP[i];
    }
    
    printf("%.3lf", max );
    
    return 0;
}