#include <stdio.h>

int main() {
    
    int n; scanf("%d", &n); //포도주 잔의 개수 n
    int grape_Amount[ n + 1 ]; // 포도주의 양이 순서대로 주어짐
    for ( int i = 1 ; i <= n ; i++ )
        scanf("%d", &grape_Amount[ i ] );
    
    int max_Glass[ n + 1 ]; // 각 잔에 도달하기까지 최대로 마실 수 있는 포도주의 양.
    int now_Step[ n + 1 ]; // 현재 최대로 마실 수 있는 포도주의 양을 정하기까지 현재 잔에 도달하기까지 연속으로 마신 수
    int result = 0; // 마실 수 있는 포도주의 최대 양을 저장한 변수
    
    max_Glass[0] = 0; // 의미 없는 garbage 값.
    // max_Glass[1]의 값은 grape_Amount[1]의 값을 저장.
    max_Glass[1] = grape_Amount[1]; now_Step[1] = 1;
    
    // n이 2이상인 경우는 max_Glass[2]도 정해줌.
    if ( n >= 2 )
    {
        max_Glass[2] = max_Glass[1] + grape_Amount[2];
        now_Step[2] = 2;
    }
    
    
    for (int now_Index = 3 ; now_Index <= n; now_Index++ )
    {
        // 만약 max_Glass[ now_Index - 1 ]이 2개 이상 연속으로 밟지 않은 경우 현재 잔을 마신다.
        if ( now_Step[ now_Index - 1 ] != 2 )
        {
            max_Glass[ now_Index ] = max_Glass[ now_Index - 1 ] + grape_Amount[ now_Index ];
            now_Step[ now_Index ] = now_Step[ now_Index - 1 ] + 1;
        }
        
        // max_Glass[ now_Index - 1 ]의 now_Step값이 2일 경우 
        else
        {
            int before_Jump = max_Glass[ now_Index - 2 ] + grape_Amount[ now_Index ];
            int before_One = max_Glass[ now_Index - 3 ] + grape_Amount[ now_Index - 1 ] + grape_Amount[ now_Index ];
            int now_Not_choose = max_Glass[ now_Index - 1 ];
            
            if ( before_One < before_Jump )
            {
                if ( now_Not_choose < before_Jump )
                {
                    max_Glass[ now_Index ] = before_Jump;
                    now_Step[ now_Index ] = 1;
                }
                else
                {
                    max_Glass[ now_Index ] = now_Not_choose;
                    now_Step[ now_Index ] = 0;
                }
                
            }
            else // before_One > before_Jump
            {
                if ( now_Not_choose < before_One )
                {
                    max_Glass[ now_Index ] = before_One;
                    now_Step[ now_Index ] = 2;
                }
                else
                {
                    max_Glass[ now_Index ] = now_Not_choose;
                    now_Step[ now_Index ] = 0;
                }
                
            }
            
        }
        
    }
    
    
    //최대값을 [1]부터 차근차근 찾아감.
    for (int i = 1; i <= n ; i++ )
    {
        if ( result < max_Glass[i] )
            result = max_Glass[i];
    }
    
    //결과값을 출력
    printf("%d", result);
    
    return 0;
}