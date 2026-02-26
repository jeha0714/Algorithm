#include <stdio.h>

int main() {
    
    int n; scanf("%d", &n);
    
    for (int now = n ; now > 0 ; now-- )
    {
        for (int i = now ; i < n ; i++ )
            printf(" ");
        
        for (int i = 0 ; i < now ; i++ )
            printf("*");
        
        printf("\n");
    }
    
    return 0;
}