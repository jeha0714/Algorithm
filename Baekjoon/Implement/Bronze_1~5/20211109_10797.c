#include <stdio.h>

int main() {
    
    int num; scanf("%d", &num);
    int result = 0;
    int array[5];
    for (int i = 0 ; i < 5 ; i++ )
    {
        scanf("%d", &array[i] );
        if ( num == array[i] )
            result++;
    }
        
    
    printf("%d", result);
    
    return 0;#include <stdio.h>

int main() {
    
    int num; scanf("%d", &num);
    int result = 0;
    int array[5];
    for (int i = 0 ; i < 5 ; i++ )
    {
        scanf("%d", &array[i] );
        if ( num == array[i] )
            result++;
    }
        
    
    printf("%d", result);
    
    return 0;
}
}