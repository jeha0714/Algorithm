#include <stdio.h>


int main() {
    
    int N; scanf("%d", &N);
    long long result = 0;
    
    
    for ( int base = 0 ; base <= N; base++ )
    {
        for ( int sub = 0 ; sub <= base ; sub++ )
            result += ( base + sub );
        
    }
    
    printf("%lld", result );
    
    return 0;
}