#include <stdio.h>

int main()
{
    int num1, num2, num3; scanf("%d %d %d", &num1, &num2, &num3 );
    
    int A = 0, B = 0 , C = 0;
    
    char string[5]; scanf("%s", string);
    
    if ( num1 > num2 && num2 > num3 )
    {
        A = num3;
        B = num2;
        C = num1;
    }
    else if ( num1 < num2 && num2 < num3 )
    {
        C = num3;
        B = num2;
        A = num1;
    }
    else if ( num1 > num2 && num2 < num3 && num1 > num3 )
    {
        C = num1;
        B = num3;
        A = num2;
    }
    else if ( num1 > num2 && num2 < num3 && num1 < num3 )
    {
        C = num3;
        B = num1;
        A = num2;
    }
    else if ( num1 < num2 && num2 > num3 && num1 > num3 )
    {
        C = num2;
        B = num1;
        A = num3;
    }
    else if ( num1 < num2 && num2 > num3 && num1 < num3 )
    {
        C = num2;
        B = num3;
        A = num1;
    }
    
    for (int main = 0 ; main < 3 ; main++ )
    {
        if (main == 2)
        {
            if ( string[ main ] == 'A')
                printf("%d", A);
        
            else if ( string[ main ] == 'B')
                printf("%d", B);
        
            else if ( string[ main ] == 'C')
                printf("%d", C);
        }
        else
        {
            if ( string[ main ] == 'A')
                printf("%d ", A);
            
            else if ( string[ main ] == 'B')
                printf("%d ", B);
            
            else if ( string[ main ] == 'C')
                printf("%d ", C);
        }
    }
    

    return 0;
}
