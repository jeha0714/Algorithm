#include <stdio.h>
#include <stdlib.h>

extern void P(int N, long long* array_P);


int main() {
    
    int T;//테스트 케이스
    long long* array_P = (long long*)malloc(sizeof(long long) * 101); //동적 메모리 저장.
    
    for (int now_Index = 0; now_Index < 101 ; now_Index++) //배열내부의 모든 값을 0으로 초기화.
    {
        array_P[now_Index] = 0;
    }
    
    
    scanf("%d", &T);
    
    
    for (int num_Try = 0; num_Try < T ;num_Try++) //테스트 횟수만큼 진행
    {
        int N;
        scanf("%d", &N);
        
        P(N, array_P);
        
        printf("%lld\n", array_P[N]);
    }
    
    
    return 0;
}



/* 함수 구현 */
void P(int N, long long* array_P)
{
    if (N == 1)
    {
        array_P[1] = 1;
    }
    else if (N == 2)
    {
        array_P[2] = 1;
    }
    else if (N == 3)
    {
        array_P[3] = 1;
    }
    else if (N == 4)
    {
        array_P[4] = 2;
    }
    else if (N == 5)
    {
        array_P[5] = 2;
    }
    else
    {
        if (array_P[N - 1] == 0)
        {
            P(N - 1, array_P);
        }
        
        if (array_P[N - 5] == 0)
        {
            P(N - 5, array_P);
        }
        
        
        array_P[N] = array_P[N - 1] + array_P[N - 5];
    }
    
}
