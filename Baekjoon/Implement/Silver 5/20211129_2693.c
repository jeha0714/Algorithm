#include <stdio.h>
#include <stdlib.h>


int compare( const void * first, const void * second )
{
    return *(int *)first - *(int *)second;
}



int main() {
    
    int t; scanf("%d" ,&t );
    
    for (int i = 0 ; i < t ; i++ )
    {
        int array[10];
        for (int index = 0; index < 10 ; index++ )
            scanf("%d", &array[ index ] );
        
        qsort(array, 10 , sizeof(array[0]), compare );
        
        printf("%d\n", array[7] );
    }
    
    
    
    return 0;
}