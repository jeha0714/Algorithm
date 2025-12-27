#include <stdio.h>

int max( int a, int b)  
{
    return a > b ? a : b;
}


int column = 0, row = 0; // 베열의 행과 열의 크기.


extern int move_Up( int array[column][row], int now_Moving, int now_C, int now_R, int sum_All );
extern int move_Down( int array[column][row], int now_Moving, int now_C, int now_R, int sum_All );
extern int move_Left( int array[column][row], int now_Moving, int now_C, int now_R, int sum_All );
extern int move_Right( int array[column][row], int now_Moving, int now_C, int now_R, int sum_All );




// 배열과 현재위치의 행 열 위치가 주어짐.
int check_T( int array[column][row], int now_C, int now_R )
{
	int now_Moving = 0; // 현재 움직인 수
	
	int num1 = move_Up( array, now_Moving, now_C - 1, now_R, array[ now_C ][ now_R ] );
	
	int num2 = move_Down( array, now_Moving, now_C + 1, now_R, array[ now_C ][ now_R ] );
	
	int num3 = move_Left( array, now_Moving, now_C, now_R - 1, array[ now_C ][ now_R ] );
	
	int num4 = move_Right( array, now_Moving, now_C, now_R + 1, array[ now_C ][ now_R ] );
	
	int max1 = max( num1 , num2 );
	int max2 = max( num3 , num4 );
	
	return max( max1 , max2 );
}

// 위로 움직이는 함수
int move_Up( int array[column][row], int now_Moving, int now_C, int now_R, int sum_All )
{
	if ( now_Moving != 3 )
	{
		if ( now_C < 0 )
			return 0;
		
		else
		{
			int num1 = move_Up( array, now_Moving + 1, now_C - 1, now_R, sum_All + array[ now_C ][ now_R ] );
			
			int num2 = move_Left( array, now_Moving + 1, now_C, now_R - 1, sum_All + array[ now_C ][ now_R ] );
			
			int num3 = move_Right( array, now_Moving + 1, now_C, now_R + 1, sum_All + array[ now_C ][ now_R ] );
			
			int max1 = max( num1, num2 );
			int max2 = max( max1, num3 );
			
			return max2;
		}		
		
	}
	
	else 
		return sum_All;
	
}

// 아래로 움직이는 함수
int move_Down( int array[column][row], int now_Moving, int now_C, int now_R, int sum_All )
{
	if ( now_Moving != 3 )
	{
		if ( now_C >= column )
			return 0;
		
		else
		{
			int num1 = move_Down( array, now_Moving + 1, now_C + 1, now_R, sum_All + array[ now_C ][ now_R ] );
			
			int num2 = move_Left( array, now_Moving + 1, now_C, now_R - 1, sum_All + array[ now_C ][ now_R ] );
			
			int num3 = move_Right( array, now_Moving + 1, now_C, now_R + 1, sum_All + array[ now_C ][ now_R ] );
			
			int max1 = max( num1, num2 );
			int max2 = max( max1, num3 );
			
			return max2;
		}		
		
	}
	
	else
		return sum_All;
	
}

// 왼쪽으로 움직이는 함수
int move_Left( int array[column][row], int now_Moving, int now_C, int now_R, int sum_All )
{
	if ( now_Moving != 3 )
	{
		if ( now_R < 0 )
			return 0;
		
		else
		{
			int num1 = move_Down( array, now_Moving + 1, now_C + 1, now_R, sum_All + array[ now_C ][ now_R ] );
			
			int num2 = move_Left( array, now_Moving + 1, now_C, now_R - 1, sum_All + array[ now_C ][ now_R ] );
			
			int num3 = move_Up( array, now_Moving + 1, now_C - 1, now_R, sum_All + array[ now_C ][ now_R ] );
			
			int max1 = max( num1, num2 );
			int max2 = max( max1, num3 );
			
			return max2;
		}		
		
	}
	
	else
		return sum_All;
	
}

// 오른쪽으로 움직이는 함수
int move_Right( int array[column][row], int now_Moving, int now_C, int now_R, int sum_All )
{
	if ( now_Moving != 3 )
	{
		if ( now_R >= row )
			return 0;
		
		else
		{
			int num1 = move_Down( array, now_Moving + 1, now_C + 1, now_R, sum_All + array[ now_C ][ now_R ] );
			
			int num2 = move_Right( array, now_Moving + 1, now_C, now_R + 1, sum_All + array[ now_C ][ now_R ] );
			
			int num3 = move_Up( array, now_Moving + 1, now_C - 1, now_R, sum_All + array[ now_C ][ now_R ] );
			
			int max1 = max( num1, num2 );
			int max2 = max( max1, num3 );
			
			return max2;
		}		
		
	}
	
	else
		return sum_All;
	
}


