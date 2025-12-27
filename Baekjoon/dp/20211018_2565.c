#include <stdio.h>
#include <stdlib.h>


// 전깃줄 구조체 선언
typedef struct 
{
    int start;
    int end;
    
}connect_Line;



//퀵소트 내부 정렬 핵심 함수 (오름차순으로 정렬)
int compare ( const void * first, const void * second )
{
    return ((connect_Line *)first)->start - ((connect_Line *)second)->start; 
}



int main() {
    
    int num_Cable; scanf("%d", &num_Cable ); // 전깃줄의 개수
    connect_Line line[ num_Cable ]; // 연결을 시작하는 위치 번호를 1행, 그 열의 시작하는 번호가 도착하는 번호를 2행
    for (int i = 0 ; i < num_Cable ; i++ ) 
    { 
        scanf("%d", &line[i].start );
        scanf("%d", &line[i].end );
    }
    
    // 퀵소트로 시작하는 위치 번호를 오름차순으로 배열에 정렬
    qsort( line, num_Cable, sizeof( line[0] ), compare);
    
    int max_Length[ num_Cable ]; // 나열되어있는 connect_Num[1][?] 해당수까지 최대로 증가하는 부분수열 길이를 구함
    for (int now_Index = 0; now_Index < num_Cable ; now_Index++ )
    {
        max_Length[ now_Index ] = 1;
        
        for (int sub_Index = now_Index - 1; sub_Index >= 0 ; sub_Index-- )
        {
            if ( line[ sub_Index ].end < line[ now_Index ].end && max_Length[ sub_Index ] >= max_Length[ now_Index ] )
                max_Length[ now_Index ] = max_Length[ sub_Index ] + 1;
        }
        
    }
    
    int max_Result = 0; // 남아있는 전깃줄의 최대 개수를 저장한 변수값
    for (int i = 0 ; i < num_Cable ; i++ )
    {
        if ( max_Result < max_Length[ i ] )
            max_Result = max_Length[i];
    }
    
    
    // 주어진 전깃줄 수에서 최대로 남아있을 수 있는 전깃줄의 수를 빼면 제거해야하는 전깃줄의 최소 개수가 나온다.
    printf("%d", num_Cable - max_Result );
    
    return 0;
}