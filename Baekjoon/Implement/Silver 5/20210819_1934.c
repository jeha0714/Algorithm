#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main() {
    
    int T;
    scanf("%d", &T);
    
    for (int num_Try = 0 ; num_Try < T ; num_Try++)
    {
        int A, B;
        scanf("%d %d", &A, &B);
        
        if (A > B)
        {
            for (int try = 1; ; try++)
            {
                if (A * try % B == 0)
                {
                    printf("%d\n", A * try);
                    break;
                }
                
            }
            
        }
        else 
        {
            for (int try = 1; ; try++)
            {
                if (B * try % A == 0)
                {
                    printf("%d\n", B * try);
                    break;
                }
                
            }
            
        }
        
    }
    
    
    
    
    return 0;
}