#include <stdio.h>

int main() {
    
    int tri_Size; scanf("%d", &tri_Size); // 삼각형의 크기
    int triangle[ tri_Size ][ tri_Size ]; // 정수 삼각형이 저장되는 배열.
    int max_tri[ tri_Size ][ tri_Size ]; // 각 column row에서 가장 큰 값을 만든 값을 저장하는 배열.
    int max_Num = 0; // 결과값을 저장하는 변수
    
    // 정수 삼각형을 입력받는다.
    for (int column = 0 ; column < tri_Size ; column++ )
    {
        for (int row = 0 ; row <= column; row++ )
        {
            scanf("%d", &triangle[ column ][ row ] );
            max_tri[ column ][ row ] = 0;
        }
    }
    
    // max_tri에서 각 배열 내부의 값은 가장 위층에서 해당 배열까지 내려오면서 가장 크게 만들 수 있는 값을 저장.
    max_tri[0][0] = triangle[0][0];
    for (int column = 1; column < tri_Size ; column++ )
    {
        for (int row = 0 ; row <= column; row++ )
        {
            // row == 0 일 시
            if ( row == 0 )
                max_tri[ column ][ row ] = max_tri[ column - 1 ][ 0 ] + triangle[ column ][ row ];
            
            // row == column일 시
            else if ( row == column )
                max_tri[ column ][ row ] = max_tri[ column - 1 ][ row - 1 ] + triangle[ column ][ row ];
            
            else
            {
                // 삼각형의 양끝을 제외한 나머지들은 삼각형의 위부터 아래로 내려오면서 가장 큰값을 선택해야 함.
                if ( max_tri[ column - 1 ][ row - 1 ] < max_tri[ column - 1 ][ row ] )
                    max_tri[ column ][ row  ] = max_tri[ column - 1 ][ row ] + triangle[ column ][ row ];
                else
                    max_tri[ column ][ row  ] = max_tri[ column - 1 ][ row - 1 ] + triangle[ column ][ row ];
            }
            
        }
        
    }
    
    
    
    
    
    // 마지막 column에서 가장 큰 값을 찾아내기.
    for (int now_Index = 0 ; now_Index < tri_Size ; now_Index++ )
    {
        if ( max_Num < max_tri[ tri_Size - 1][ now_Index ] )
            max_Num = max_tri[ tri_Size - 1 ][ now_Index ];
    }
    
    // 결과값 출력
    printf("%d", max_Num);
    
    return 0;
}