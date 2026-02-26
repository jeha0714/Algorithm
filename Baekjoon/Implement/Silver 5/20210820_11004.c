#include <stdio.h>
#include <stdlib.h>

int compare(const void * first, const void * second)
{
    if ( *((int *)first) < *((int *)second) ) {return -1;}
    else if ( *((int *)first) == *((int *)second) ) {return 0;}
    else {return 1;}
}



int main() {
    
    int N, K;
    scanf("%d %d", &N, &K);
    
    int array_N[N];
    for (int i = 0 ; i < N ; i++)
    {
        scanf("%d", &array_N[i]);
    }
    
    
    qsort(array_N, N, sizeof(int), compare);
    
    printf("%d", array_N[K - 1]);
    
    return 0;
}