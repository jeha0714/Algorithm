#include <stdio.h>

//스택 간단 구현.
int stack[100010];
int top = -1;

void push(int X) {
    stack[++top] = X;
}

void pop(){
    top--;
}



int main() {
    
    int T, Yes_OR_No = 0; //T는 테스트 케이스, Yes_OR_No는 수열을 만들 수 있는지 판단해주는 변수.
    int max_In_Array = 0; //NO가 되는 조건을 찾기 위해 사용되는 변수. 
    scanf("%d", &T);
    
    int example[T]; //나열할 수열을 저장.
    for(int i = 0; i < T ;i++) {
        scanf("%d", &example[i]);
    }
    
    
    for (int i = 0 ; i < T ; i++) { 
        //example에 저장되어있는 수열이 i번째 숫자가 i+1번째 숫자보다 작으면 상관 x  <
        //그렇지만 > 일 경우 i + @번 째 숫자가 i번째보다 클때까지 내림차순이어야함!.
        
        if (example[i] < example[i+1]) { // < 일 경우 상관 x
            continue;
        }
        else { //example[i] > example[i+1]
            
            max_In_Array = example[i]; //기준이 되는 max를 설정.
            
            for (int j = i + 1 ; j < T -1 ; j++) {
                
                if (example[j] > example[j+1]) { //내림차순일 경우 정상진행.
                    continue;
                }
                else {
                    if (max_In_Array < example[j+1]) { // 자기보다 큰 수 일경우 반복문 i를 j로 하고 브레이크문 걸기
                        i = j;
                        break;
                    }
                    else { //기준이 되는 수보다 작지만 내림차순이 아닌경우 no!
                        Yes_OR_No = 1;
                        break;
                    }
                    
                }
                
            }
            
        }
        
        if (Yes_OR_No == 1) {
            break;
        }
        else {
            continue;
        }
        
    }
    
    
    
    if (Yes_OR_No == 1) {
        printf("NO");
    }
    else { //구현 방식은 example[?]번째 수와 동일할 경우 팝. 나머지인 경우 그냥 푸쉬.
        
        int now_Location = 0, help_Code = 0, num = 1; //now_Location은 example의 현재위치
                                                    // help_Code는 push할것인지를 고려해줄 변수 
                                                    // num은 push할 수를 알려주는 변수 


        for (int i = 1 ;; i++) {
            
            if (stack[top] == example[now_Location] && top != -1) { 
                
                pop();
                printf("-\n");
                help_Code = 1; now_Location++;
                
            }
            else {
                
                help_Code = 0;
            }
            
            
            if (help_Code == 0) {
                
                push(num++);
                printf("+\n");
            }
            
            
            if (top == -1 && now_Location == T) { //무한루프 탈출 방법은 스택의 모든 값을 pop 했으며 now_Location이 배열의 끝가지 도달했을때!
                break;
            }
            
        }
    }
    
    
    return 0;
}