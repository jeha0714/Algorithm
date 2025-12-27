#include <stdio.h>



int main() {
    
    // 구매하려고 하는 카드의 개수
    int purchase_N; scanf("%d", &purchase_N );
    
    // Pi ~ PN이 주어짐
    int price_Cards_assortment[ purchase_N + 1 ]; // 각 인덱스에 해당 인덱스만큼의 묶음 카드 가격이 주어짐 index 0은 제외
    price_Cards_assortment[0] = 0;
    for ( int i = 1 ; i <= purchase_N ; i++ )
        scanf("%d", &price_Cards_assortment[ i ] );
    
    
    // 각 인덱스에 해당하는 만큼의 카드를 구매한 경우의 최소 가격을 저장함.
    int min_Price_Cards[ purchase_N + 1 ];
    min_Price_Cards[0] = 0; // index 0은 제외 하겠음
    min_Price_Cards[1] = price_Cards_assortment[1]; // 카드 하나를 구매하는 방법은 P1방법 하나임.
    
    
    // 카드 2장부터 구매하려는 카드 장 수 까지 차례대로 최소 구매금액을 찾아나감.
    for (int make_Min = 2 ; make_Min <= purchase_N; make_Min++ )
    {
        // min_Price_Cards 각 인덱스에 해당하는 값은 P(index)으로 초기화하겠음.
        min_Price_Cards[ make_Min ] = price_Cards_assortment[ make_Min ];
        
        for ( int focus = 1 ; focus <= make_Min / 2 ; focus++ )
        {
            // (make_Min - focus)와 (focus)개의 최소 구매 가격의 합으로 이루어진 가격이
            // 기존에 저장된 min_Price_Cards[ make_Min ]가격보다 싼 경우 최신화 해줌
            if ( min_Price_Cards[ make_Min ] > min_Price_Cards[ focus ] + min_Price_Cards[ make_Min - focus ] )
                min_Price_Cards[ make_Min ] = min_Price_Cards[ focus ] + min_Price_Cards[ make_Min - focus ];
        }
        
    }
    
    // 최소값인 결과를 출력한다.
    printf("%d", min_Price_Cards[ purchase_N ] );
    
    return 0;
}