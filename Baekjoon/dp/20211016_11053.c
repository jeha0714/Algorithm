#include <stdio.h>

int main() {
    
    int size_A; scanf("%d", &size_A); //수열 A의 크기
    int array_A[ size_A ]; // 수열 A를 이루고 있는 배열
    for (int index = 0 ; index < size_A ; index++ ) { scanf("%d", &array_A[ index ] ); }
    
    int max_Increase[ size_A ]; // 해당 수까지 오면서 증가하는 부분수열의 길이의 최대값을 저장한 배열.
    int result = 0; // 가장 긴 길이를 저장할 변수값.
    // dp를 통한 해결 알고리즘
    for ( int main_Index = 0 ; main_Index < size_A ; main_Index++ )
    {
        // 첫 시작이므로 첫 값은 1로 대입해준다.
        if ( main_Index == 0 )
            max_Increase[ main_Index ] = 1;
        
        // 2번째 값부터
        else
        {
            // 앞에 수보다 전부 크더라도 자신부터 시작할 수 있으므로 1로 초기화.
            max_Increase[ main_Index ] = 1;
            
            // 반복문으로 main_Index 전의 모든 인덱스를 돌아다난다
            for ( int sub_Index = main_Index - 1 ; sub_Index >= 0; sub_Index-- )
            {
                // 수열의 값은 main_Index가 크면서
                if ( array_A[ sub_Index ] < array_A[ main_Index ] )
                {
                    // 증가하는 수열 부분이 sub_Index가 같거나 클 때 main_Increase값을 다음과 같이 적용한다.
                    if ( max_Increase[ sub_Index ] >= max_Increase[ main_Index ] )
                        max_Increase[ main_Index ] = max_Increase[ sub_Index ] + 1;
                }
                
            }
            
        }
        
    }
    
    // max_Increase 내부를 하나씩 돌면서 최대값을 찾는다.
    for (int index = 0 ; index < size_A ; index++ )
    {
        if ( result < max_Increase[ index ] )
            result = max_Increase[ index ];
    }
    
    // 결과값 출력.
    printf("%d", result);
    
    return 0;
}