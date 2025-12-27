#include <stdio.h>
#include <string.h>


char stack[110]; //연산자들이 저장될 스택 배열.
int top = -1;

void push(char String)
{
    stack[++top] = String;
}

char pop()
{
    return stack[top--];
}



int main() {

    int length_array_S = 0; //중위 표기식이 저장될 배열의 길이값을 저장할 변수.
    int result_Index = 0; //결과값이 저장될 배열의 현재 인덱스를 나타내는 변수
    char array_S[110], array_Result[110]; // 중위 표기식이 저장될 배열과 후위 표기식이 저장될 배열.

    for (int i = 0; i < 102; i++) { array_Result[i] = '\0'; }

    scanf("%s", array_S);
    length_array_S = strlen(array_S);


    for (int now_Index = 0; now_Index < length_array_S; now_Index++)
    {
        if (array_S[now_Index] >= 65 && array_S[now_Index] <= 90)
        {
            array_Result[result_Index++] = array_S[now_Index];
        }

        else if (array_S[now_Index] == '(')
        {
            push(array_S[now_Index]);
        }

        else if (array_S[now_Index] == ')') //괄호가 닫기면 스택에 남아있는 연산자들을 모두 출력.
        {
            while (stack[top] != '(') //괄호 시작 앞 까지만 pop 하고 괄호는 pop하지 않는다.
            {
                array_Result[result_Index++] = pop();
            }

            top--; // top에 저장된 '('을 제거.
        }
        
        //연산자가 들어왔을 때
        else if (top == -1)
        {
            push(array_S[now_Index]);
        }

        else if (top != -1 && stack[top] != '(') //괄호가 아닌 연산자가 대입될 경우
        {
            //stack[top]보다 상위 연산자 일경우 push
            //stack[top]과 동등 연산자 일경우 top값만 pop 그리고 동등한 연산자를 push
            //stack[top]보다 하위 연산자 일 경우 top = -1 or 자기보다 상위 연산자를 만날때까지 pop한 후 자신을 push

            if (stack[top] == '+' || stack[top] == '-')
            {
                if (array_S[now_Index] == '+' || array_S[now_Index] == '-')
                {
                    array_Result[result_Index++] = pop();
                    push(array_S[now_Index]);
                }
                else if (array_S[now_Index] == '*' || array_S[now_Index] == '/')
                {
                    push(array_S[now_Index]);
                }

            }

            else if (stack[top] == '*' || stack[top] == '/')
            {
                if (array_S[now_Index] == '+' || array_S[now_Index] == '-')
                {
                    while ( stack[top] != '(' && top != -1 ) 
                    { 
                        array_Result[result_Index++] = pop(); 
                    }
                    push(array_S[now_Index]);
                }
                else if (array_S[now_Index] == '*' || array_S[now_Index] == '/')
                {
                    array_Result[result_Index++] = pop();
                    push(array_S[now_Index]);
                }

            }

        }

        else if (top != -1 && stack[top] == '(')
        {
            push(array_S[now_Index]);
        }

    }


    while (top != -1) // 스택에 있는 남은 연산자들을 모드 pop.
    {
        array_Result[result_Index++] = pop();
    }


    //결과값 출력.
    printf("%s", array_Result);


    return 0;
}