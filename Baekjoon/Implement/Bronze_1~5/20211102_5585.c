#include <stdio.h>

int main() {
    
    int n; scanf("%d", &n);
    n = 1000 - n;
    int result = 0;
    int money[6] = {500,100,50,10,5,1};
    
    for (int i = 0 ; i < 6 ; i++ )
    {
        result += ( n / money[i] );
        n = n % money[i];
    }
    
    printf("%d", result);
    
    return 0;
}