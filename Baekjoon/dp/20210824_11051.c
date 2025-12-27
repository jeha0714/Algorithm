#include <stdio.h>
#include <stdlib.h>


void Binomial_coefficient(int ** array_N, int N, int K) //이항 계수 구하는 함수.
{
    if ( K == 0 )
    {
        array_N[N][K] = 1;
    }
    else if ( K == N )
    {
        array_N[N][K] = 1;
    }
    else
    {
        if ( array_N[N -1][K - 1] == 0 )
        {
            Binomial_coefficient(array_N, N - 1, K - 1);
        }
        
        if ( array_N[N -1][K] == 0 )
        {
            Binomial_coefficient(array_N, N - 1, K);
        }
        
        array_N[N][K] = ( array_N[N - 1][K - 1] + array_N[N - 1][K] ) % 10007;
    }
    
}



int main() {
    
    int N, K;
    
    scanf("%d %d", &N, &K);
    
    int** array_N = (int **)malloc(sizeof(int *) * N + 1); //[N + 1][K + 1]사이즈의 동적 할당.
    for (int i = 0; i < N + 1 ; i++)
    {
        array_N[i] = (int *)malloc(sizeof(int) * K + 1);
    }
    
    
    Binomial_coefficient(array_N, N, K);
    
    printf("%d", array_N[N][K] );
    
    return 0;
}