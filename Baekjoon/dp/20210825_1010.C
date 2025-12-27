#include <stdio.h>
#include <stdlib.h>


void Find_C(int M, int N, long long ** array_C) //이항 계수를 구하는 함수.
{
    if (N == 0 || N == M) {array_C[M][N] = 1; }
    else 
    {
        if ( array_C[M -1][N] == 0 ) {Find_C(M - 1, N, array_C); }
        if ( array_C[M - 1][N - 1] == 0 ) { Find_C(M -1, N - 1, array_C); }
        
        array_C[M][N] = array_C[M - 1][N] + array_C[M - 1][N - 1];
    }
    
}



int main() {
    int T; //테스트 케이스
    
    scanf("%d", &T);
    
    for (int try_Num = 0; try_Num < T ; try_Num++ )
    {
        int N, M;
        
        scanf("%d %d", &N, &M);
        
        long long ** array_C = (int **)malloc(sizeof(long long *) * (M + 1) ); //2차배열을 동적 할당.
        for (int now_Index = 0 ; now_Index < M + 1; now_Index++)
        {
            array_C[now_Index] = (long long *)malloc(sizeof(long long) * (M + 1) );
        }
        
        Find_C(M, N, array_C);
        
        printf("%d\n", array_C[M][N] );
        
        
        free(array_C);
    }
    
    
    
    return 0;
}