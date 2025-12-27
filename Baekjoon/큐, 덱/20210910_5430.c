#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct tagNode
{
    int Data;
    struct tagNode * PrevNode;
    struct tagNode * NextNode;
    
}Node;


typedef struct tagLinkedQueue
{
    Node * Front;
    Node * Rear;
    
    int Count;
    
}LinkedQueue;


/* 함수 재 선언 영역 */
extern void LQ_CreateQueue ( LinkedQueue ** Queue );
extern void LQ_DestroyQueue (LinkedQueue * Queue);
extern Node * LQ_CreateNode ( int NewData );
extern void LQ_DestroyNode ( Node * _Node );
extern void push_front ( LinkedQueue * Queue , Node * NewNode );
extern void push_back ( LinkedQueue * Queue , Node * NewNode );
extern int pop_front ( LinkedQueue * Queue );
extern int pop_back ( LinkedQueue * Queue );




int main() {
    
    int test_Case;
    scanf("%d", &test_Case);
    
    
    for (int now_Try = 0; now_Try < test_Case; now_Try++ )
    {
        int n, length_Function; // 배열에 들어있는 수 
        char function[100013]; // 수행할 함수 p
        LinkedQueue * Queue;
        int now_Queue_System = 0, check_Code = 0; // 0일 시 정상, 1일 시 뒤집어진 상태. check_Code가 0일시 정상 1일시 빈상태에서 D할시 0으로 변환되며 이후 error 값 출력.
        char main_String[300010]; // 배열을 입력받을 변수
        
        scanf("%s %d %s", function, &n, main_String);
        length_Function = strlen(function);
        
        LQ_CreateQueue( &Queue );
        
        for (int main_Index = 0, now_Index = 0; main_Index < n; now_Index++ )
        {
            //괄호열과 쉼표 제외 숫자만 Queue에 받아들인다.
            //배열에 입력된 char형 문자를 인트로 변환 후 큐에 삽입.
            
            if ( main_String[now_Index] == '[' || main_String[now_Index] == ',' || main_String[now_Index] == ']' ) { continue; }
            else 
            {
                if ( main_String[now_Index] % 48 == 1 )
                {
                    if ( main_String[now_Index + 1] % 48 == 0 )
                    {
                        if ( main_String[now_Index + 2] < 48 || main_String[now_Index + 2] > 57 )
                        {
                            int num;
                            num =  ( (main_String[now_Index] % 48) * 10 + ( main_String[now_Index+ 1] % 48 ) );
                            
                            Node * NewNode = LQ_CreateNode( num );
                    
                            push_back( Queue, NewNode );
                            main_Index++; now_Index++;
                        }
                        else
                        {
                            Node * NewNode = LQ_CreateNode( 100 );
                
                            push_back( Queue, NewNode );
                            main_Index++; now_Index += 2;
                        }
                        
                    }
                    else
                    {
                        if ( main_String[now_Index + 1] % 48 >= 0 && main_String[now_Index + 1] % 48 <= 9)
                        {
                            int num;
                            num =  ( (main_String[now_Index] % 48) * 10 + ( main_String[now_Index+ 1] % 48 ) );
                            
                            Node * NewNode = LQ_CreateNode( num );
                    
                            push_back( Queue, NewNode );
                            main_Index++; now_Index++;
                        }
                        else
                        {
                            Node * NewNode = LQ_CreateNode( main_String[now_Index] % 48 );
                    
                            push_back( Queue, NewNode );
                            main_Index++;
                        }
                    }
                    
                }
                else // 2~9
                {
                    if ( main_String[now_Index + 1] % 48 >= 0 && main_String[now_Index + 1] % 48 <= 9)
                    {
                        int num;
                        num =  ( (main_String[now_Index] % 48) * 10 + ( main_String[now_Index+ 1] % 48 ) );
                        
                        Node * NewNode = LQ_CreateNode( num );
                
                        push_back( Queue, NewNode );
                        main_Index++; now_Index++;
                    }
                    else
                    {
                        Node * NewNode = LQ_CreateNode( main_String[now_Index] % 48 );
                
                        push_back( Queue, NewNode );
                        main_Index++;
                    }
                    
                }
                
                
            }
            
            
        }
        
        
        // 수행할 함수를 차례대로 실행
        for ( int now_Index = 0 ; now_Index < length_Function; now_Index++ )
        {
            if ( function[now_Index] == 'R' )
            {
                if ( now_Queue_System == 0 )
                {
                    now_Queue_System = 1;
                }
                
                else
                {
                    now_Queue_System = 0;
                }
                
            }
            
            else if ( function[now_Index] == 'D' )
            {
                // 큐가 빈 상태에서 D가 호출됐을 시 check_Code가 1으로 변환 
                // 이후 check_Code로 인해 error 출력
                
                if ( now_Queue_System == 0 )
                {
                    if ( Queue->Count == 0 )
                    {
                        int garbage_Num;
                        garbage_Num = pop_front(Queue);
                        check_Code = 1;
                    }
                    else
                    {
                        int garbage_Num;
                        garbage_Num = pop_front(Queue);
                    }
                    
                }
                
                else
                {
                    if ( Queue->Count == 0 )
                    {
                        int garbage_Num;
                        garbage_Num = pop_back(Queue);
                        check_Code = 1;
                    }
                    else
                    {
                        int garbage_Num;
                        garbage_Num = pop_back(Queue);
                    }
                    
                }
                
            }
            
        }
        
        //check_Code가 1이므로 error
        if ( check_Code == 1) {printf("error\n"); continue;}
        
        // 이제 출력.
        if ( now_Queue_System == 0 )
        {
            printf("[");
            while ( Queue->Count > 1 )
            {
                printf("%d,", pop_front( Queue ) );
            }
            int garbage_Num = pop_front( Queue );
            if ( garbage_Num != -1 ) { printf("%d", garbage_Num ); }
            printf("]\n");
        }
        else 
        {
            printf("[");
            while ( Queue->Count > 1 )
            {
                printf("%d,", pop_back( Queue ) );
            }
            int garbage_Num = pop_back( Queue );
            if ( garbage_Num != -1 ) { printf("%d", garbage_Num ); } 
            printf("]\n");
        }
        
        
        // Queue free 시킴.
        while ( Queue->Count != 0 )
        {
            int garbage_Num = pop_front( Queue );
        }
        LQ_DestroyQueue(Queue);
        
    }
    
    
    
    
    return 0;
}



