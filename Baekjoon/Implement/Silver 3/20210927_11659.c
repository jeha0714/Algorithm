#include <stdio.h>

int main() {
    
    int num_All, test_Case; // 숫자의 개수와 테스트 케이스의 수
    
    scanf("%d %d", &num_All, &test_Case);
    
    int num_Array[num_All], sum_now_Index[num_All]; // num_All개의 수가 저장될 배열과 누적합이 저장될 배열
    
    for (int now_Index = 0 ; now_Index < num_All ; now_Index++ )
    {
        scanf("%d", &num_Array[ now_Index ] );
        sum_now_Index[ now_Index ] = 0; // 0으로 초기화.
        
        if ( now_Index == 0 )
            sum_now_Index[ now_Index ] = num_Array[ now_Index ]; //now_Index가 0인 경우 -1 인덱스가 존재하지 않으므로 누적합 불가능
        else
            sum_now_Index[ now_Index ] = num_Array[ now_Index ] + sum_now_Index[ now_Index - 1 ]; // now_Index 가 1이상부터 누적합 저장 진행
    }
  
    
    // 누적합을 이용하여 계산
    for (int now_Try = 0 ; now_Try < test_Case; now_Try++ )
    {
        int start, end; // start부터 end까지 의 합을 출력
        scanf("%d %d", &start, &end );
        
        if ( start == end )
            printf("%d\n", num_Array[ start - 1 ] );
        
        else 
        {
            if ( start == 1 )
                printf("%d\n", sum_now_Index[ end - 1 ]);
            else
                printf("%d\n", sum_now_Index[ end - 1 ] - sum_now_Index[ start - 2 ] );
        }
        
    }
    
    
    
    
    return 0;
}