#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void * first, const void * second) { //compare return 함수.
    
    
    if (strlen((char*)first) < strlen((char*)second)) { //-1일경우 정상.
        
        return -1;
    }
    else if (strlen((char*)first) > strlen((char*)second)) { //1일 경우 반대로 저장 될 수 있도록.
        
        return 1;
    }
    else if (strlen((char*)first) == strlen((char*)second)) { //문자 길이가 같은 경우 사전순으로 배열.
        
        return strcmp((char*)first, (char*)second); // strcmp를 이용하여 사전순으로 배열 할 수 있도록 .
    }
    
}



int main(void) {
    
    int N; //입력 받을 단어의 개수 N.
    scanf("%d", &N);
    char array_S[N][51]; //문자열을 저장 할 2차원 배열.
    
    for (int i = 0 ; i <N ; i++) { //각 행마다 문자 저장.
        
        scanf("%s", array_S[i]);
    }
    
    
    qsort(array_S, N, sizeof(array_S[0]), compare); //qsort 함수를 이용해서 내부 정리.
    
    
    
    for (int i = 0 ; i < N ; i++) { //정렬된 배열을 순서대로 출력.
        
        if (i > 0 && strcmp(array_S[i-1], array_S[i]) == 0) {continue;} // 앞에 단어와 동일 할 경우 건너뜀.
        else {
            printf("%s\n", array_S[i]);
        }
    }
    
    
    return 0;
}