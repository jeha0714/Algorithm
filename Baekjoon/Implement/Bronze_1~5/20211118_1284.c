#include <stdio.h>
#include <string.h>


int main() {
    
    char number[ 10000 ]; 
    scanf("%s", number );
    
    while ( strcmp( number, "0" ) != 0 )
    {
        int num_Len = strlen( number );
        int size = 0;
        
        for (int i = 0 ; i < num_Len ; i++ )
        {
            if ( number[ i ] == '1' )
                size += 2;
            else if ( number[ i ] == '0' )
                size += 4;
            else
                size += 3;
        }
        size += ( num_Len + 1 );
        
        printf("%d\n", size);
        scanf("%s", number );
    }
    
    
    
    return 0;
}