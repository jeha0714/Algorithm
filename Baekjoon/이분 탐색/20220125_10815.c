#include <stdio.h>
#include <stdlib.h>


// Qsort 내부 비교 함수
int compare( const void * first, const void * second )
{
    return *(int *)first - *(int *)second;
}

// 해당 카드를 찾기위한 이분탐색 내포 함수
// card배열은 찾아야할 숫자가 들어있는지 판단할 배열, num_Card는 card배열의 총 카드 개수, 
// find_Num은 찾아야할 카드의 숫자 번호
int BNS(int card[], int num_Card, int find_Num )
{
    int start = 0, end = num_Card;
    int mid = ( start + end ) / 2;
    
    int checking = 0;
    
    while ( start <= end )
    {
        if ( card[ mid ] < find_Num )
            start = mid + 1;
        
        else if ( card[ mid ] > find_Num )
            end = mid - 1;
            
        else 
            return 1;
        
        mid = ( start + end ) / 2;
    }
    
    return checking;
}



int main()
{
    // 상근이가 가지고 있는카드의 수
    int N; scanf("%d", &N );
    // 상근이가 가지고 있는 숫자 카드의 종류
    int have_Card[ N ];
    for ( int i = 0 ; i < N ; i++ )
        scanf("%d", &have_Card[ i ] );
    
    // 상근이가 가지고 있는 숫자 카드인지를 구해야 할 정수들
    int M; scanf("%d", &M);
    int Are_U_Have[ M ];
    for ( int i = 0 ; i < M ; i++ )
        scanf("%d", &Are_U_Have[ i ] );
    
    // have_Card배열을 오름차순으로 정렬
    qsort( have_Card, N, sizeof( have_Card[ 0 ] ), compare );
    
    
    // Are_U_Have배열을 돌면서 have_Card내에 해당되는 카드가 있는지 찾기.
    for (int now_Turn = 0 ; now_Turn < M; now_Turn++ )
    {
        int checking;
        
        checking = BNS( have_Card, N, Are_U_Have[ now_Turn ]);
        
        // checking이 1인 경우는 해당 숫자가 있는 경우
        if ( checking == 1 )
            printf("1 ");
        // checking이 0인 경우는 해당 숫자가 없는 경우
        else if ( checking == 0 )
            printf("0 ");
    }
    
    
    return 0;
}
