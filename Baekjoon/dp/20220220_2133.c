#include <stdio.h>

// 점화식을 이용한 문제.
//F(N) = F(N - 1) * F(2) + 2 * ( F(N-4) + F(N-6) + ... + F(4) + F(2) + F(0) )

int main()
{
    // N짜리의 벽이 주어짐
    int N; scanf("%d", &N);
    
    int DP[ N + 1 ];
    DP[2] = 3; DP[0] = 1;
    
    int up = DP[0];
    
    for (int i = 4 ; i <= N ; i+=2 )
    {
        DP[i] = DP[ i - 2 ] * 3 + 2 * up;
        up += DP[i - 2];
    }
    
    printf("%d", DP[N] );

    return 0;
}
