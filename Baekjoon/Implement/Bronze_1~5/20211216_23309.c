#include <stdio.h>
#include <string.h>

int main()
{
    char string[ 102 ];
    scanf("%s", string );
    
    int len = strlen( string );
    
    for (int i = 0; i < len ; i++ )
    {
        if ( i != 0 && i % 10 == 0 )
            printf("\n");
            
        printf("%c", string[i] );
    }
    
    

    return 0;
}
