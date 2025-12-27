#include <stdio.h>

int array_Size; // 게임 판의 크기 array_Size


// 현재 위치에서 이동한 칸의 도달 방법의 수를 늘려주는 함수
void plus_Other( int column, int row, int array[][ array_Size ], unsigned long long location_Reach[][ array_Size ] )
{
    if ( column + array[ column ][ row ] < array_Size && row < array_Size  )
        location_Reach[ column + array[ column ][ row ] ][ row ] += ( location_Reach[ column ][ row ] );
    
    
    if ( column < array_Size && row + array[ column ][ row ] < array_Size  )
        location_Reach[ column ][ row + array[ column ][ row ] ] += ( location_Reach[ column ][ row ] );
    
}



int main() {
    
    scanf("%d", &array_Size ); // 게임 판의 크기 array_Size
    int array[ array_Size ][ array_Size ]; // 게임판
    
    // 게임판 내부 데이터를 입력받음
    for (int column = 0 ; column < array_Size ; column++ )
    {
        for ( int row = 0 ; row < array_Size ; row++ )
            scanf("%d", &array[ column ][ row ] );
    }
    
    
    unsigned long long location_Reach[ array_Size ][ array_Size ]; // 해당되는 배열위치에 도달하는 방법의 수의 값을 저장한 배열
    
    // 배열의 내부값을 우선 0으로 초기화.
    for (int column = 0 ; column < array_Size ; column++ )
    {
        for ( int row = 0 ; row < array_Size ; row++ )
            location_Reach[ column ][ row ] = 0;
    }
    
    // 처음은 시작 위치를 통해 다른 위치로 이동하는 방법의 값을 변경 
    location_Reach[ 0 ] [ 0 ] = 1;
    plus_Other( 0, 0, array, location_Reach );
    
    
    for (int column = 0 ; column < array_Size ; column++ )
    {
        for ( int row = 0 ; row < array_Size ; row++ )
        {
            // 시작하는 위치의 값은 건너 뛴다.
            if ( column == 0 && row == 0 )
                continue;
                
            // 해당 위치의 도달하는 방법이 0 인경우 다음으로 건너뛴다.
            if ( location_Reach[ column ][ row ] == 0 )
                continue;
            
            // 배열의 끝에 도달할 시 종료
            if ( column == array_Size - 1 && row == array_Size - 1 )
                break;
            
            // 해당 위치의 도달하는 방법이 1이상인 경우 해당 위치의 이동을 통하여
            // 다른 위치로 이동하는 방법의 수를 +(해당 위치의 도달하는 방법의 수) 해준다.
            else 
            {
                plus_Other( column, row, array, location_Reach );
            }
            
            
        }
        
    }
    
    // 답 출력
    printf("%llu", location_Reach[ array_Size - 1 ][ array_Size - 1 ] );
    
    
    return 0;
}