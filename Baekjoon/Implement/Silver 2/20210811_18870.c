#include <stdio.h>
#include <stdlib.h>


typedef struct 
{
    long long what_Num; //숫자.
    int order; //몇 번째 언급되었는지.
}Location;


int compare (const void * first , const void * second) { //구조체형 배열을 오름차순으로 정리한다.
    
    if ( (((Location *)first) -> what_Num) < (((Location *)second) -> what_Num) ) {
        return -1;
    }
    else if ( (((Location *)first) -> what_Num) == (((Location *)second) -> what_Num) ) {
        return 0;
    }
    else if ( (((Location *)first) -> what_Num) > (((Location *)second) -> what_Num) ) {
        return 1;
    }
    
    return 0;
}



int main() {
    
    int N; //N개의 좌표.
    scanf("%d", &N);
    
    int array_Sort_Num[N];
    Location array_Num[N]; //N개의 좌표가 삽입 될 배열.
    for (int i = 0 ; i < N; i++) { //좌표 및 입력된 순서 입력.
        scanf("%lld", &array_Num[i].what_Num);
        array_Num[i].order = i;
        
        array_Sort_Num[i] = 0; // array_Sort_Num의 각 배열내부도 전부 0으로 초기화.
    }    
    
    
    qsort(array_Num, N, sizeof(array_Num[0]), compare); //오름차순 배열 정리.
    
    
    
    for (int i = 0, start = 0; start < N ; start++, i++) { //array_Num의 정렬되고 순서가 저장된 변수값을 통해 array_Sort_Num에 차례대로 삽입.
        
        if (start != 0 && array_Num[start].what_Num == array_Num[start - 1].what_Num) {
            
            //정렬된 배열 array_Num에 입력된 what_Num의 수가 start -1 와 start번째가 같을 경우 
            //start - 1번째 시행되고 i++된 값을 -1해주며 그 값 i을 대입해준다.
            i--;
            array_Sort_Num[ array_Num[start].order ] = i;
        }
        else  { //start - 1 번째와 start 번째 수가 다를 경우 그대로 i값을 대입해준다.
            
            array_Sort_Num[ array_Num[start].order ] = i;
        }
        
    }
    
    
    for (int i = 0 ; i < N ; i++) { //정렬되고 압축된 좌표를 모두 출력.
        printf("%d ", array_Sort_Num[i]);
    }
    

    return 0;
}