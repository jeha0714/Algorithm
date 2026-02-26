#include <stdio.h>

int main()
{
    int n; scanf("%d", &n);
    
    for ( int now = n - 1 ; now > 0 ; now-- )
    {
        for (int space = 0 ; space < now ; space++ )
            printf(" ");
        
        for (int star = 0 ; star < n - now ; star++ )
            printf("*");
        
        
        printf("\n");
    }
    
    for (int now = 0 ; now < n ; now++ )
        printf("*");
    printf("\n");
    
    for ( int now = 1 ; now < n ; now++ )
    {
        for (int space = 0 ; space < now ; space++ )
            printf(" ");
        
        for (int star = 0 ; star < n - now ; star++ )
            printf("*");
        
        
        printf("\n");
    }
    
    

    return 0;
}
