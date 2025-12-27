#include <stdio.h>
#include <stdlib.h>


void Tile( int num, int * array )
{
    if ( num == 1 )
        array[ num - 1 ] = 1;
    else if ( num == 2 )
        array[ num - 1 ] = 2;
    else
    {
        if ( array[ num - 2 ] == 0 )
            Tile( num - 1, array );
        
        if ( array[ num - 3 ] == 0 )
            Tile( num - 2, array );
        
        if ( array[ num - 2 ] + array[ num - 3 ] > 10007 )
            array[ num - 1 ] = ( array[ num - 2 ] + array[ num - 3 ] ) % 10007;
            
        else
            array[ num - 1 ] = array[ num - 2 ] + array[ num - 3 ];
    }
    
}


int main() {
    
    int n;
    
    scanf("%d", &n);
    
    int * array = (int *)malloc( sizeof( int ) * n );
    
    Tile(n, array);
    
    printf("%d", array[ n -1 ] );
    
    
    return 0;
}