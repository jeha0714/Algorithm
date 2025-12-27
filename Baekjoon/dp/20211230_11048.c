#include <stdio.h>




int main() {
    
    // 미로의 크기
    int column, row; scanf("%d %d", &column, &row );
    
    // 미로에 놓여 있는 사탕의 개수
    int maze[ column ][ row ];
    
    // 해당 타일 이동까지 얻을 수 있는 최대 사탕 개수
    int candy[ column ][ row ];
    
    // 미로 내에 사탕개수와 candy 해당 타일의 값을 설정.
    for (int now_C = 0; now_C < column; now_C++ )
    {
        for (int now_R = 0 ; now_R < row ; now_R++ )
        {
            scanf("%d", &maze[ now_C ][ now_R ] );
            candy[ now_C ][ now_R ] = 0;
        }
    }
    
    candy[ 0 ][ 0 ] = maze[ 0 ][ 0 ];
    
    for (int now_C = 0; now_C < column; now_C++ )
    {
        for (int now_R = 0 ; now_R < row ; now_R++ )
        {
            //시작은 넘어감.
            if ( now_R == 0 && now_C == 0 )
                continue;
            
            
            // 미로 제일 위 행에 있을 때
            if ( now_C == 0 )
            {
                candy[ now_C ][ now_R ] = candy[ now_C ][ now_R - 1 ] + maze[ now_C  ][ now_R ];
            }
            
            // 미로 제일 왼쪽 열에 있을 때
            else if ( now_R == 0 )
            {
                candy[ now_C ][ now_R ] = candy[ now_C - 1 ][ now_R ] + maze[ now_C  ][ now_R ];
            }
            
            // 그 외 나머지 타일에 있을 때
            else
            {
                // 세가지 수 중 가장 큰 값을 저장
                int try1 = candy[ now_C - 1 ][ now_R - 1 ];
                int try2 = candy[ now_C - 1 ][ now_R ];
                int try3 = candy[ now_C ][ now_R - 1 ];
                
                int max = try1;
                if ( max < try2 )
                    max = try2;
                if ( max < try3 )
                    max = try3;
                
                candy[ now_C ][ now_R ] = max + maze[ now_C ][ now_R ];
            }
            
        }
        
    }
    
    
    printf("%d", candy[ column - 1 ][ row - 1  ]);
    
    return 0;
}