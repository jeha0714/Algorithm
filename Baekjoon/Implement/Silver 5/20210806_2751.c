#include <stdio.h>
#include <stdlib.h>

int compare(void *first, void * second) {
    
    if (*(int*)first > *(int*)second) {return 1;}
    else if (*(int*)first < *(int*)second) {return -1;}
    else {return 0;}
}



int main() {
    
    int N;
    scanf("%d", &N);
    int arr_Num[N];
    
    for (int i = 0 ; i < N ; i++) {
        
        scanf("%d", &arr_Num[i]);
    }
    
    qsort(arr_Num, N, sizeof(arr_Num[0]), compare);
    
    for (int i = 0 ; i < N ;i++) {
        
        printf("%d\n", arr_Num[i]);
    }
    
    
    return 0;
}