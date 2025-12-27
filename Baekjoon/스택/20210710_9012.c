#include <stdio.h>

int stack[100];
int top = -1;

void push(char bracket) {
    
    stack[++top] = bracket;
} 

void pop() {
    
    top--;
}



int main() {
    int T;
    scanf("%d", &T);
    
    for (int i = 0 ; i < T; i++) { //T개의 데이터 케이스.
        char array_Bracket[100]; //괄호 문자열 받는 변수.
        scanf("%s", array_Bracket);
        
        int now_Spot = 0; // 문자열 배열의 위치를 알려줄 변수.
        int help_Code = 0; //출력에 도움을 주는 변수.
        top = -1; //top을 매 테스트마다 초기화.
        
        
        while (array_Bracket[now_Spot] != '\0') { //문자열이 끝나기 전까지 반복.
            
            if(array_Bracket[now_Spot] == '(') { // '(' 가 들어오면 스택에 푸시
                push('(');

            }
            else if (array_Bracket[now_Spot] == ')' && stack[top] == '(') { // ')'가 들어오면 팝.
                pop();
                
                
            }
            else { // ')'가 들어왔는데 스택 탑에 '('가 없는 상황.
                help_Code = 1;
                printf("NO\n");
                break;
            }

            now_Spot++;
        }
        
        if (help_Code == 0 && top == -1) {
            printf("YES\n");
        }
        else if(help_Code == 0 && top != -1) {
            printf("NO\n");
        }
        
    }
    
    
    return 0;
}