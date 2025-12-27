#include <stdio.h>

int main() {
    
    // 우리의 크기
    int N; scanf("%d", &N);
    
    if ( N == 0 )
        printf("1");
    else if ( N == 1 )
        printf("3");
    else if ( N == 2 )
        printf("7");
    else
    {
        // 해당 인덱스는 사자 수를 의미, 배열 내 값은 인덱스( 사자 수 )가 주어질 때 2*N에 배치 할 수 있는 경우의 수.
        int DP[ N + 1 ];
        DP[0] = 1; DP[1] = 3; DP[2] = 7;
        
        for ( int i = 3 ; i <= N ; i++ )
            DP[ i ] = ( DP[ i - 1 ] * 2 + DP[ i - 2 ] ) % 9901;
        
        printf("%d", DP[ N ] );
    }
    
    
    return 0;
}