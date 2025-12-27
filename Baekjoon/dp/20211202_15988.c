#include <stdio.h>

int dp_Result[ 1000001 ] = {0};


void find( int n )
{
    if ( dp_Result[ n - 1 ] == 0 )
        find( n - 1 );
    
    if ( dp_Result[ n - 2 ] == 0 )
        find( n - 2 );
        
    if ( dp_Result[ n - 3 ] == 0 )
        find( n - 3 );
    
    long long find_Num = ( (long long)dp_Result[ n - 3 ] + (long long)dp_Result[ n - 2 ] + (long long)dp_Result[ n - 1 ] );
    dp_Result[ n ] = ( find_Num % 1000000009 );
}



int main() {
    
    // 테스트 케이스의 개수가 주어짐.
    int num_Test; scanf("%d", &num_Test );
    
    // 초기 값 설정.
    dp_Result[1] = 1; dp_Result[2] = 2; dp_Result[3] = 4;
    
    
    // 테스트 케이스만큼 진행.
    for (int now = 0 ; now < num_Test ; now++ )
    {
        // 정수 offer_Num ( n )이 주어짐.
        int offer_Num; scanf("%d", &offer_Num );
        
        if ( offer_Num == 1 || offer_Num == 2 || offer_Num == 3 )
            printf("%d\n", dp_Result[ offer_Num ] );
        
        else
        {
            find( offer_Num );
            printf("%d\n", dp_Result[ offer_Num ] );
        }
        
    }
    
    
    return 0;
}