#include <stdio.h>
#include <stdlib.h>

// 매인 도우의 가격과 토핑 하나당의 가격 
int main_Fee = 0, sub_Fee = 0;

// 1g당 열량이 높은 순으로 내림차순으로 정렬하는 qsort compare 함수
int compare( const void * first, const void * second )
{
    if ( (((double)*(int *)first) / (double)sub_Fee ) < ( ((double)*(int *)second) / (double)sub_Fee ) )
        return 1;
    else if ( (((double)*(int *)first) / (double)sub_Fee ) == ( ((double)*(int *)second) / (double)sub_Fee ) )
        return 0;
    else
        return -1;
}


int main() {
    
    // 토핑의 총 개수 
    int num_Sub; scanf("%d", &num_Sub );
    
    // 매인 도우의 가격과 토핑 하나당의 가격 
    scanf("%d %d", &main_Fee, &sub_Fee );
    
    // 메인도우의 열량과 각 토핑의 열량이 주어짐.
    int main_Kcal; scanf("%d", &main_Kcal );
    int sub_Array[ num_Sub ];
    for (int i = 0 ; i < num_Sub ; i++ )
        scanf("%d", &sub_Array[ i ] );
    
    // 각 토핑의 열량이 저장된 배열을 1원 당 열량 내림차순으로 저장.
    qsort( sub_Array, num_Sub, sizeof( sub_Array[0] ), compare);
    
    // 총 가격과 총 열량이 주어짐
    int total_Fee = 0, total_Kcal = 0;
    double main_per_Kcal = (double)main_Kcal / (double)main_Fee;
    
    // 메인도우는 무조건 포함되고 가격당 열량이 메인도우와 같거나 큰 경우만 토핑을 추가시킨다.
    total_Fee += main_Fee; total_Kcal += main_Kcal;
    for (int i = 0 ; i < num_Sub ; i++ )
    {
        // 메인도우보다 1g당 열량이 같거나 높아야 하며
        if ( main_per_Kcal <= (double)sub_Array[i] / (double)sub_Fee )
        {
            // 해당 토핑을 추가했을 때 이전 토핑까지 포함했을 때 구한 1g당 열량 값보다 크거나 같아야 한다.
            if ( (double)total_Kcal / (double)total_Fee <= (double)( total_Kcal + sub_Array[i] ) / (double)( total_Fee + sub_Fee ) )
            {
                total_Fee += sub_Fee; total_Kcal += sub_Array[i];
            }
        }
    }
    
    // 총 열량을 총 가격으로 나눈 값이 주어짐.
    printf("%d", total_Kcal / total_Fee );
    
    return 0;
}