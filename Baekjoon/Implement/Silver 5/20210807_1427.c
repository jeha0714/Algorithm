#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compare (const void * first, const void * second) { //내림차순으로 정렬
    
    if ( *(int *)first < *(int *)second ) {return 1;}
    else if ( *(int *)first > *(int *)second ) {return -1;}
    else {return 0;}
    
}



int main() {
    
    char array_S[12]; //문자열 입력받을 배열
    int already_Sort_Num[12]; //문자열 입력받은 배열을 자리수 순서대로 int형으로 변환하고 qsort로 정렬할 배열.
    scanf("%s", array_S); //문자열 입력
    
    for (int i = 0; i < strlen(array_S) ;i++) { //입력받은 문자열을 각자리수별 int형으로 변환 후 삽입.
        
        already_Sort_Num[i] = array_S[i] % 48;
    }
    
    qsort(already_Sort_Num, strlen(array_S), sizeof(already_Sort_Num[0]), compare); //정렬 함수 실행.
    
    
    for (int i = 0; i < strlen(array_S) ;i++) { //출력.
        
        printf("%d", already_Sort_Num[i]);
    }
    
    return 0;
}