#include <stdio.h>

int main() {
    
    int n; scanf("%d", &n);
    
    for ( int make = 1 ; make <= n ; make++ )
    {
        for ( int space = n ; space > make ; space-- )
            printf(" ");
        
        for ( int star = 0 ; star < make * 2 - 1  ; star++ )
            printf("*");
        
        printf("\n");
    }
    
    for ( int make = n - 1 ; make >= 1 ; make-- )
    {
        for ( int space = n ; space > make ; space-- )
            printf(" ");
        
        for ( int star = 0 ; star < make * 2 - 1 ; star++ )
            printf("*");
            
        printf("\n");
    }
    
    
    return 0;
}