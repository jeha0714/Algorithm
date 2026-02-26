#include <stdio.h>


int main() {
    
    int num = 1;
    
    while (1)
    {
        int L, P, V; scanf("%d %d %d", &L, &P, &V);
        
        if ( L == 0 && P == 0 && V == 0 )
            break;
        
        int result = 0;
        if ( V % P > L )
            result = V / P * L + L;
        else
            result = V / P * L + V % P;
        
        printf("Case %d: %d\n", num, result);
        num++;
    }

    return 0;
}