#include <stdio.h>
#include <string.h>
#include <stdlib.h>



double stack[110];
int top = -1;

void push(double num)
{
    stack[++top] = num;
}

double pop()
{
    return stack[top--];
}




int main() {
    
    int N; //피연산자들의 개수.
    //double result = 0.0;
    char array_S[1000]; //후위 표기식이 저장될 배열.
    
    scanf("%d %s", &N, array_S);
    
    double array_N[N]; //피연산자들이 주어지고 저장될 배열.
    for (int now_Index = 0 ; now_Index < N ; now_Index++) // 피연산자들이 주어짐.
    {
        scanf("%lf", &array_N[now_Index]);
    }
    
    
    for (int now_Index = 0 ; now_Index < strlen(array_S); now_Index++ )
    {
        double result = 0.0;
        
        if (array_S[now_Index] <= 90 && array_S[now_Index] >= 65) //피연산자들
        {
            push( array_N[ array_S[now_Index] % 65 ] );
        }
        
        else //연산자들
        {
            if ( array_S[now_Index] == '+' )
            {
                result = pop() + pop();
                push(result);
            }
            else if ( array_S[now_Index] == '-' )
            {
                double num1 = pop(), num2 = pop();
                result = num2 - num1;
                push(result);
            }
            else if ( array_S[now_Index] == '*' )
            {
                double num1 = pop(), num2 = pop();
                result = num2 * num1;
                push(result);
            }
            else if ( array_S[now_Index] == '/' )
            {
                double num1 = pop(), num2 = pop();
                result = num2 / num1;
                push(result);
            }
            
        }
        
    }
    
    
    printf("%.2lf", pop() );
    
    
    return 0;
}