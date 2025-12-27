#include <stdio.h>

void find_Solution( int DP[], int n )
{
	if ( n == 1 )
		DP[1] = 1;
	else if ( n == 2 )
		DP[2] = 2;
	else if ( n == 3 )
		DP[3] = 4;
	else if ( n == 4 )
		DP[4] = 7;	
		
	else
	{
		if ( DP[ n - 4 ] == 0 )
			find_Solution( DP, n - 4 );
			
		if ( DP[ n - 1 ] == 0 )
			find_Solution( DP, n - 1 );
		
		DP[ n ] = DP[ n - 1 ] * 2 - DP[ n - 4 ];
	}
	
}


int main(void)
{
	int T; scanf("%d", &T); // 테스트 케이스의 수 T
	int DP[ 11 ] = {0};
	
	for (int i = 0 ; i < T ; i++ )
	{
		int num; scanf("%d", &num); // 각 테스트 케이스의 정수
		find_Solution( DP, num );
		
		printf("%d\n", DP[ num ]);
	}
	
	
	return 0;
}