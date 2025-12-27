#include <stdio.h>

int stack[500001];
int top = -1;


extern void push(int num);
extern int pop();


int main() {
    
    int N; // 탑의 수를 나타내는 정수
    scanf("%d", &N);
    
    int array_Top[N], array_Result[N]; // 탑들의 높이를 저장할 배열과 레이저 신호를 수신한 탑들의 번호를 저장할 배열
    for (int now_Index = 0; now_Index < N ; now_Index++ ) 
    {
        scanf("%d", &array_Top[now_Index] ); 
        array_Result[now_Index] = 0; // array_Result내부를 전부 0으로 초기화.
    }
    
    
    for (int now_Index = N - 1; now_Index >= 0 ; now_Index-- )
    {
        if ( top == - 1 ) // 스택이 비었을 경우 인덱스를 push
        {
            push( now_Index );
        }
        
        else // 스택내부에 값이 존재할 때
        {
            
            if ( array_Top[ stack[top] ] < array_Top[now_Index] ) 
            {
                while ( array_Top[ stack[top] ] < array_Top[now_Index] && top != -1 )
                {
                    int location = pop();
                
                    array_Result[location] = now_Index + 1;
                }
                
                push ( now_Index );

            }
            
            else // array_Top[ stack[top] ] >= array_Top[now_Index] 일 시 인덱스를 push
            {
                push( now_Index );
            }
            
        }
        
    }
    
    // 결과값인 array_Result를 하나하나 출력.
    for (int now_Index = 0 ; now_Index < N ; now_Index++ )
    {
        printf("%d ", array_Result[now_Index] );
    }
    
    return 0;
}



void push(int num)
{
    stack[++top] = num;
}


int pop()
{
    return stack[top--];
}