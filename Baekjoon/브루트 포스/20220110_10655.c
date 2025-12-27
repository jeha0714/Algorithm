#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 체크포인트의 개수
    int num_Point; scanf("%d", &num_Point );
    
    // 체크포인트의 위치
    int check_Point_Loca[ num_Point ][ 2 ];
    for (int now = 0 ; now < num_Point ; now++ )
        scanf("%d %d", &check_Point_Loca[ now ][0], &check_Point_Loca[ now ][1] );

    // 체크포인트를 모두 지날 경우의 거리
    int len_All = 0;
    
    // 체크포인트의 위치를 처음부터 끝까지 거리차이를 구하며 len_All과 max_Len의 값을 구함
    for (int i = 0 ; i < num_Point - 1 ; i++ )
    {
        int beside_Len = abs( check_Point_Loca[i][0] - check_Point_Loca[i+1][0] ) +
            abs( check_Point_Loca[i][1] - check_Point_Loca[i+1][1] );
        
        len_All += beside_Len;
    }
    
    // 거리를 가장 짧을 때의 거리값
    int min_Len = len_All;
    
    // loca가 1인 위치부터 건너 뛸경우를 계산하며 건너뛰었을 때 제일 작은 거리를 찾아감.
    // 다만 max_Len이 맨 마지막이 되는 경우는 없애야 함.
    for (int now_Loca = 1; now_Loca < num_Point - 1 ; now_Loca++)
    {
        int now_Len = len_All - 
            ( abs( check_Point_Loca[now_Loca-1][0] - check_Point_Loca[now_Loca][0] ) + abs( check_Point_Loca[now_Loca-1][1] - check_Point_Loca[now_Loca][1] ) ) -
            ( abs( check_Point_Loca[now_Loca][0] - check_Point_Loca[now_Loca+1][0] ) + abs( check_Point_Loca[now_Loca][1] - check_Point_Loca[now_Loca+1][1] ) ) +
            ( abs( check_Point_Loca[now_Loca-1][0] - check_Point_Loca[now_Loca+1][0] ) + abs( check_Point_Loca[now_Loca-1][1] - check_Point_Loca[now_Loca+1][1] ) );
    
        
        if ( now_Len < min_Len )
            min_Len = now_Len;
    }

    // 결과값 출력
    printf("%d", min_Len);

    
    return 0;
}
