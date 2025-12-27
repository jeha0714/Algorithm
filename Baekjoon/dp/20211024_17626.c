#include <stdio.h>
#include <math.h>


int main()
{
	int n; scanf("%d", &n); // 제곱수들로 나타낼 n
	int DP[ n + 1 ]; // index 1부터 사용 할 것이며 각 index의 제곱수 사용의 최솟값을 저장
	// 0과 1의 DP 배열 초기값 설정.
	DP[0] = 0;
	DP[1] = 1;
	
	// 2부터 차근차근 최소 개수의 제곱수 합을 저장한다.
	for (int now = 2; now <= n ; now++ )
	{
		int min_Make = 1 + DP[ now - ( (int)sqrt( now ) * (int)sqrt( now ) )]; // 해당 now를 최소한으로 만든 개수 
		
		// now를 가장 큰 제곱수부터 빼가면서 가장 최소 개수를 찾음.
		for (int sqrt_Now = (int)sqrt( now ) - 1 ; sqrt_Now >= 1 ; sqrt_Now-- )
		{
			int make_Solution = 1 + DP[ now - ( sqrt_Now * sqrt_Now ) ];
			
			if ( make_Solution < min_Make )
				min_Make = make_Solution;
		}
		
		// 브루트포스로 전부 돈 다음, 최소 개수를 DP 해당 배열 index에 저장
		DP[ now ] = min_Make;
	}
	
	// 결과값 출력
	printf("%d", DP[ n ] );
	
	return 0;
}