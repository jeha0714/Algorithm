#include <stdio.h>
#include <string.h>

int top = -1;
char stack[100010];

void push() {
    
    stack[++top] = '(';
}


void pop() {
    
    top--;
}



int main() {
    
    char array_Bracket[100010]; //입력받을 배열.
    int piece_of_Stick = 0; //조각들의 합을 의미하는 변수.
    
    scanf("%s", array_Bracket);

    
    for (int i = 0 ; i < strlen(array_Bracket) ;i++) {
        
        
        if (array_Bracket[i] == '(' && array_Bracket[i + 1] == ')') { //레이저를 의미.
            
            piece_of_Stick += (top + 1);
            
            i++; // 레이저를 넘어가야 하기에 +1을 해주며 for문 +1을 해주어 총 +2를 해준다.
            
        }
        else if (array_Bracket[i] == '(') { //조각의 시작.
            
            push();
        }
        else if (array_Bracket[i] == ')') { //괄호가 끝나면 잘리고 남은 꼭다리도 조각에 +1하여 추가해준다.
            
            piece_of_Stick++;
            pop();
        }
        
        
    }
    
    
    printf("%d", piece_of_Stick);
    
    return 0;
}