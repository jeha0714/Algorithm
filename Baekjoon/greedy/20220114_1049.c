#include <stdio.h>



int main()
{
    // 끊어진 기타 줄의 개수와 브랜드 수
    int num_break_Line, num_Brand; scanf("%d %d", &num_break_Line, &num_Brand );
    
    // 브랜드 별 줄 가격 저장 배열
    int brand_Array[ num_Brand ][ 2 ];
    for (int column = 0 ; column < num_Brand ; column++ )
        scanf("%d %d", &brand_Array[ column ][ 0 ], &brand_Array[ column ][ 1 ] );
    
    // 줄 하나의 가격이 가장 싼 경우의 값을 저장하는 변수
    int min_One = brand_Array[0][1];
    for (int column = 1 ; column < num_Brand ; column++ )
    {
        if ( min_One > brand_Array[ column ][1] )
            min_One = brand_Array[ column ][1];
    }
    
    // 가장 싸게 살 수 있는 경우를 찾는다.
    int result = min_One * num_break_Line; // 초기값은 하나가격으로 전부 산 경우로 설정
    for (int column = 0 ; column < num_Brand ; column++ )
    {
        // 6개 세트 가격이 하나 *6개의 가격보다 싼 경우
        if ( brand_Array[ column ][0] < min_One * 6 )
        {
            // 끊어진 줄의 수를 딱 맞게 구매하는 경우의 가격
            int now_Price = ( num_break_Line / 6 * brand_Array[ column ][0] ) +
                ( num_break_Line % 6 * min_One );
            
            
            // 끊어진 줄을 6개 세트로 산 경우 now_Price와 비교해서 now_Price를 결정 
            if ( num_break_Line % 6 == 0 )
            {
                if ( num_break_Line / 6 * brand_Array[ column ][0] < now_Price )
                    now_Price = num_break_Line / 6 * brand_Array[ column ][0];
            }
            else 
            {
                if ( ( num_break_Line / 6 + 1 ) * brand_Array[ column ][0] < now_Price )
                    now_Price = ( num_break_Line / 6 + 1 ) * brand_Array[ column ][0];
            }
            
            // 현재 브랜드로 계산된 now_Price가 result보다 싼경우 result값을 변경
            if ( now_Price < result )
                result = now_Price;
        }
        
    }
    
    // 결과값 출력
    printf("%d", result );
    
    return 0;
}
