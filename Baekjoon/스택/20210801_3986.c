#include <stdio.h>
#include <string.h>


int top = -1;
char stack[1000010];

void push(char save_What) { //stack의 push 함수
    
    stack[++top] = save_What;
}


void pop() { //stack의 pop 함수
    
    top--;
}




int main() {
    
    
    int N, num_GoodWord = 0;
    scanf("%d", &N);
    
    
    for (int here_we_Go = 0 ; here_we_Go < N ; here_we_Go++) { //N번의 단어를 입력받기.
        
        char array_AB[1000010]; //단어를 입력 받을 배열.
        top = -1;
        
        scanf("%s", array_AB);
        if (array_AB[strlen(array_AB) - 1] == 13){array_AB[strlen(array_AB) - 1] = '\0';} //엔터키가 마지막에 저장되어 있을 시 널값으로 지정.
        

        for (int check_one = 0 ; check_one < strlen(array_AB) ; check_one++) { //입력받은 문자열 하나하나 확인.
            
            if (array_AB[check_one] == 'A' ) {
                
                if (stack[top] == 'A') {pop();} //top의 문자와 같으니 pop
                else if (stack[top] == 'B') {push('A');} //top의 문자와 다르니 push
                else {//top == -1, 현재 스택이 비었으니 push
                    push('A');
                }
                
            }
            else if (array_AB[check_one] == 'B') {
                
                if (stack[top] == 'B') {pop();} //top의 문자와 같으니 pop
                else if (stack[top] == 'A') {push('B');} //top의 문자와 다르니 push
                else {//top == -1, 현재 스택이 비었으니 push
                    push('B');
                }
                
            }
            
            
        }
        
        
        if (top == -1) {num_GoodWord++;}

    }
    
    
    printf("%d", num_GoodWord);
    
    
    return 0;
}