#include <stdio.h>

int main()
{
    int N; scanf("%d", &N);
    
    int array[ N ];
    int num[ 201 ] = {0};
    for (int i = 0 ; i < N ; i++ )
    {
        scanf("%d", &array[i] );
        
        num[ array[i] + 100 ]++;
    }
    
    int find_Num; scanf("%d", &find_Num );
    
    printf("%d", num[ find_Num + 100 ] );
    

    return 0;
}
