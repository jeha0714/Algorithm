#include <stdio.h>

int main() {
    
    int x,y,w,h;
    int array_min[4];
    int min;
    
    scanf("%d %d %d %d", &x,&y,&w,&h);
    
    array_min[0] = w-x>=0 ? w-x : x-w;
    array_min[1] = y;
    array_min[2] = x;
    array_min[3] = h-y>=0 ? h-y : y-h;
    
    
    min = array_min[0];
    
    for(int i =0; i<4 ;i++) {
        
        if( min > array_min[i]) {
            min = array_min[i];
        }
    }
    
    printf("%d", min);
    
    return 0;
}