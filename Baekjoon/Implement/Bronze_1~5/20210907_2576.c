#include <stdio.h>

int main() {
    
    int min_Num = 100, sum_All = 0;
    
    for (int now = 0 ; now < 7; now++ )
    {
        int num;
        scanf("%d", &num);
        
        if ( num % 2 != 0)
        {
            sum_All+=num;
            if ( min_Num > num ) { min_Num = num; }
        }
        
    }

    if ( sum_All != 0) { printf("%d\n%d", sum_All, min_Num); }
    else
    {
        printf("-1");
    }
    
    return 0;
}