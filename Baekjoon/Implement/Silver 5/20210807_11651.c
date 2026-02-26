#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct //좌표 구조체 정의.
{
    int x_Location;
    int y_Location;
    
}Location;


int compare(const void *first, const void *second) { //내림차순 정의.
    
    if ( ((Location *)first)->y_Location == ((Location *)second)->y_Location ){
        
        return ((Location *)first)->x_Location - ((Location *)second)->x_Location;
    }
    else {
        
        return ((Location *)first)->y_Location - ((Location *)second)->y_Location;
    }
    
    //return 0;
}



int main() {
    
    int N = 0; //점의 개수 N
    scanf("%d", &N);
    Location x_And_y[N]; //구조체 포인터 N 정의
    
    for (int i = 0; i < N; i++) { //정의된 구조체 타입의 각 배열에 좌표 저장.
        
        scanf("%d %d", &x_And_y[i].x_Location, &x_And_y[i].y_Location); 
    }
    
    
    qsort(x_And_y, N, sizeof(x_And_y[0]), compare); //qsort 진행.
    
    
    for (int i = 0 ; i < N; i++) { //차례대로 구조체 내 변수를 통해 좌표 출력.
        
        printf("%d %d\n", x_And_y[i].x_Location, x_And_y[i].y_Location);
    }
    
    
    
    return 0;
}