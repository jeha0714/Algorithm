#include <stdio.h>

int main() {
    
    int column, row, K; scanf("%d %d %d", &column, &row, &K );
    
    printf("%d %d", K / row, K % row );
    
    
    return 0;
}