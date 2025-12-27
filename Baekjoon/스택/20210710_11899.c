#include <stdio.h>

char stack[100];
int top = -1;

void push (char bracket) {
    
    stack[++top] = bracket;
}

void pop() {
    
    top--;
}


int main() {
    
    char array[52];
    int now_Spot = 0, result = 0; //now_Spot은 배열의 현재위치를 나타내기 위한 변수, result는 결과값에 이용하는 변수.
    
    scanf("%s", array);
    
    while (array[now_Spot] != '\0') {
        
        if(array[now_Spot] == '(') {
            
            push('(');
        }
        else if(array[now_Spot] == ')'&& stack[top] == '(') {
            
            pop();
        }
        else {
            result++;
        }
        
        
        now_Spot++;
    }
    
    printf("%d", top + result + 1);
    
    
    return 0;
}