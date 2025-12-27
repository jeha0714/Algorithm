#include <stdio.h>

int main() {
    
    int left_Index, right_Index;
    int left_Move = 0, right_Move = 0;
    
    scanf("%d %d", &left_Index, &right_Index);
    
    while( left_Index != 1 && right_Index != 1 )
    {
        if ( left_Index < right_Index )
        {
            right_Move++;
            right_Index -= left_Index;
        }
        
        else
        {
            left_Move++;
            left_Index -= right_Index;
        }
        
    }
    
    if ( left_Index == 1 )
        right_Move += (right_Index - 1);
    if ( right_Index == 1 )
        left_Move += (left_Index - 1);  
        
    
    printf("%d %d", left_Move, right_Move);
    
    
    return 0;
}