#include <stdio.h>

char stack[1000];
int top = -1;

void push(char code) {
    stack[++top] = code;
}

char pop() {
    
    return stack[top--];
}

int main() {
    
    while(1) { //.만 찍힐 때까지 츄라이하는 반복문.
        
        top = -1; //새로운 문자열이 찍힐 때마다 초기화.
        char array_String[110];
        int help_Code = 0; //마지막 균형잡힌 세상인지 식별해준 변수 값.
        fgets(array_String, 110, stdin);
        
        if (array_String[0] == '.') {break;} //'.'시 중지.
        
        for (int i = 0; array_String[i] != '\0' ; i++) { //문자열을 차레로 돌면서 (,[가 나올시 push ),]가 나올시 pop하는 등의 알고리즘.
            
            if (array_String[i] == '(' || array_String[i] == '[') {
                push(array_String[i]);
            }
            else if (array_String[i] == ')') {
                if (pop() == '(') {
                    continue;
                }
                else {
                    help_Code = 1;
                    printf("no\n");
                    top = -1;
                    break;
                }
            }
            else if (array_String[i] == ']') { 
                if (pop() == '[') {
                    continue;
                }
                else {
                    help_Code = 1;
                    printf("no\n");
                    top = - 1;
                    break;
                }
            }
        }
        
        
        if (help_Code == 0 && top == -1) {//균형잡힌 세상은 모든걸 pop하고 help_Code값도 0일 것임.
            printf("yes\n");
        }
        else if (top != -1) { // else가 아닌 다음과 같은 조건을 둔 이유는 push만 된 문자열이 있을 수 있기 때문.
            printf("no\n");
        }
    }
    
    
    return 0;
}