#include <stdio.h>


// n C m
int n, m ;


// 큰 수를 저장하기 위한 구조체
typedef struct 
{
    long long front;
    long long back;
}Big_Num;


// 큰 수를 두개의 변수로 쪼개서 저장. 총 36자리의 수를 저장할 수 있음.
void calculate( Big_Num DP[ n + 1 ][ n + 1 ] , int now_N, int now_M )
{
    DP[ now_N ][ now_M ].front += DP[ now_N ][ now_M ].back / 1000000000000000000;
    DP[ now_N ][ now_M ].back = DP[ now_N ][ now_M ].back % 1000000000000000000;
}


// 조합 공식을 이용하여 DP로 접근
void find( Big_Num DP[ n + 1 ][ n + 1 ], int now_N, int now_M )
{
    if ( now_M == 0 )
    {
        DP[ now_N ][ now_M ].front = 0;
        DP[ now_N ][ now_M ].back = 1;
    }
    else if ( now_N == now_M )
    {
        DP[ now_N ][ now_M ].front = 0;
        DP[ now_N ][ now_M ].back = 1;
    }
    
    else
    {
        if ( DP[ now_N - 1 ][ now_M - 1 ].back == 0 && DP[ now_N - 1 ][ now_M - 1 ].front == 0 )
            find( DP, now_N - 1, now_M - 1 );
        
        if ( DP[ now_N - 1 ][ now_M ].back == 0 && DP[ now_N - 1 ][ now_M ].front == 0 )
            find( DP, now_N - 1, now_M );
        
        DP[ now_N ][ now_M ].back = DP[ now_N - 1 ][ now_M - 1 ].back + DP[ now_N - 1 ][ now_M ].back;
        DP[ now_N ][ now_M ].front = DP[ now_N - 1 ][ now_M - 1 ].front + DP[ now_N - 1 ][ now_M ].front;
        
        calculate( DP, now_N, now_M );
    }
    
}


int main() {
    
    scanf("%d %d", &n, &m); // n C m 을 출력하기 위한 n 과 m 을 구함.
    Big_Num DP[ n + 1 ][ n + 1 ]; // 조합의 결과값을 저장할 배열.
    
    // 초기값을 설정해주고 0 C 0
    DP[0][0].front = 0, DP[0][0].back = 1;
    // 나머지 값을 0으로 초기화.
    for ( int i = 1 ; i < n + 1 ; i ++ )
    {
        for ( int j = 0 ; j < i + 1 ; j++ )
        {
            DP[i][j].back = 0;
            DP[i][j].front = 0;
        }
    }
    
    find( DP, n, m );
    
    
    if ( DP[n][m].front != 0 || DP[n][m].back > 1000000000000000000 )
        printf("%lld%.18lld", DP[n][m].front, DP[n][m].back);
    else
    printf("%lld", DP[n][m].back );
    
    return 0;
}