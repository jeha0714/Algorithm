#include <stdio.h>


int main() {
    
    int t; scanf("%d", &t );
    
    int now = 1;
    
    for (int i = 0 ; i < t ; i++ )
    {
        int num1, num2; scanf("%d %d", &num1, &num2 );
        
        if ( num1 == now )
            now = num2;
        
        else if ( num2 == now )
            now = num1;
        
        else
            continue;
    }
    
    printf("%d", now);
    
    return 0;
}