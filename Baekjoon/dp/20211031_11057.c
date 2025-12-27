#include <stdio.h>

int main() {
    
    int N; scanf("%d", &N); // 길이 N의 오르막 수의 개수
    
    // 각 행은 해당 길이를 의미하며 
    // 각 열은 인덱스의 값이 행 길이에 해당하는 오르막 수의 끝의 자리 수를 의미.
    int DP[N + 1][10]; // 즉 끝의 자리 수의 총 개수를 저장함.
    
    // 길이가 1인 오르막 수의 끝 자리 수는 1임.
    for (int index = 0 ; index < 10 ; index++ )
        DP[1][index] = 1;
    
    // 길이가 2이상인 경우
    for (int column = 2; column < N + 1 ; column++ )
    {
        for (int row = 0; row < 10; row++ )
        {
            if ( row == 0 )
                DP[ column ][ row ] = DP[ column - 1 ][ row ] % 10007;
            else
                DP[ column ][ row ] = ( DP[ column ][ row - 1 ] + DP[ column - 1 ][ row ] ) % 10007;
        }
        
    }
    
    // 주어진 행의 모든 값을 더함.
    int result = 0;
    for (int index = 0 ; index  < 10 ; index++ )
        result += DP[ N ][ index ];
        
    printf("%d", result % 10007 );
    
    
    return 0;
}