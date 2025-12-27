#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* 구조체 영역 */

//노드 구조체 정의
typedef struct tagNode
{
    char Data;
    
}Node;

// 배열스택 구조체 정의
typedef struct tagArrayStack
{
    int Capacity;
    int Top;
    Node * Nodes;
    
}ArrayStack;


/* 함수 extern 선언 영역 */

extern void Create_ArrayStack(ArrayStack ** NewStack, int Capacity );
extern void push ( ArrayStack * Stack, int Data );
extern char pop ( ArrayStack * Stack );



int main() {
    
    int string_Length; //string의 길이를 전달받을 변수.
    int result_Index = 0; //result_String에 사용될 인덱스 변수값.
    char String[101], result_String[101];
    scanf("%s", String);
    
    string_Length = strlen(String); // 입력받은 중위표기식의 길이.
    
    ArrayStack * main_Stack;
    Create_ArrayStack( &main_Stack , 101);
    
    
    for (int now_Index = 0 ; now_Index < 101; now_Index++) { result_String[now_Index] = '\0';} //값을 모두 초기화.
    
    
    for (int now_Index = 0 ; now_Index < string_Length ; now_Index++ )
    {
        
        if ( String[now_Index] == '(' )
        {
            push ( main_Stack, '(' );
        }
        
        else if ( String[now_Index] == ')' )
        {
            // ( 괄호를 만나기 전 까지 pop
            char pop_Now = pop( main_Stack );
            
            while ( pop_Now != '(' )
            {
                result_String[ result_Index++ ] = pop_Now;
                pop_Now = pop( main_Stack );
            }
            
        }
        
        else if ( String[now_Index] == '*' )
        {
            if ( main_Stack->Top == 0 ) // Stack이 빈 경우
            {
                push ( main_Stack, '*' );
            }
            
            else // Stack에 하나라도 차 있는 경우
            {
                // top이 (거나 + - 가 올 때 까지 pop.
                while ( main_Stack->Top != 0 && main_Stack->Nodes[ main_Stack->Top - 1 ].Data != '(' && main_Stack->Nodes[ main_Stack->Top - 1 ].Data != '+' && main_Stack->Nodes[ main_Stack->Top - 1 ].Data != '-' )
                {
                    result_String[ result_Index++ ] = pop( main_Stack );
                }
                
                push ( main_Stack, '*' );
            }
            
        }
        
        else if ( String[now_Index] == '/' )
        {
            if ( main_Stack->Top == 0 ) // Stack이 빈 경우
            {
                push ( main_Stack, '/' );
            }
            
            else // Stack에 하나라도 차 있는 경우
            {
                // top이 (거나 + - 가 올 때 까지 pop.
                while ( main_Stack->Top != 0 && main_Stack->Nodes[ main_Stack->Top - 1 ].Data != '(' && main_Stack->Nodes[ main_Stack->Top - 1 ].Data != '+' && main_Stack->Nodes[ main_Stack->Top - 1 ].Data != '-' )
                {
                    result_String[ result_Index++ ] = pop( main_Stack );
                }
                
                push ( main_Stack, '/' );
            }
            
        }
        
        else if ( String[now_Index] == '+' )
        {
            if ( main_Stack->Top == 0 ) // Stack이 빈 경우
            {
                push ( main_Stack, '+' );
            }
            
            else // Stack에 하나라도 차 있는 경우
            {//괄호를 만나기 전이나 top이 0이 될 때 까지 모두 pop 하고 해당 연산자를 push,
                while ( main_Stack->Top != 0 && main_Stack->Nodes[ main_Stack->Top - 1 ].Data != '('  )
                {
                    result_String[ result_Index++ ] = pop( main_Stack );
                }
                
                push ( main_Stack, '+' );
            }
            
        }
        
        else if ( String[now_Index] == '-' )
        {
            if ( main_Stack->Top == 0 ) // Stack이 빈 경우
            {
                push ( main_Stack, '-' );
            }
            
            else // Stack에 하나라도 차 있는 경우
            {//괄호를 만나기 전이나 top이 0이 될 때 까지 모두 pop 하고 해당 연산자를 push,
                while ( main_Stack->Top != 0 && main_Stack->Nodes[ main_Stack->Top - 1 ].Data != '(' )
                {
                    result_String[ result_Index++ ] = pop( main_Stack );
                }
                
                push ( main_Stack, '-' );
            }
            
        }
        
        else if ( String[now_Index] >= 65 && String[now_Index] <= 90 )
        {
            //알파벳이 들어온 경우 결과 배열에 바로 삽입 한다.
            result_String[ result_Index++ ] = String[now_Index];
        }
        
    }
    
    
    while ( main_Stack->Top != 0 )
    {
        result_String[ result_Index++ ] = pop( main_Stack );
    }
    
    
    printf("%s", result_String);
    
    
    return 0;
}






/* 함수 생성 영역 */

//ArrayStack을 생성하는 함수
void Create_ArrayStack(ArrayStack ** NewStack, int Capacity )
{
    (*NewStack) = (ArrayStack *)malloc(sizeof (ArrayStack));
    
    (*NewStack)->Capacity = Capacity;
    (*NewStack)->Top = 0;
    (*NewStack)->Nodes = (Node *)malloc(sizeof(Node) * Capacity);
}


// node를 탑에 집어 넣는 함수
void push ( ArrayStack * Stack, int NewData )
{
    int now_Index = Stack->Top;
    
    ( Stack->Nodes )[now_Index].Data = NewData;
    Stack->Top++;
}


// 탑에 존재하는 node를 return하는 함수
char pop ( ArrayStack * Stack )
{
    Stack->Top--;
    
    return Stack->Nodes[Stack->Top].Data;
}


char check_Top ( ArrayStack * Stack)
{
    return Stack->Nodes[ Stack->Top ].Data;
}

