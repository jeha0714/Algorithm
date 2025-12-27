#include <stdio.h>

//스택 구현
int stack[100010];
int top = -1;


void push(int x) {
    stack[++top] = x;
}


void pop() {
    stack[top--] = ' ';
}



int main() {
    
    int n; //n개의 수.
    int Can_or_Not = 0; //주어진 수열이 생성될 수 있는지 파악하는데 사용되는 변수.
    int start_Num = 1; //수열이 생성될 수 있다고 판단될 때 생성 방법에 사용되는 변수.
    int now_Location = 0; //수열의 생성 방법에 사용되며 배열의 현재 인덱스를 나타낼 변수.
    scanf("%d", &n);
    
    int array_Num[n]; //n개의 수가 저장될 배열.
    for (int i = 0 ; i < n; i++) {
        
        scanf("%d", &array_Num[i]);
    }
    
    
    
    //우선 주어진 수열이 생성될 수 있는지 파악.
    for (int i = 1; i < n ; i++) {
        
        //주어진 수열이 생성가능한지 파악하는 조건은.
        //1. n값이 등장하기 전에 앞 뒤 수가  '>'  일경우 앞에수부터 뒤에수 까지 사이의 숫자가 모두 pop된 상태여야 함.
        //2. n값이 등장 한 후에는 무조건 앞 뒤 수가  '>'  이어야 한다.
        
        if(array_Num[i] == n) { //최소 숫자 n을 만났을 때 특정 변수 값을 설정.
            
            Can_or_Not = 1; 
        }
        else if (Can_or_Not == 1) { 
            //Can_or_Not값을 설정 하여 최고 값을 만난 이후라고 설정됨
            //이 이후로는 수열이 내림차순이어야 함. 아닐 시 수열 생성 불가능.
            
            if (array_Num[i - 1] > array_Num[i]) {continue;}
            else {
                
                printf("NO");
                return 0;
            }
            
        }
        else if ( Can_or_Not == 0 && array_Num[i - 1] > array_Num[i] ) {
            //Can_or_Not이 0인 상태로 아직 최고값을 만나지 못한 상태
            //이때 앞 뒤 수가  '>'  일 경우 i-1번째 수와 i번째 사이의 수들이 모두 pop되어 있는 상태여야 생성 가능.
            
            // array_Num[i - 1]와 array_Num[i]크기 사이의 숫자들이 모두 array_Num[i - 1]보다 앞에 존재하는지 확인하기.
        
            int small_and_big = 0; //array_Num[i - 1]앞에 사이의 수들의 개수가 몇 개인지 파악하기 위한 변수.
            
            
            for(int j = 0; j < i - 1 ; j++) {
                
                if (array_Num[i - 1] > array_Num[j] && array_Num[i] < array_Num[j]) {
                    small_and_big++;
                }
            }
            
            //small_and_big로 (array_Num[i - 1]와 array_Num[i] 수들이 개수가 같을 경우 정상 진행. 아닐 시 no!
            if ( small_and_big == (array_Num[i - 1] - array_Num[i] - 1) ) {continue;}
            else {
                
                printf("NO");
                return 0;
            }
            
        }
        
    }
    
    
    
    //수열이 생성된다고 파악이 될 시 아래의 알고리즘을 통해 과정을 출력.
    while(1) {
        
        if (top == -1 && now_Location < n) { //스택이 비었으며 인덱스가 n보다 작을 때 push 연산 진행.
            
            push(start_Num++); printf("+\n");
        }
        else if (top == -1 && now_Location == n) {break;} //스택이 비었지만 인덱스가 n일경우 break! 모든 출력 끝!
        
        
        if ( stack[top] == array_Num[now_Location] ) { //스택의 탑과 배열의 인덱스의 값이 같을 경우 팝과 인덱스 증가.
            
            pop(); printf("-\n");
            now_Location++;
        }
        else if ( stack[top] < array_Num[now_Location] ) { //스택의 탑이 배열의 인덱스 값보다 작을경우 push!
            
            push(start_Num++); printf("+\n");
        }
        /*else if ( stack[top] > array_Num[now_Location] ) { //스택의 탑이 배열의 인덱스 값보다 클 경우 팝!
            //이러한 경우는 존재하지 않는다. 스택의 탑이 더 크기전에 팝되어버림.
            
            pop(); printf("-\n");
            now_Location++;
        }*/
        
    }
    
    
    
    
    
    return 0;
}