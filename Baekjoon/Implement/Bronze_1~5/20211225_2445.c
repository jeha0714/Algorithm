#include <stdio.h>

int main()
{
    int num; scanf("%d", &num );
    
    for (int i = 1 ; i < num ; i++ )
    {
        for (int star = 0 ; star < i ; star++ )
            printf("*");
        
        for (int space = num ; space > i ; space-- )
            printf(" ");
            
        for (int space = num ; space > i ; space-- )
            printf(" ");
        
        for (int star = 0 ; star < i ; star++ )
            printf("*");
        
        printf("\n");
    }
    
    for (int i = 1 ; i <= 2 * num ; i++ )
        printf("*");
    printf("\n");
    
    for (int i = num - 1 ; i > 0 ; i--)
    {
        for (int star = 0 ; star < i ; star++ )
            printf("*");
        
        for (int space = num ; space > i ; space-- )
            printf(" ");
        
        for (int space = num ; space > i ; space-- )
            printf(" ");
        
        for (int star = 0 ; star < i ; star++ )
            printf("*");
        
        printf("\n");
    }
    

    return 0;
}
