#include <stdio.h>


int main()
{
	int T; scanf("%d", &T); // 테스트 케이스의 개수 T
	for (int now_Try = 0 ; now_Try < T ; now_Try++ )
	{
		int n; scanf("%d", &n); // 2*n에서 n의 크기
		int Sticker[2][n]; // 스티커의 배열
		for (int column = 0 ; column < 2; column++ ) // 스티커 배열 내부 값 입력.
		{
			for ( int row = 0 ; row < n ; row++ )
			    scanf("%d", &Sticker[ column ][ row ] ); 
		
		}
	
		int max_Sum[2][n]; // 각 열을 기준으로 해당 열의 수를 선택하면서 해당 열을 오기까지 나오는 최대값 저장.
		for ( int now_Row = 0 ; now_Row < n; now_Row++ )
		{
			// now_Row가 0 or 1인 경우는 값을 미리 정해준다.
			if ( now_Row == 0 )
			{
				max_Sum[0][ now_Row ] = Sticker[0][0];
				max_Sum[1][ now_Row ] = Sticker[1][0];
			}
			else if ( now_Row == 1 )
			{
				max_Sum[0][ now_Row ] = max_Sum[1][0] + Sticker[0][ now_Row ];
				max_Sum[1][ now_Row ] = max_Sum[0][0] + Sticker[1][ now_Row ];
			}
			
			// now_Row >= 2인 경우
			else
			{
				// 아래는 현재 열보다 2번 뒤로간 열의 행 값중 최대값을 정함
				int max_minus2_Row = max_Sum[0][ now_Row - 2 ] > max_Sum[1][ now_Row - 2 ] ? max_Sum[0][ now_Row - 2 ] : max_Sum[1][ now_Row - 2 ];
				
				
				// max_Sum[0][ now_Row ] 값의 최대값을 정해준다
				if ( max_minus2_Row < max_Sum[1][ now_Row - 1 ] )
					max_Sum[0][ now_Row ] = max_Sum[1][ now_Row - 1 ] + Sticker[0][ now_Row ];
				else
					max_Sum[0][ now_Row ] = max_minus2_Row + Sticker[0][ now_Row ];
				
				// max_Sum[1][ now_Row ] 값의 최대값을 정해준다
				if ( max_minus2_Row < max_Sum[0][ now_Row - 1 ] )
					max_Sum[1][ now_Row ] = max_Sum[0][ now_Row - 1 ] + Sticker[1][ now_Row ];
				else
					max_Sum[1][ now_Row ] = max_minus2_Row + Sticker[1][ now_Row ];
				
			}
		
		}
		
		
		// 마지막 열의 두 값중 더 큰 값을 출력
		if ( max_Sum[0][ n - 1 ] < max_Sum[1][ n - 1 ] )
			printf("%d\n", max_Sum[1][ n - 1 ] );
		else
			printf("%d\n", max_Sum[0][ n - 1 ] );
	
	}	
	
	return 0;
}