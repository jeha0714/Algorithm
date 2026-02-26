#include <stdio.h>



int main() {
    
    int test; scanf("%d", &test );
    
    for (int i = 0 ; i < test ; i++ )
    {
        int left_M; scanf("%d", &left_M );
        
        printf("%d ", left_M / 25 ); left_M %= 25;
        
        printf("%d ", left_M / 10 ); left_M %= 10;
        
        printf("%d ", left_M / 5 ); left_M %= 5;
        
        printf("%d\n", left_M / 1 );
    }
    
    
    return 0;
}