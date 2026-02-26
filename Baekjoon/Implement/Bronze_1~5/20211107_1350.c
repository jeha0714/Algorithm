#include <stdio.h>

int main()
{
    int num_CD; scanf("%d", &num_CD );
    int cd_Size[ num_CD ];
    for (int i = 0 ; i < num_CD ; i++ )
        scanf("%d", &cd_Size[ i ] );
    
    int disk_Set_Size; scanf("%d", &disk_Set_Size );
    long long result = 0;
    
    for (int i = 0 ; i < num_CD ; i++ )
    {
        if ( cd_Size[ i ] == 0 )
            continue;
            
        else if ( cd_Size[ i ] < disk_Set_Size )
            result += disk_Set_Size;
            
        else
        {
            if ( cd_Size[ i ] % disk_Set_Size != 0 )
                result += ( disk_Set_Size * ( cd_Size[ i ] / disk_Set_Size + 1 ) );
            else
                result += ( disk_Set_Size * ( cd_Size[ i ] / disk_Set_Size ) );
        }
        
    }
    
    
    printf("%lld", result );

    return 0;
}
