#include <stdio.h>

int column_row; // 표의 크기 행과 열의 변수.

int main() {
    
    int test_Case; // 총 테스트 케이스의 수
    int column_row; scanf("%d %d", &column_row, &test_Case ); // 표의 크기인 행과 열이 주어짐.
    
    int array[ column_row ][ column_row ]; // 표에 채울 수들을 저장할 배열
	int DP[ column_row ][ column_row ]; // [0][0] 부터 해당 되는 인덱스 위치까지 직사각형 누적합을 저장하는 배열
    
	// DP 배열을 누적합으로 채워줌.
	for (int c = 0 ; c < column_row ; c++ )
    {
        for (int r = 0 ; r < column_row ; r++ )
		{
            scanf("%d", &array[c][r] );
			
			if ( c == 0 && r == 0 )
				DP[ c ][ r ] = array[ c ][ r ];
				
			else if ( c == 0 && r != 0 )
				DP[ c ][ r ] = DP[ c ][ r - 1 ] + array[ c ][ r ];
			
			else if ( c != 0 && r == 0 )
			    DP[ c ][ r ] = DP[ c - 1 ][ r ] + array[ c ][ r ];
			
			else
				DP[ c ][ r ] = DP[ c ][ r - 1 ] + DP[ c - 1 ][ r ] - DP[ c - 1 ][ r - 1 ] + array[ c ][ r ];
			
		}
    }
    
	//해당되는 값을 출력.
    for (int now_Try = 0 ; now_Try < test_Case ; now_Try++ )
    {
        int start_x, start_y, end_x, end_y; // 누적합을 계산할 배열의 위치를 저장한 변수값 . 실제 index로는 -1을 생각
        scanf("%d %d %d %d", &start_x, &start_y, &end_x, &end_y );
        
        int result; // 결과값을 저장하는 변수
        
        if ( start_x > 1 && start_y > 1 )
            result = DP[ end_x - 1 ][ end_y - 1 ] - DP[ end_x - 1 ][ start_y - 2 ] - DP[ start_x - 2 ][ end_y - 1 ] + DP[ start_x - 2 ][ start_y - 2 ] ;
        
        else if ( start_x == 1 && start_y > 1 )
            result = DP[ end_x - 1 ][ end_y - 1 ] - DP[ end_x - 1 ][ start_y - 2 ];
        
        else if ( start_x > 1 && start_y == 1 )
            result = DP[ end_x - 1 ][ end_y - 1 ] - DP[ start_x - 2 ][ end_y - 1 ];
        
        else if ( start_x == 1 && start_y == 1 )
            result = DP[ end_x - 1 ][ end_y - 1 ];
        
        
        // 결과값 출력
		printf("%d\n", result);
    }

    
    return 0;
}