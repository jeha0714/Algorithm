#include <stdio.h>

int main() {
    
    //수열 A의 크기
    int A_Size; scanf("%d", &A_Size );
    
    // 수열 A를 정의
    int array_A[ A_Size ];
    for ( int index = 0 ; index < A_Size ; index++ )
        scanf("%d", &array_A[ index ] );
    
    // dp가 사용될 배열 생성과 내부를 1으로 초기화
    int dp[ A_Size ];
    for ( int index = 0 ; index < A_Size ; index++ )
        dp[ index ] = 1;
    
    // for문 2개를 사용
    for (int main_I = 1; main_I < A_Size ; main_I++ )
    {

        for ( int sub_I = 0 ; sub_I < main_I ; sub_I++ )
        {
            // 기준이 되는 값보다 크고 dp + 1 값이 클 경우 해당 인덱스의 dp + 1 의 값을 저장
            if ( array_A[ sub_I ] > array_A[ main_I ] && dp[ sub_I ] + 1 > dp[ main_I ] )
                dp[ main_I ] = dp[ sub_I ] + 1;
        }

    }
    
    // 최대값
    int max = 0;
    
    // dp 배열을 전부 돌면서 최대값 찾기
    for (int i = 0 ; i < A_Size ; i++ )
    {
        if ( max < dp[ i ] )
            max = dp[i];    
    }
    
    // 최대값 출력
    printf("%d", max );
    
    return 0;
}