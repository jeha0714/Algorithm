#include <stdio.h>
#include <stdlib.h>

long long cal_Len (int x1, int y1, int x2, int y2 )
{
    return ( ( x1- x2 ) * ( x1 - x2 ) ) + ( ( y1- y2 ) * ( y1 - y2 ) );
}

int compare( const void * first, const void * second)
{
    return *(int*)first - *(int *)second;
}


int main()
{
    int size_Num; scanf("%d", &size_Num);
    
    for( int tring = 0 ; tring < size_Num ; tring++ )
    {
        int spot[4][2]; // 점들이 저장될 위치
        
        for (int i = 0 ; i < 4 ; i++)
            scanf("%d %d", &spot[i][0], &spot[i][1] );
        
        long long spot_with_spot[6]; // 점들 간의 거리
        
        spot_with_spot[ 0 ] = cal_Len( spot[0][0], spot[0][1], spot[1][0], spot[1][1] );
        spot_with_spot[ 1 ] = cal_Len( spot[0][0], spot[0][1], spot[2][0], spot[2][1] );
        spot_with_spot[ 2 ] = cal_Len( spot[0][0], spot[0][1], spot[3][0], spot[3][1] );
        spot_with_spot[ 3 ] = cal_Len( spot[1][0], spot[1][1], spot[2][0], spot[2][1] );
        spot_with_spot[ 4 ] = cal_Len( spot[1][0], spot[1][1], spot[3][0], spot[3][1] );
        spot_with_spot[ 5 ] = cal_Len( spot[2][0], spot[2][1], spot[3][0], spot[3][1] );
        
        qsort( spot_with_spot, 6, sizeof( spot_with_spot[0] ), compare );
        
        if ( (spot_with_spot[4] == spot_with_spot[5]) && ( (spot_with_spot[0] == spot_with_spot[1]) && (spot_with_spot[0] == spot_with_spot[2]) && (spot_with_spot[0] == spot_with_spot[3]) ) )
            printf("1\n");
        else
            printf("0\n");
    }

    return 0;
}
