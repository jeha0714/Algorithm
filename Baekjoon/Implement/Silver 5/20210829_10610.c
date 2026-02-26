#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compare(const void * first, const void * second)
{
    return -( (*(char *)first) - (*(char *)second) );
    
}







int main() {
    
    int num_Length, zero_Spot = -1;
    char array_N[100005];
    scanf("%s", array_N);
    
    num_Length = strlen(array_N);
    
    for (int now_Index = 0 ; now_Index < num_Length ; now_Index++)
    {
        if ( array_N[now_Index] =='0' ) {zero_Spot = now_Index; break;}
    }
    
    if (zero_Spot == -1)
    {
        printf("-1");
    }
    else
    {
        int sumAll = 0;
        
        for (int now_Index = 0 ; now_Index < num_Length ; now_Index++)
        {
            sumAll+= ( array_N[now_Index] % 48 );
        }
        
        if (sumAll % 3 == 0)
        {
            char temp = array_N[num_Length - 1];
            array_N[num_Length - 1] = '0';
            array_N[zero_Spot] = temp;
            
            qsort(array_N, num_Length - 1, sizeof(array_N[0]), compare );
            
            printf("%s", array_N);
        }
        else 
        {
            printf("-1");
        }
        
    }
    
    
    return 0;
}