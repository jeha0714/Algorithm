
#include <stdio.h>
#include <string.h>

int main()
{
    char string[51]; scanf("%s", string);
    int string_Len = strlen( string );
    
    int result = 10;
    
    for (int i = 1 ; i < string_Len ; i++ )
    {
        if ( string[i - 1] == '(' && string[ i ] == ')' )
            result += 10;
        else if ( ( string[i - 1] == '(' && string[ i ] == '(' ) || ( string[i - 1] == ')' && string[ i ] == ')' ) )
            result += 5;
        else 
            result += 10;
    }
    
    printf("%d", result );

    return 0;
}
