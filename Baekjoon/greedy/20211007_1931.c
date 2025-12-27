#include <stdio.h>
#include <stdlib.h>


int compare( const void * first, const void * second )
{
    // 우선 회의 종료시간이 일찍인것부터 앞에 배치한다.
    if ( *((int *)first + 1 ) < *((int *)second + 1 ) )
    {
        return -1;
    }
    
    else if ( *((int *)first + 1 ) > *((int *)second + 1 ) )
    {
        return 1;
    }
    
    // 회의 종료시간이 같을 경우 회의 시작시간이 이른 순으로 앞에 정리한다.
    else if ( *((int *)first + 1 ) == *((int *)second + 1 ) )
    {
        return ( *((int *)first + 0 ) - *((int *)second + 0 ) );
    }
    
    
}



int main() {
    
    int N; scanf("%d", &N); // 회의의 수
    int info[N][2]; // 회의의 정보
    for (int i = 0 ; i < N ; i++ ) { scanf("%d %d", &info[i][0], &info[i][1] ); }
    int result = 0; // 회의의 개수를 출력.
    int end_Time;
    
    // 퀵소트로 회의 종료시간이 이르면서 시작시간이 이른순으로 정렬.
    qsort( info, N, sizeof( info[0] ), compare);
    
    for (int now_Index = 0 ; now_Index < N ; now_Index++ )
    {
        // 우선 처음에는 회의 종료시간이 가장 이른 회의를 선택
        if ( now_Index == 0 )
        {
            result++;
            end_Time = info[now_Index][1];
        }
        
        // 이후에는 앞선 회의의 종료시간과 이후에 새롭게 시작될 회의의 시작시간을 
        // now_Index를 하나씩 증가시켜가며 차이가 가장 작은 것을 선택.
        else
        {
            if ( info[ now_Index ][0] >= end_Time )
            {
                result++;
                end_Time = info[now_Index][1];
            }
            
        }
        
    }

    
    printf("%d", result);
    
    return 0;
}