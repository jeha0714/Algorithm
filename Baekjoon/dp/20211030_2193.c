#include <stdio.h>

int main() {
    
    int N; scanf("%d", &N);
    
    long long DP[ N + 1 ];
    
    DP[1] = 1; DP[2] = 1;
    
    for (int i = 3 ; i < N + 1 ; i++ )
        DP[i] = DP[ i - 2 ] + DP[ i - 1 ];
    
    printf("%lld", DP[N]);
    
    return 0;
}