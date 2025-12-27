#include <stdio.h>


int main() {
    
    int N; scanf("%d", &N);
    
    if ( N % 7 == 1 || N % 7 == 3 )
        printf("CY");
    else
        printf("SK");
    
    return 0;
}