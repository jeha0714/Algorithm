#include <stdio.h>
#include <stdlib.h>


int compare(const void * first, const void * second)
{
    return *(int *)first - *(int *)second;
}


int BNS( int array_Card[], int find_num, int right_Num )
{
    int start_Index = 0, end_Index = right_Num - 1;
    int left = 0 , right = right_Num - 1;
    short code = 0; // 0일시 존재하지 않음 1일시 존재하는 수.
    
    // find start_Index
    while ( left <= right )
    {
        int mid = ( left + right ) / 2;
        
        if ( array_Card[ mid ] == find_num )
        {
            if ( mid == 0 )
            {
                code = 1;
                start_Index = 0;
                break;
            }
            
            else if ( mid != 0 && array_Card[ mid - 1 ] < find_num )
            {
                code = 1;
                start_Index = mid;
                break;
            }
            
            else
                right = mid - 1;
            
        }
        
        else if ( array_Card[ mid ] < find_num )
            left = mid + 1;
        
        else if ( array_Card[ mid ] > find_num )
            right = mid - 1;
            
    }
    
    left = 0;
    right = right_Num - 1;
    
    // find end_Index
    while ( left <= right )
    {
        int mid = ( left + right ) / 2;
        
        if ( array_Card[ mid ] == find_num )
        {
            if ( mid == right_Num - 1 )
            {
                code = 1;
                end_Index = right_Num - 1;
                break;
            }
            
            if ( array_Card[ mid + 1 ] > find_num )
            {
                code = 1;
                end_Index = mid;
                break;
            }
            
            else
                left = mid + 1;
            
        }
        
        else if ( array_Card[ mid ] < find_num )
            left = mid + 1;
        
        else if ( array_Card[ mid ] > find_num )
            right = mid - 1;
            
    }

    
    if ( code == 1 )
        return end_Index - start_Index + 1;
    else
        return 0;
}






int main() 
{
    int num_Card;
    scanf("%d", &num_Card);
    
    int array_Card[ num_Card ];
    for (int index = 0; index < num_Card ; index++ ) { scanf("%d", &array_Card[ index ] ); }
    
    qsort(array_Card, num_Card, sizeof( array_Card[0] ), compare);

    int check_Card;
    scanf("%d", &check_Card);
    for (int try = 0 ; try < check_Card ; try++ )
    {
        int num;
        scanf("%d", &num);
        
        printf("%d ", BNS(array_Card, num, num_Card) );
    }
    
    
    
    
    return 0;
}