/* 큐 관련 함수 */


// 큐 생성
void LQ_CreateQueue(LinkedQueue** Queue)
{
	(*Queue) = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	
	(*Queue)->Front = NULL;
	(*Queue)->Rear = NULL;
	(*Queue)->Count = 0;

}

// 큐 제거
void LQ_DestroyQueue(LinkedQueue* Queue)
{
	free(Queue);
}

// 노드 생성
Node* LQ_CreateNode( int NewData )
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;
    NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}



void LQ_DestroyNode(Node* _Node)
{
	free(_Node);
}

//  정수를 덱의 앞에 넣는다.
void push_front ( LinkedQueue * Queue , Node * NewNode )
{
    if ( Queue->Front == NULL )
    {
        Queue->Front = NewNode;
        Queue->Rear = NewNode;
        Queue->Count++;
    }
    
    else
    {
        NewNode->NextNode = Queue->Front;
        Queue->Front->PrevNode = NewNode;
        Queue->Front = NewNode;
        Queue->Count++;
    }
    
}

// 정수를 덱의 뒤에 넣는다.
void push_back ( LinkedQueue * Queue , Node * NewNode )
{
    if ( Queue->Rear == NULL )
    {
        Queue->Front = NewNode;
        Queue->Rear = NewNode;
        Queue->Count++;
    }
    
    else
    {
        NewNode->PrevNode = Queue->Rear;
        Queue->Rear->NextNode = NewNode;
        Queue->Rear = NewNode;
        Queue->Count++;
    }
    
}

// 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
int pop_front ( LinkedQueue * Queue )
{
    if ( Queue->Front == NULL )
    {
        return -1;
    }
    
    else if ( Queue->Front->NextNode == NULL )
    {
        int return_Data = Queue->Front->Data;
        
        free(Queue->Front);
    
        Queue->Front = NULL;
        Queue->Rear = NULL;
        Queue->Count--;
        
        return return_Data;
    }
    
    else
    {
        int return_Data = Queue->Front->Data;
        
        Queue->Front = Queue->Front->NextNode;
        
        free( Queue->Front->PrevNode );
    
        Queue->Front->PrevNode = NULL;
        Queue->Count--;
        
        return return_Data;
    }
    
}

// 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
int pop_back ( LinkedQueue * Queue )
{
    if ( Queue->Front == NULL )
    {
        return -1;
    }
    
    else if ( Queue->Rear->PrevNode == NULL )
    {
        int return_Data = Queue->Rear->Data;
        
        free(Queue->Rear);
    
        Queue->Front = NULL;
        Queue->Rear = NULL;
        Queue->Count--;
        
        return return_Data;
    }
    
    else
    {
        int return_Data = Queue->Rear->Data;
        
        Queue->Rear = Queue->Rear->PrevNode;
        
        free( Queue->Rear->NextNode );
    
        Queue->Rear->NextNode = NULL;
        Queue->Count--;
        
        return return_Data;
    }
    
}


