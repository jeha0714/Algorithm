#include <stdio.h>

int main() {
    
    
    int how_Many; //진짜 약수의 개수
    scanf("%d", &how_Many);
    int array_Measure[how_Many]; //진짜 약수의 종류가 들어갈 배열
    
    for (int i = 0; i < how_Many ; i++) {
        scanf("%d", &array_Measure[i]);
    }
    
    int max = array_Measure[0], min = array_Measure[0];
    
    for(int i = 1; i < how_Many ; i++ ) {
        if (max <= array_Measure[i]) {max = array_Measure[i];}
        if (min >= array_Measure[i]) {min = array_Measure[i];}
    }
    
    printf("%d",max * min);
    
    return 0;
}