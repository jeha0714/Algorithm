#include <stdio.h>


// 오름차순 정렬
int compare( const void * first, const void * second )
{
    return *(int *)first - *(int *)second ;
}


int main() {
    
    // n가지 종류의 동전과 k원의 가치의 합
    int n, k; scanf("%d %d", &n, &k);
    
    // n개의 동전 종류가 주어짐.
    int value_Coin[ n ];
    for (int i = 0 ; i < n ; i++ )
        scanf("%d", &value_Coin[i] );
    
    // value_Coin을 오름차순으로 정렬
    qsort( value_Coin, n, sizeof( value_Coin[0] ), compare );
    
    // 해당 인덱스(원)을 만들 때 가장 적게 사용한 동전의 수를 저장한 배열 ( 초기 값은 0으로 설정 )
    int DP[ k + 1 ];
    for (int i = 1 ; i <= k ; i++ )
        DP[i] = 0;
    
    // 동전하나하나를 돌고 가치값을 1부터 k원까지 돌면서 DP를 설정한다.
    for ( int i = 0 ; i < n ; i++ )
    {
        for ( int now_Value = 1; now_Value <= k ; now_Value++ )
        {
            
            // 해당 동전을 최종적으로 사용하는 경우
            if ( now_Value - value_Coin[i] > 0 && DP[ now_Value - value_Coin[i] ] != 0 )
            {  
                // 현재 이미 저장된 값이 존재하다면 그 값보다 더 많은 동전개수를 써야하는 경우 그냥 넘어감.
                if ( DP[ now_Value ] != 0 && DP[ now_Value ] < DP[ now_Value - value_Coin[i] ] + 1 )
                    continue;
                
                // 최종적으로 하나 추가해준다.
                DP[ now_Value ] = DP[ now_Value - value_Coin[i] ] + 1;
            }
            
            
            // DP[ ? ] == 0 인경우 만약 해당 동전으로만 맍족 시킬 수 있는 경우  now_Value / value_Coin[i]값을 저장.
            else if ( now_Value - value_Coin[i] == 0 && now_Value % value_Coin[ i ] == 0 )
                DP[ now_Value ] = now_Value / value_Coin[ i ];
        }
    }
    

    // k를 만들 수 있는 값이 있을 때는 해당 값 출력 없다면 -1출력
    if ( DP[ k ] == 0 )
        printf("-1");
    else
        printf("%d", DP[k] );
    
    
    return 0;
}