#include <stdio.h>

// 이분탐색을 통해 Insert_Num을 array배열 내부에 Insert_Num보다 작은 수중 제일 큰 수 뒤에 배치.
void BNS_In ( int Insert_Num, int array[], int * array_Index )
{
	int start = 0, end = *array_Index - 1;
	int mid = ( start + end ) / 2;
	
	while ( start <= end )
	{
		mid = ( start + end ) / 2;
		
		if ( Insert_Num < array[ mid ] )
			end = mid - 1;
		
		else
			start = mid + 1;		
	}
	
	
	if ( array[ mid ] < Insert_Num && array[ mid + 1 ] > Insert_Num )
	    array[ mid + 1 ] = Insert_Num;
	else
	    array[ mid ] = Insert_Num;
}



int main() {
    
    int num_Powerpole; scanf("%d", &num_Powerpole); // 전봇대의 개수 
    int array_Line[ num_Powerpole + 1 ]; // index1부터 연결되어있는 전선의 위치를 저장
	for (int i = 1 ; i <= num_Powerpole ; i++ ) { scanf("%d", &array_Line[ i ] ); }
	
	int array_Long[ num_Powerpole ]; // 가장 긴 증가 부분 수열을 저장하는 배열
	int aL_Index = 0; // array_Long의 저장할 위치를 나타내는 변수값
	
	// 우선 array_Long[0]에 array_Line[1]의 값을 저장해준다.
	array_Long[ aL_Index++ ] = array_Line[1];
	
	// 가장 긴 부분 증가수열을 찾는다.
	for (int i = 2; i <= num_Powerpole ; i++ )
	{
		// array_Long의 마지막에 저장된 값보다 array_Line의 값이 더 클 경우 저장한다.
		if ( array_Long[ aL_Index - 1 ] < array_Line[ i ] )
			array_Long[ aL_Index++ ] = array_Line[ i ];
		
		// 값이 같다면 continue
		else if ( array_Long[ aL_Index - 1 ] == array_Line[ i ] )
		    continue;
		
		// array_Long의 마지막에 저장된 값보다 array_Line의 값이 더 작을 경우
		// 이분탐색을 통해 적절한 위치를 찾는다
		else if ( array_Long[ aL_Index - 1 ] > array_Line[ i ] )
			BNS_In( array_Line[ i ], array_Long, &aL_Index );
		
	}
	
	// 주어진 전봇대 수에서 가장 길게 증가하는 부분수열을 빼면 제거해야하는 전선의 최소 개수가 주어짐.  
	printf("%d", num_Powerpole - aL_Index);
    
    return 0;
}