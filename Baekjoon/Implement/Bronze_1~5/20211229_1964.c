#include <stdio.h>


int main() {
    
    int N; scanf("%d", &N);
    
    int array[ N + 1 ];
    
    array[1] = 5;
    int next = 7;
    
    
    for (int now = 2 ; now < N + 1 ; now++, next+=3 )
    {
        array[now] = ( array[ now - 1 ] + next ) % 45678;
    }
    
    printf("%d", array[ N ]);
    
    return 0;
}