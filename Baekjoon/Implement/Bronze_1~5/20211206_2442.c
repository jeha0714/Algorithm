#include <stdio.h>

int main() {
    
    int N; scanf("%d", &N);
    
    for (int column = 0 ; column < N; column++ )
    {
        for ( int spacebar = 0 ; spacebar < N - 1 - column; spacebar++ )
            printf(" ");
        
        for ( int star = 0 ; star < column * 2 + 1 ; star++ )
            printf("*");
        
        for ( int spacebar = 0 ; spacebar < N - 1 - column; spacebar++ )
            printf(" ");
            
        printf("\n");
    }
    
    
    return 0;
}