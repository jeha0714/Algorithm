#include <stdio.h>

int main() {
    
    int call_Num; scanf("%d", &call_Num );
    
    int M = 0, Y = 0;
    
    for (int i = 0 ; i < call_Num; i++ )
    {
       int calling_Time; scanf("%d", &calling_Time ); 
       
       Y += ( calling_Time / 30 + 1 );
       M += ( calling_Time / 60 + 1 );
       
    }
    
    if ( Y * 10 <  M * 15 )
        printf("Y %d", Y  * 10 );
        
    else if ( Y * 10 > M * 15 )
        printf("M %d",  M * 15 );
        
    else
        printf("Y M %d", M * 15 );
    
    
    
    return 0;
}