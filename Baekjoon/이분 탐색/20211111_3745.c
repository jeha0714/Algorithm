#include <stdio.h>


// 입력받은 수를 적절한 위치에 삽입하는 알고리즘.
void BNS_IN ( int input_Num, int array[], int A_Index )
{
    int start = 0, end = A_Index - 1;
    int mid = ( start + end ) / 2;
    
    while ( start <= end )
    {
        mid = ( start + end ) / 2;
        
        if ( array[ mid ] < input_Num )
            start = mid + 1;
        else if ( array[ mid ] == input_Num )
            return;
        else
            end = mid - 1;
    }
    
    if ( array[ mid ] < input_Num && array[ mid + 1 ] > input_Num ) 
        array[ mid + 1 ] = input_Num;
    else
        array[ mid ] = input_Num;
    
}




int main() {
    
    int size;
    
    while ( scanf("%d", &size ) != EOF ) // 입력되는 데이터가 없을 때 까지 반복
    {
        int array_Invest[ size ]; // 관찰한 주가를 저장하는 배열
        for (int i = 0 ; i < size ; i++ )
            scanf("%d", &array_Invest[ i ] );
        
        
        int find_Long[ size ]; // 오름세의 길이를 찾기위한 배열
        int fL_Index = 0; // find_Long 배열의 인덱스를 가리키는 변수
        
        
        for ( int Invest_Index = 0 ; Invest_Index < size ; Invest_Index++ )
        {
            // 주가를 관찰한 배열을 나타내는 변수값이 0일 때
            if ( Invest_Index == 0 )
                find_Long[ fL_Index++ ] = array_Invest[ Invest_Index ];
            
            // 주가를 관찰한 배열을 나타내는 변수값이 1이상 일 때
            else
            {
                if ( find_Long[ fL_Index - 1 ] < array_Invest[ Invest_Index ] )
                    find_Long[ fL_Index++ ] = array_Invest[ Invest_Index ];
                    
                else if ( find_Long[ fL_Index - 1 ] == array_Invest[ Invest_Index ] )
                    continue;
                
                else if ( find_Long[ fL_Index - 1 ] > array_Invest[ Invest_Index ] )
                    BNS_IN( array_Invest[ Invest_Index ], find_Long, fL_Index );
                    
            }
            
        }

        
        // 각 케이스 별 결과값 출력
        printf("%d\n", fL_Index );
    }
    
    
    return 0;
}