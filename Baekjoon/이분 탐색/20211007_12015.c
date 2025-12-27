#include <stdio.h>

// 이분 탐색을 통해 적당한 위치에 change_Num을 삽입해준다.
void BNS( int change_Num, int result_Array[], int result_Array_Size )
{
    int left = 0;
    int right = result_Array_Size;
    int mid = (left + right) / 2;
    
    
    while ( left <= right )
    {
        mid = (left + right) / 2;
        
        // 값이 같다면 삽입하지 않는다.
        if ( result_Array[ mid ] == change_Num )
            return;
        
        else if ( result_Array[ mid ] < change_Num )
            left = mid + 1;
        
        else if ( result_Array[ mid ] > change_Num )
            right = mid - 1;

    }
    
    // result_Array[ mid - 1] 보다 크고 result_Array[ mid ]보다 작은 경우에만 change_Num을 삽입한다.
    if ( result_Array[ mid ] < change_Num )
        result_Array[ mid + 1 ] = change_Num;
    else if ( result_Array[ mid ] > change_Num )
        result_Array[ mid ] = change_Num;
    
}



int main() {
    
    int sequence_Size; scanf("%d", &sequence_Size); //수열 sequence_A의 사이즈.
    int sequence_A[sequence_Size];
    for (int i = 0 ; i < sequence_Size ; i++) { scanf("%d", &sequence_A[ i ]); }
    
    int result_Array[ sequence_Size ]; // 결과 값이 들어가게 될 배열
    int Insert_Index = 0; // 어떠한 수기 result_Array에 들어가야 할 배열의 위치
    
    for (int now_Index = 0 ; now_Index < sequence_Size ; now_Index++ )
    {
        if ( Insert_Index == 0 ) // result_Array가 비어있을 경우 한칸은 채워준다.
            result_Array[ Insert_Index++ ] = sequence_A[ now_Index ];
        
        else
        {
            // result_Array의 맨 뒤 수가 sequence_A의 now_Index의 값보다 작을 경우 Insert_Index에 삽입.
            if ( result_Array[ Insert_Index - 1 ] < sequence_A[ now_Index ] )
                result_Array[ Insert_Index++ ] = sequence_A[ now_Index ];
            
            // result_Array의 맨 뒤 수가 sequence_A의 now_Index의 값과 같은 경우 continue로 다음 반복문 진행.
            else if ( result_Array[ Insert_Index - 1 ] == sequence_A[ now_Index ] )
                continue;
            
            // result_Array의 맨 뒤 수가 sequence_A의 now_Index의 값보다 클 경우
            // 해당 값을 BNS를 통해 적당한 위치에 삽입.
            else if ( result_Array[ Insert_Index - 1 ] > sequence_A[ now_Index ] )
            {
                BNS( sequence_A[ now_Index ], result_Array, Insert_Index - 1 );
            }
                
        }
        
        
    }

    // 현재 저장되어 있는 수를 출력.
    printf("%d", Insert_Index );
    
    return 0;
}