#include <stdio.h>
#include <stdlib.h>


long long result; // 결과값 Mid를 저장할 변수

// mid로 자른 렌선의 총 개수를 반환하는 함수
long long Calculate(long long Mid, int array_Lan_Length[], int num_Lan_String )
{
    long long can_make_String = 0;
    
    for (int now_Index = 0 ; now_Index < num_Lan_String ; now_Index++ )
    {
        can_make_String += array_Lan_Length[ now_Index ] / Mid;
    }
    
    
    return can_make_String;
}



void BNS( int Start, int End, int array_Lan_Length[], int need_Lan_String, int num_Lan_String )
{
    
    while ( Start <= End ) 
    {
        long long Mid = ( (long long)Start + (long long)End ) / 2;
       // printf("%lld\n", Mid);
        
        // mid 로는 알맞은 수량 >=이 나오고 mid+1로는 알맞은 수량 -1 <=의 값이 나온다면 break
        if ( Calculate( Mid, array_Lan_Length, num_Lan_String) >= need_Lan_String && Calculate( Mid + 1, array_Lan_Length, num_Lan_String ) <= need_Lan_String - 1 )
        {
            result = Mid;
            break;
        }
        
        // mid 값으로 need_Lan_String보다 작을 시 End값을 mid - 1로 설정
        else if ( Calculate( Mid, array_Lan_Length, num_Lan_String ) < need_Lan_String )
        {
            End = Mid - 1;
        }
        
        // mid 값으로 need_Lan_String보다 작을 시 Start값을 mid + 1로 설정
        else if ( Calculate( Mid, array_Lan_Length, num_Lan_String ) > need_Lan_String )
        {
            Start = Mid + 1;
        }
        
        // mid와 mid + 1값 둘다 알맞은 수량으로 나올 시 start값을 mid + 1로 설정
        else if ( Calculate( Mid, array_Lan_Length, num_Lan_String ) == need_Lan_String && Calculate( Mid + 1, array_Lan_Length, num_Lan_String ) == need_Lan_String )
        {
            Start = Mid + 1;
        }
        
    }
    
}




int main() {
    
    int num_Lan_String, need_Lan_String; // 주어진 렌선의 개수와 필요한 렌선의 개수
    scanf("%d %d", &num_Lan_String, &need_Lan_String);
    
    int Lan_Length[ num_Lan_String ]; // num_Lan_String개의 렌선을 저장할 배열
    int max_Lan = 0; // 가장 긴 랜선의 길이를 저장하는 변수
    for (int i = 0 ; i < num_Lan_String ; i++ ) 
    { 
        scanf("%d", &Lan_Length[ i ] ); 
        if ( i == 0 ) max_Lan = Lan_Length[ 0 ];
        else if ( Lan_Length[ i ] > max_Lan ) max_Lan = Lan_Length[ i ];
    }
    
    // 스트링의 길이를 1과 max_Lan의 mid 값부터 시작해서 이분탐색으로 결과값 찾기 시작.
    BNS(1, max_Lan, Lan_Length, need_Lan_String, num_Lan_String);
    
    
    printf("%lld", result);
    
    return 0;
}