int check_FK( int array[column][row], int now_C, int now_R )
{
    
    // 현재 주어진 위치에서 ㅗ 모양으로 만들 수 있는 최대합을 return 함. 수많은 fk모양 중 툭튀어나온곳이 현재 기준값.
    // ㅜ
    int num1 = array[ now_C ][ now_R ] + array[ now_C - 1 ][ now_R ] + array[ now_C - 1 ][ now_R - 1 ] + array[ now_C - 1 ][ now_R + 1 ];

    // ㅗ
    int num2 = array[ now_C ][ now_R ] + array[ now_C + 1 ][ now_R ] + array[ now_C + 1 ][ now_R - 1 ] + array[ now_C + 1 ][ now_R + 1 ];
    
    // ㅓ
    int num3 = array[ now_C ][ now_R ] + array[ now_C ][ now_R + 1 ] + array[ now_C - 1 ][ now_R + 1 ] + array[ now_C + 1 ][ now_R + 1 ];
    
    // ㅏ
    int num4 = array[ now_C ][ now_R ] + array[ now_C ][ now_R - 1 ] + array[ now_C - 1 ][ now_R - 1 ] + array[ now_C + 1 ][ now_R - 1 ];
    
    int max1 = max( num1 , num2 );
	int max2 = max( num3 , num4 );
	
	int a_max = max( max1 , max2 );
	
	
	// 현재 주어진 위치에서 ㅗ 모양으로 만들 수 있는 최대합을 return 함. 수많은 fk모양 중 세 칸으로 둘러쌓인 곳이 현재값.
	// ㅜ
    int num5 = array[ now_C ][ now_R ] + array[ now_C + 1 ][ now_R ] + array[ now_C ][ now_R - 1 ] + array[ now_C ][ now_R + 1 ];

    // ㅗ
    int num6 = array[ now_C ][ now_R ] + array[ now_C - 1 ][ now_R ] + array[ now_C ][ now_R - 1 ] + array[ now_C ][ now_R + 1 ];
    
    // ㅓ
    int num7 = array[ now_C ][ now_R ] + array[ now_C ][ now_R - 1 ] + array[ now_C - 1 ][ now_R ] + array[ now_C + 1 ][ now_R ];
    
    // ㅏ
    int num8 = array[ now_C ][ now_R ] + array[ now_C ][ now_R + 1 ] + array[ now_C - 1 ][ now_R ] + array[ now_C + 1 ][ now_R ];
	
	int max3 = max( num5 , num6 );
	int max4 = max( num7 , num8 );
	
	int b_max = max( max3 , max4 );
	
	
	return max( a_max , b_max );
}




int main(void)
{
	scanf("%d %d", &column, &row ); // 배열의 행과 열의 크기가 주어짐
	int array[ column ][ row ]; // column * row 에 해당하는 배열이 주어지고 그 내부에 값이 주어짐.
	for (int c = 0 ; c < column ; c++ )
	{
		for (int r = 0 ; r < row ; r++ )
			scanf("%d", &array[ c ][ r ] );
	}
	
	int max_Result = 0; // 테트로미노로 만들어지는 4개의 최대값을 저장
	
	// 브루트포스 알고리즘으로 배열 한칸을 기준으로 만들 수 있는 모든 테트로미노중에서
	// 4개의 칸이 한번에 이어질 수 있는 ( ㅗ 모양 제외 ) 합을 계산해서 최대값을 비교하면서 저장.
	for (int c = 0 ; c < column ; c++ )
	{
		for (int r = 0 ; r < row ; r++ )
		{
			// 해당 칸의 최대값을 도출한다.
			int now_Result = check_T( array, c, r );
			
			// 그 값을 저장된 최대값과 비교.
			if ( max_Result < now_Result )
				max_Result = now_Result;
		}
	}	
    
    // 브루트포스 알고리즘으로 배열 한칸을 기준으로 만들 수 있는 모든 테트로미노중에서
	//  ㅗ 모양 합을 계산해서 최대값을 비교하면서 저장.
	for (int c = 1 ; c < column - 1 ; c++ )
	{
		for (int r = 1 ; r < row - 1 ; r++ )
		{
			// 해당 칸의 최대값을 도출한다.
			int now_Result = check_FK( array, c, r );
			
			// 그 값을 저장된 최대값과 비교.
			if ( max_Result < now_Result )
				max_Result = now_Result;
		}
	}	
    

	// 결과값 출력
	printf("%d", max_Result );
	
	return 0;
}