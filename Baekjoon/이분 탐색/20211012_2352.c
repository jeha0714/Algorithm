#include <stdio.h>

// change_Num보다 작은 수 중 가장 큰 수 뒤에 대입한다. ( 작은 수가 없다면 가장 앞에 설치.)
// 이를 위해 적절한 위치를 찾는데 이분탐색 사용됨.
void BNS( int change_Num, int result[], int last_Index )
{
    int left = 0;
    int right = last_Index;
    int mid = 0;
    
    while ( left <= right )
    {
        mid = ( left + right ) / 2;
        
        if ( result[ mid ] < change_Num )
            left = mid + 1;
            
        else
            right = mid - 1;
        
    }
    
    if ( result[ mid ] < change_Num && result[ mid + 1 ] > change_Num )
        result[ mid + 1 ] = change_Num;
    else
        result[ mid ] = change_Num;

}



int main(void)
{
    int num; scanf("%d", &num); // 포트의 수
    int want_Access_Port[ num ]; // 1번 포트부터 num 포트까지 연결되어야 하는 포트 번호가 주어진 배열.
    for (int index = 0 ; index < num ; index++ ) { scanf("%d", &want_Access_Port[ index ] ); }
    
    int result[ num ]; // LIS 알고리즘을 사용하기 위해 이용되는 배열.
    int result_Index = 0; // result배열에 현재 인덱스 위치를 나타내주는 인덱스 변수값.
    
    for ( int now_Index = 0; now_Index < num ; now_Index++ )
    {
        if ( result_Index == 0 ) // result배열이 비었을 경우는 무조건 하나를 대입.
            result[ result_Index++ ] = want_Access_Port[ now_Index ];
        else // result배열에 하나라도 값이 있는 경우
        {
            // want_Access_Port[ now_Index ]의 값보다 result[ result_Index - 1 ] 값이 작은 경우
            // want_Access_Port[ now_Index ]를 result[ result_Index ]에 삽입.
            if ( result[ result_Index - 1 ] < want_Access_Port[ now_Index ] )
                result[ result_Index++ ] = want_Access_Port[ now_Index ];
                
            // want_Access_Port[ now_Index ]의 값보다 result[ result_Index - 1 ] 값이 큰 경우
            // 이분탐색을 통해 적절한 위치에 값을 대체.
            else if ( result[ result_Index - 1 ] > want_Access_Port[ now_Index ] )
                BNS( want_Access_Port[ now_Index ], result, result_Index - 1 );
            
            // 같은 경우 빠르게 넘긴다.
            else
                continue;
        }
            
    }

    
    // 현재 now_Index값 ( 다음으로 값이들어갈 배열의 위치 = 현재 수가 들어있는 총 합계 )을 출력.
    printf("%d", result_Index );
    
    return 0;
}