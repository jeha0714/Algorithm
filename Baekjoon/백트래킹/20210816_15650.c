#include <stdio.h>
#include <stdlib.h>


int check_Array(int array_Num[], int max_Num, int array_Size) { //조건에 부합하면 return 0
    //맨 끝의 배열 수가 max_Num이며 그 아래로 -1씩 감소할 경우 조건에 부합.
    
    
    for (int now_Index = array_Size - 1; now_Index >= 0; now_Index--) {
        
        if ( now_Index == (array_Size - 1) && array_Num[now_Index] != max_Num ) {
            return 1;
        }
        else if ( now_Index != (array_Size - 1) && (array_Num[now_Index] + 1) != array_Num[ now_Index + 1 ] ) {
            return 1;
        }
        
        
    }
    
    
    return 0;
}


void calculate(int array_Num[], int max_Num, int array_Size) { 
    //맨 끝의 수가 max_Num보다 클 경우 index를 앞으로 옮겨가면서 2이상 차이 나는곳을 찾는다.
    //이후 2이상 차이 나는 곳을 +1 시켜준 후 그 인덱스를 기준으로 뒤의 숫자들을 1씩 차이나게 만든다.
    
    
    int find_Index; //+1의 위치의 인덱스에 해당하는 배열값과 2이상 차이가 날 경우 해당 인덱스의 값을 저장하는 변수.
    
    if ( array_Num[array_Size - 1] > max_Num ) {
            
        for (int now_Index = array_Size - 2 ; now_Index >= 0 ; now_Index-- ) {
            
            //맨 뒤의 값과 그 앞 차이는 3이상일 때 해야함. 메인함수에서 맨 뒤 수가 +1되기 때문에 
            // 맨 뒤 max_Num + 1 맨뒤 앞 max_Num -1인 경우 2차이가 나게 되고 이 경우 아래 반복문을 진행 할 경우 오류.
            if (now_Index == array_Size - 2 && (array_Num[now_Index + 1] - array_Num[now_Index] >= 3) ) {
                
                find_Index = now_Index;
                break;
                
            } 
            else if (now_Index != array_Size - 2 && array_Num[now_Index + 1] - array_Num[now_Index] >= 2 ) { //array_Size -1 인덱스와 -2 인덱스에서만 해당.
                // 그 외에는 2이상.
                
                find_Index = now_Index;
                break;
            }
            
        }//find_Index의 값을 찾음.
        
        array_Num[find_Index]++;
        
        //find_Index의 값을 기준으로 이후의 인덱스의 값을 앞에 값보다 1증가한 상태로 바꿈.
        for (int now_Index = find_Index + 1 ; now_Index < array_Size ; now_Index++) {
            
            array_Num[now_Index] = array_Num[now_Index - 1] + 1;
        }
        
        
        
    }
    
}





int main (void) {
    
    int N,M;
    scanf("%d %d", &N, &M);
    
    int array_Num[M]; //배열의 크기가 M인 배열 선언.
    for (int index = 0, num = 1 ; index < M ; index++, num++) { //배열내부의 모든 값을 1로 초기화.
        array_Num[index] = num;
    }
    
    
    while(1) {
        
        for (int index = 0 ; index < M ; index++) { //배열 내부의 모든 값을 출력.
            printf("%d ", array_Num[index]);
        }
        printf("\n");
        
        if (check_Array(array_Num, N, M ) == 0) {break;} //무한루프를 종료시키는 조건에 도달하면 break.
        
        
        array_Num[M - 1]++; //배열의 맨 끝 수에 + 1.
        
        calculate(array_Num, N, M ); //배열 내부의 각 자리가 N보다 클 경우 다음자리수에 넘겨주는 연산을 하는 함수.

    }
    
    
    
    return 0;
}