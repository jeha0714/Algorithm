#include <stdio.h>


int Break_or_Not(int array_N[], int array_Size, int max_Num) { //배열에 있는 수가 모두 N과 같은지 검사하는 함수.
    
    for (int i = 0 ; i < array_Size ; i++) {
        
        if (array_N[i] != max_Num) {return 0;}
    }
    
    return 1;
}


void calculate_Array(int array_N[], int array_Size, int max_Num) { //배열에 저장되어 있는 수가 N보다 클경우 다음 자리수로 넘겨줌.
    
    for (int i = array_Size - 1; i > 0 ; i--) {
        
        if (array_N[i] > max_Num) { // 우선 각 자리수가 N보다 클 경우 다음자리수에 +1 해준다.
            
            array_N[i - 1]++;
        }
        
    }
    
    for (int i = 1 ; i < array_Size ; i++ ) {// 각 자리 수들끼리 <=이 성립하면서 N보다는 작을 수 있도록 조치해준다.
        
        if (array_N[i - 1] > array_N[i] || array_N[i] > max_Num) {
            
            array_N[i] = array_N[i - 1];
        }
        
    }
    
}



int main() {
    
    int N, M; //1부터 N까지의 자연수 중 M개를 고른 수열.
    //중복이 허용되며 고른 수열은 비내림차순이다.
    
    scanf("%d %d", &N, &M); //값 입력 받기.
    
    int array_N[M]; //M개의 수가 저장될 배열.
    for (int i = 0 ; i < M ; i++) {array_N[i] = 1;} //모든 배열 내부의 값을 1로 초기화.
    
    
    while(1) {
        
        for (int i = 0 ; i < M ; i++) { //배열에 저장되어 있는 수를 모두 호출
            printf("%d ", array_N[i]);
        }
        printf("\n");
        
        if (Break_or_Not( array_N, sizeof(array_N) / 4, N ) == 1 ) {break;} //배열에 있는 수가 모두 N과 같을 경우 break
        
        //연산 시작
        array_N[M - 1]++;
        
        if (M != 1) { //M이 1이 아닐 경우 각 배열의 자리 값의 크기를 확인해야함.
            
            calculate_Array( array_N, sizeof(array_N) / 4, N ); //배열에 저장되어 있는 각 자리수가 N보다 큰지 파악하며 조치.
        }
        
    }
    
    
    
    return 0;
}