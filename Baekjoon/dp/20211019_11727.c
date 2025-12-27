#include <stdio.h>

int main() {
    
    int n; scanf("%d", &n);
    int DP[n + 1]; // 2*? 해당하는 직사각형을 채우는 방법의 수를 저장한 배열
    
    DP[1] = 1;
    for (int now_Size = 2; now_Size <= n ; now_Size++ )
    {
        if ( now_Size % 2 == 0 )
            DP[ now_Size ] = ( DP[ now_Size - 1 ] * 2 + 1 ) % 10007;
        else
            DP[ now_Size ] = ( DP[ now_Size - 1 ] * 2 - 1 ) % 10007;
    }
    
    
    printf("%d", DP[ n ] );
    
    return 0;
}