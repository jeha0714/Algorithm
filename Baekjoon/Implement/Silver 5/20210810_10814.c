#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct  //회원 구조체.
{
    int age;
    char name[110];
    
}Profile;



int compare(const void * first, const void * second ) {//나이를 오름차순으로 같을 시 가입한 순.
    
    if ( (((Profile *)first) -> age) < (((Profile *)second) -> age) ) {
        return -1;
    }
    else if ( (((Profile *)first) -> age) == (((Profile *)second) -> age) ) {
        return 0;
    }
    else if ( (((Profile *)first) -> age) > (((Profile *)second) -> age) ) {
        return 1;
    }
    
}



int main() {
    
    
    int N;
    scanf("%d", &N);
    
    Profile array_P[N];
    
    for (int i = 0 ; i < N; i++) { //데이터를 구조체 배열에 차례로 입력.
        scanf("%d %s", &array_P[i].age, array_P[i].name);
    }
    
    
    qsort(array_P, N, sizeof(array_P[0]), compare);
    
    
    for (int i = 0 ; i < N; i++) { //정렬된 구조체 배열을 차례로 출력.
        printf("%d %s\n", array_P[i].age, array_P[i].name);
    }
    
    
    return 0;
}