#include <stdio.h>


int Find_GCD (int num1, int num2)
{
    int bigNum = (num1 > num2 ? num1 : num2);
    int smallNum = ( bigNum == num1 ? num2 : num1 );
    int result = bigNum % smallNum;
    
    
    while ( result != 0 )
    {
        bigNum = smallNum;
        smallNum = result;
        result = bigNum % smallNum;
    }
    
    
    
    return smallNum;
}



int main() {
    
    int test_Case;
    scanf("%d", &test_Case);
    
    for (int i = 0 ; i < test_Case ; i++)
    {
        int num1, num2;
        int GCD, LCM;
        
        scanf("%d %d", &num1, &num2);
        
        
        GCD = Find_GCD(num1, num2);
        LCM = num1 * num2 / GCD;
        
        
        printf("%d %d\n", LCM, GCD);
    }
    
    
    
    return 0;
}