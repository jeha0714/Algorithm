#include <stdio.h>
#include <stdlib.h>


int compare ( const void * num1 , const void * num2 )
{
    return (*(int *)num1) - (*(int *)num2);
}


// atm을 사용하는데 걸리는 시간이 제일 작은 사람부터 오름차순으로 정렬 후
//맨 앞 사람이 사용한 시간부터 N - @ (@는 현재까지 이용한 사람들)씩 곱해서 그 값을 차례차례 더해가면 된다.

int main() {
    
    int N, min_Time = 0, try_Time; //N은 인원 수 , min_Time은 최소시간이 저장될 변수, try_Time은 각 사람이 다른 사람에게 영향을 입힌 횟수
    
    scanf("%d", &N);
    try_Time = N;
    int array_Time[N]; 
    
    for (int now_Index = 0 ; now_Index < N; now_Index++) { scanf("%d", &array_Time[now_Index] ); }
    
    
    qsort (array_Time, N , sizeof(array_Time[0]), compare); //정렬.
    
    
    for (int now_Index = 0; now_Index < N; now_Index++, try_Time--)
    {
        min_Time += array_Time[now_Index] * try_Time;
    }
    
    printf("%d", min_Time);
    
    return 0;
}