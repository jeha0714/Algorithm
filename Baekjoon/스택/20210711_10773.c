#include <stdio.h>

int stack[100000]; // 스택 구현.
int top = -1;

void push(int X) {
    
    stack[++top] = X;
}

void pop() {
    
    top--;
}

int main() {
    
    int K, result = 0; // result는 스택에 남아있는 수들의 총합을 계산.
    scanf("%d", &K);
    
    for(int i = 0; i < K; i++) {
        int num;
        scanf("%d", &num);
        
        if (num == 0) {
            
            pop();
        }
        else {
            
            push(num);
        }
        
    }
    
    for(int i = 0; i <= top; i++) {
        result += stack[i];
    }
    
    printf("%d", result);
    
    return 0;
}