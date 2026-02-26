#include <stdio.h>

int main() {
    
    int num, start;
    short array_Num[5];
    
    scanf("%hd %hd %hd %hd %hd", &array_Num[0], &array_Num[1], &array_Num[2], &array_Num[3], &array_Num[4]);
    start = array_Num[0];
    
    for (int i = 1 ; i < 5 ; i++) {
        
        if (start > array_Num[i]) {start = array_Num[i];}
    }
    
    
    for (; ; start++) {
        
        int how_Many = 0;
        
        if ( start % array_Num[0] == 0 ) {how_Many++;}
        if ( start % array_Num[1] == 0 ) {how_Many++;}
        if ( start % array_Num[2] == 0 ) {how_Many++;}
        if ( start % array_Num[3] == 0 ) {how_Many++;}
        if ( start % array_Num[4] == 0 ) {how_Many++;}
        
        
        if (how_Many >= 3) {
            printf("%d", start);
            break;
            
        }
        
    }
    
    
    
    return 0;
}