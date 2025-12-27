#include <stdio.h>



int main()
{
    // 수열 A의 크기가 주어짐.
    int size_A; scanf("%d", &size_A );
    
    // size_A크기의 배열 생성 후 내부 값을 순차적으로 등록.
    int array_A[ size_A ];
    for (int i = 0 ; i < size_A ; i++ )
        scanf("%d", &array_A[ i ] );
    
    
    // array_A의 0~size_A - 1 인덱스까지 오면서 만들 수 있는 가장 큰 증가 부분 수열의 합을 각 인덱스별로 저장. 
    int DP[ size_A ];
    DP[0] = array_A[0]; // 인덱스 0까지 오면서 만들 수 있는 최대 부분 수열 합은 array_A[0]이므로 해당 값으로 초기값 저장.
   
    for (int main_I = 1; main_I < size_A ; main_I++ )
    {
        // DP[ main_I ] 초기값을 해당 인덱스에 저장된 array_A값으로 설정
        DP[ main_I ] = array_A[ main_I ];
        
        // main_I 앞 인덱스 전체를 돌면서
        // array_A[ main_I ]에 저장된 값보다 작으면서 DP[ main_I ]에 저장된 값보다 앞 인덱스 + array_A[main_I] 값이 크다면
        // DP[ sub_I ] + array_A[ main_I ]값으로 DP[ main_I ]를 최신화.
        for (int sub_I = 0 ; sub_I < main_I ; sub_I++ )
        {
            if ( array_A[ sub_I ] < array_A[ main_I ] && DP[ sub_I ] + array_A[ main_I ] > DP[ main_I ] )
                DP[ main_I ] = DP[ sub_I ] + array_A[ main_I ];
        }
    }
    
    // DP 내부를 돌면서 최대값을 찾은 후 출력
    int max = 0;
    for (int i = 0 ; i < size_A ; i++ )
    {
        if( max < DP[ i ] )
            max = DP[ i ];
    }
    printf("%d", max );
    
    return 0;
}
