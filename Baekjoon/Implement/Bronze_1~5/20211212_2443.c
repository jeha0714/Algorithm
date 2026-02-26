#include <stdio.h>

int main()
{
    int n; scanf("%d", &n);
    
    for ( int make = n ; make > 0 ; make-- )
    {
        for ( int space = n ; space > make ; space-- )
            printf(" ");
        
        for ( int star = 0 ; star < ( 2 * make ) - 1 ; star++ )
            printf("*");
        
        printf("\n");
    }
    

    return 0;
}
