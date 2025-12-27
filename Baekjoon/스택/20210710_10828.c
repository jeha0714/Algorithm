#include <stdio.h>
#include <string.h>

int stack[100];
int top = -1; // top의 명령어는 main함수에서 따로 구현. top은 상수변수로만 선언했음. 함수 x!

void push(int X) {
    
    stack[++top] = X;    
}

int pop () {
    
    if(top == -1 ) {
        return -1;
    }
    else {
        return stack[top--];
    }
}

int size() {
    
    return top+1;
}

int empty() {
    
    if(top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}


int main() {
    
    int N;
    scanf("%d", &N);
    
    for (int i = 0 ; i <N; i++) {
        char array[6];
        scanf("%s", array);

        if (!strcmp(array,"push")) {
            int num;
            scanf("%d", &num);
            push(num);
        }
        else if (!strcmp(array,"pop")) {
            printf("%d\n", pop());
        }
        else if (!strcmp(array,"size")) {
            printf("%d\n", size());
        }
        else if (!strcmp(array,"empty")) {
            printf("%d\n", empty());
        }
        else if (!strcmp(array,"top")) {
            if (top == -1) {
                printf("-1\n");
            }
            else {
                printf("%d\n" ,stack[top]);    
            }
            
        }
        
    }

    
    return 0;
}