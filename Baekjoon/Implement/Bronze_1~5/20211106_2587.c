#include <stdio.h>
#include <stdlib.h>

int compare ( const void * first, const void * second)
{
    return *(int *)first - *(int *)second;
}



int main() {
    
    int array[5];
    int sum_div_all = 0;
    
    for (int i = 0 ; i < 5 ; i++)
    {
        scanf("%d", &array[i] );
        sum_div_all += array[i];
    }
    
    qsort( array, 5, sizeof( array[0]), compare );
    

    printf("%d\n%d", sum_div_all / 5 , array[2] );
    
    
    
    return 0;
}