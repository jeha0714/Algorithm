#include <stdio.h>

int main()
{
    int n; scanf("%d", &n);
    
    for (int star = 1; star <= n; star++ )
    {
        for (int make = 0; make < star; make++ )
            printf("*");
        
        printf("\n");
    }
    
    for ( int star = n - 1 ; star > 0 ; star-- )
    {
        for (int make = 0; make < star; make++ )
            printf("*");
        
        printf("\n");
    }
    
    

    return 0;
}
