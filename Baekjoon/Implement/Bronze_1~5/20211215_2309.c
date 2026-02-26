#include <stdio.h>
#include <stdlib.h>

int compare ( const void * first, const void * second )
{
    return *(int *)first - *(int *)second;
}


int main()
{
    int len[ 9 ];
    int sum_All = 0;
    
    for (int i = 0 ; i < 9 ; i++ )
    {
        scanf("%d", &len[i] );
        sum_All += len[i];
    }
    
    for (int i = 0 ; i < 8 ; i++ )
    {
        int code = 0;
        for (int j = i + 1 ; j < 9 ; j++ )
        {
            if ( ( sum_All - len[i] - len[j] ) == 100 )
            {
                len[i] = 0; len[j] = 0;
                code = 1;
                break;
            }
        }
        
        if (code == 1 )
            break;
    }
    
    qsort(len, 9 , sizeof( len[0] ), compare);
    
    for (int i = 2 ; i < 9 ; i++ )
    {
        printf("%d\n", len[i] );
    }

    
    return 0;
    
}
