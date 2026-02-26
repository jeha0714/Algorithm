

#include <stdio.h>

int main()
{
    int n; scanf("%d", &n);
    
    for (int make = 2 * n - 1, space = 0 ; space < n ; make -= 2, space++ )
    {
        for (int s = 0 ; s < space ; s++ )
            printf(" ");
        
        for (int star = 0 ; star < make; star++ )
            printf("*");
        
        printf("\n");
        
    }
    
    for (int make = 3, space = n - 2 ; space >= 0 ; make +=2 , space-- )
    {
        for (int s = 0 ; s < space ; s++ )
            printf(" ");
        
        for (int star = 0; star < make ; star++ )
            printf("*");
            
        printf("\n");
    }
    

    return 0;
}
