#include <stdio.h>


int main() {
    
    // 물품의 수와 버틸 수 있는 무게가 주어짐
    int num_Thing, resist_Weight;
    scanf("%d %d", &num_Thing, &resist_Weight );
    
    // num_Thing개의 물건의 무게와 가치
    int value_Thing[ num_Thing ][ 2 ];
    for (int now = 0 ; now < num_Thing; now++ )
        scanf("%d %d", &value_Thing[ now ][ 0 ], &value_Thing[ now ][ 1 ] );

    // 0부터 resist_Weight무게까지 입력 순서에 맞게 최대가치 저장.
    int DP[ num_Thing ][ resist_Weight + 1 ];
    // 0으로 초기화
    for ( int column = 0 ; column < num_Thing ; column++ )
    {
        for (int row = 0 ; row <= resist_Weight ; row++ )
            DP[ column ][ row ] = 0;
    }
    
    // 입력받은 가치 정보를 순차적으로 접근
    for ( int now = 0 ; now < num_Thing ; now++ )
    {
        // 첫번째 행은 그대로 DP 에 저장
        if ( now == 0 )
        {
            for (int row = value_Thing[ now ][ 0 ]; row <= resist_Weight ; row++ )
                DP[ now ][ row ] = value_Thing[ now ][ 1 ];
        }
        
        // 두번째 행 ( index 1 )부터
        else
        {
            for (int row = 0; row <= resist_Weight ; row++ )
            {
                // 현재 row값과 now번째 입력된 값의 무게의 차가 자연수가 아닐 경우
                // DP 해당 전행 해당 열 의 값 대입
                if ( row - value_Thing[ now ][ 0 ] < 0 )
                    DP[ now ][ row ] = DP[ now - 1 ][ row ];
                
                // 현재 row값과 now번째 입력된 값의 무게의 차가 자연수일 경우
                else
                {
                    // now 값과 DP now -1 행의 row - now의 저장된 값의 합이 DP 해당 전행 해당 열 의 값 보다 작을 경우
                    if ( value_Thing[ now ][ 1 ] + DP[ now - 1 ][ row - value_Thing[ now ][ 0 ] ] <= DP[ now - 1 ][ row ] )
                        DP[ now ][ row ] = DP[ now - 1 ][ row ];
                        
                    else
                        DP[ now ][ row ] = value_Thing[ now ][ 1 ] + DP[ now - 1 ][ row - value_Thing[ now ][ 0 ] ];
            
                } 
            }
        }
        
    }
    
    
    // DP 마지막 값으로 저장된 정보를 출력
    printf("%d", DP[ num_Thing - 1 ][ resist_Weight ] );
    
    return 0;
}