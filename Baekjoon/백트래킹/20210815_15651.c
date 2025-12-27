#include <stdio.h>
#include <stdlib.h>


int check_Array(int array_Num[], int array_Size, int max_Num) { //배열 내부의 모든 수가 N일 경우 0을 반환해 무한루프 break
    
    for (int i = 0 ; i < array_Size ; i++) {
        
        if (array_Num[i] != max_Num) { return 1;}
    }
    
    
    return 0;
}


void calculate_Array(int array_Num[], int array_Size, int max_Num) { //각 배열내부가 N보다 클경우 1로 초기화 및 다음 자리수에 +1해줌.
    for (int i = array_Size - 1; i >= 0 ; i--) {
        
        if (array_Num[i] > max_Num) {
            
            array_Num[i] = 1;
            array_Num[i - 1]++;
        }
        
    }
        
}



int main() {
    
    int N, M; 
    scanf("%d %d", &N, &M);
    
    int array_Num[M];
    for (int i = 0 ; i < M ; i++) {array_Num[i] = 1;}
    
    
    while(1) {
        
        for (int i = 0 ; i < M ; i++) { //우선 차례대로 출력.
            printf("%d ", array_Num[i]);
        }
        printf("\n");
        
        if (check_Array(array_Num , M , N) == 0) {break;} //모든 배열 내부의 수가 N이랑 같을 경우 무한반복문 break
        
        
        //우선 제일 끝의 자리를 +1 해준다.
        array_Num[M - 1]++;
        
        calculate_Array(array_Num, M, N); //배열 내부의 각 자리가 N보다 큰지 확인.
        
        
    }
    
    
    
    
    return 0;
}