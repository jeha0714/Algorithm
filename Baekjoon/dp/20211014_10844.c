#include <stdio.h>


int main() {
    
    int N; scanf("%d", &N); //길이가 N인 계단 수
    int sum_All = 0; // 길이가 N인 계단 수를 모두 저장한 변수
    int last_Num[101][10] = {0}; // 마지막 자리수가 0~10까지며 각 행은 계단의 길이를 의미함. 
    
    // 1행(길이가 1인 경우)을 모든 끝의 자리 수를 1로 저장.
    for ( int num = 1 ; num < 10 ; num++ )
        last_Num[1][num] = 1;
    
    // 해당 자리 길이의 끝의 숫자를 이용해서 다음 자리 길이의 끝의 숫자를 파악한다.
    // 이때 미리 1000000000으로 나누어준다.
    for ( int now_Stair = 2; now_Stair <= N; now_Stair++ )
    {
        for( int column_last_Num = 1; column_last_Num < 9 ; column_last_Num++ )
        {
            last_Num[ now_Stair ][ column_last_Num ] += last_Num[ now_Stair - 1 ][ column_last_Num - 1 ];
            last_Num[ now_Stair ][ column_last_Num ] += last_Num[ now_Stair - 1 ][ column_last_Num + 1 ];
            
            last_Num[ now_Stair ][ column_last_Num ] %= 1000000000;
        }
        
        
        last_Num[ now_Stair ][ 0 ] += last_Num[ now_Stair - 1 ][ 1 ];
        last_Num[ now_Stair ][ 0 ] %= 1000000000;
        last_Num[ now_Stair ][ 9 ] += last_Num[ now_Stair - 1 ][ 8 ];
        last_Num[ now_Stair ][ 9 ] %= 1000000000;
    }
        
    
    // 해당 자리수를 모두 더함과 동시에 1000000000으로 나눈 나머지를 저장.
    for ( int num = 0 ; num < 10 ; num++ )
    {
        sum_All += last_Num[N][num];
        sum_All %= 1000000000;
    }
    
    // 결과값 출력
    printf("%d", sum_All);
    
    return 0;
}