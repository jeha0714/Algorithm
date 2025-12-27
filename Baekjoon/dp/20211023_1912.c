#include <stdio.h>

int main()
{
	int n; scanf("%d", &n); // n개의 정수가 주어짐.
	int array_N[ n ]; // n개의 정수가 저장되는 배열
	for (int index = 0; index < n ; index++ ) { scanf("%d", &array_N[ index ] ); }
	
	int max_Now[ n ]; // 현재 인덱스까지의 최대값.
	max_Now[ 0 ] = array_N[ 0 ]; // 첫번째 값을 대입.
	for (int now_Index = 1 ; now_Index < n ; now_Index++ )
	{
	    // 전 인덱스의 누적합이 0이하라면
	    if ( max_Now[ now_Index - 1 ] <= 0 )
	    {
	        // 현재 인덱스의 누적합은 현재 인덱스의 값으로 시작.
	        max_Now[ now_Index ] = array_N[ now_Index ];
	    }
	    
	    // 전 인덱스의 누적합이 1이상이라면
	    else if ( max_Now[ now_Index - 1 ] > 0 )
	    {
	        // 전 인덱스까지의 최대값과 현재 인덱스의 값을 더함.
    		int plus_now_Num = max_Now[ now_Index - 1 ] + array_N[ now_Index ];
    		
    	    // 전 인덱스의 누적합과 현재 인덱스의 값의 합이 1이상인 경우 현재 인덱스 누적합에 저장
    		if ( plus_now_Num > 0 )
    			max_Now[ now_Index ] = plus_now_Num;
    		
    		// 전 인덱스의 누적합과 현재 인덱스의 값의 합이 0이하인 경우 현재 인덱스에 0저장.
    		else
    		{
    			max_Now[ now_Index ] = 0;
    		}
    		
	    }

	}
	
	// 저장된 max_Now 배열내부의 값들 중 가장 큰 값을 색출.
	int max_Result = max_Now[0];
	for (int now_Index = 1 ; now_Index < n ; now_Index++ )
	{
	    if ( max_Result < max_Now[ now_Index ] )
	        max_Result = max_Now[ now_Index ];
	}
	
	// 결과값 출력
	printf("%d", max_Result);
	
	return 0;
}