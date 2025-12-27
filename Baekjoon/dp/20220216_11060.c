#include <stdio.h>

int main() {
    
    // 미로 크기
    int N; scanf("%d", &N);
    
    // 정수가 적힌 미로를 저장 할 배열
    int array[N];
    for (int i = 0; i < N ; i++)
        scanf("%d", &array[i] );
    
    // 해당 칸에 이동하는 최소한의 횟수를 저장한 배열 처음은 0으로 초기화
    int DP[N]; 
    for (int i = 0; i < N ; i++)
        DP[i] = 0;
    
    // 해당 칸에 이동하는 최소한의 횟수를 저장
    for (int i = 0 ; i < N; i++ )
    {
        if ( i != 0 && DP[i] == 0 )
            continue;
        
        // i 번째 미로구역에 도달 했을 때 이동가능한 구역을 표시함
        for ( int j = i + 1 ; j <= i + array[i] ; j++ )
        {
            // i번째 저장된 정수로 점프한 경우 해당 구역의 값이 초기값인 0 인경우 
            if ( DP[j] == 0 )
                DP[j] = DP[i] + 1;
            
            // i번째 저장된 정수로 점프한 경우 해당 구역의 값이 0이 아니며 i에서 점프했을 때의 경우가 
            // 기존에 j구역으로 이동했을 때 저장된 횟수보다 작은 경우
            else if ( DP[j] != 0 && DP[j] > DP[i] + 1 )
                DP[j] = DP[i] + 1;
        }
    }
    
    // 미로크기가 1이라면 답은 0으로 정해짐
    if ( N == 1 )
        printf("0");
    // DP[N-1]에 저장된 값이 0이라면 미로의 끝에 도달가능한 경우가 없으므로 -1 출력
    else if ( DP[N - 1] == 0 )
        printf("-1");
    // 미로의 끝에 도달 가능할 경우 해당 값이 저장된 DP[N - 1]을 출력
    else
        printf("%d", DP[N - 1] );
    
    
    return 0;
}