#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* 구조체 선언 영역 */

// 노드 구현
typedef struct tagNode
{
	int Data;
	
	struct tagNode* NextNode;
	struct tagNode* PrevNode;

}Node;

// 링크드 큐 구현
typedef struct tagLinkedQueue
{
	Node* Front;
	Node* Rear;
	
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
extern int size (LinkedQueue * Queue );
extern int empty ( LinkedQueue * Queue );
extern int front ( LinkedQueue * Queue );
extern int back ( LinkedQueue * Queue );



/* 메인 함수 영역 */
int main() {
    
    int N; //명령의 수
    scanf("%d", &N);
    
    LinkedQueue * Queue;
    LQ_CreateQueue( &Queue );
    
    while ( N-- )
    {
        char order_String[15];
        scanf("%s", order_String );
        
        if ( strcmp(order_String, "push_front") == 0 )
        {
            int NewNum;
            scanf("%d", &NewNum);
            
            Node * NewNode = LQ_CreateNode( NewNum );
            
            push_front( Queue, NewNode );
        }
        
        else if ( strcmp(order_String, "push_back") == 0 )
        {
            int NewNum;
            scanf("%d", &NewNum);
            
            Node * NewNode = LQ_CreateNode( NewNum );
            
            push_back( Queue, NewNode );
        }
        
        else if ( strcmp(order_String, "pop_front") == 0 )
        {
            int pop_Num;
            
            pop_Num = pop_front( Queue );
            
            printf("%d\n", pop_Num);
        }
        
        else if ( strcmp(order_String, "pop_back") == 0 )
        {
            int pop_Num;
            
            pop_Num = pop_back( Queue );
            
            printf("%d\n", pop_Num);
        }
        
        else if ( strcmp(order_String, "size") == 0 )
        {
            printf("%d\n", size( Queue ) );
        }
        
        else if ( strcmp(order_String, "empty") == 0 )
        {
            printf("%d\n", empty( Queue ) );
        }
        
        else if ( strcmp(order_String, "front") == 0 )
        {
            printf("%d\n", front( Queue ) );
        }
        
        else if ( strcmp(order_String, "back") == 0 )
        {
            printf("%d\n", back( Queue ) );
        }
        
    }
    
    while(Queue->Count != 0)
    {
        int garbage_Num;
        garbage_Num = pop_front( Queue );
    }
    LQ_DestroyQueue(Queue);
    
    
    
    return 0;
}


/* 큐 관련 함수 영역 */

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

// 덱에 들어있는 정수의 개수를 출력한다.
int size (LinkedQueue * Queue )
{
    return Queue->Count;
}

// 덱이 비어있으면 1을, 아니면 0을 출력한다.
int empty ( LinkedQueue * Queue )
{
    return ( Queue->Count == 0);
}

// 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
int front ( LinkedQueue * Queue )
{
    if ( Queue->Front == NULL ) { return -1; }
    else
    {
        return Queue->Front->Data;
    }
    
}

// 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
int back ( LinkedQueue * Queue )
{
    if ( Queue->Rear == NULL ) { return -1; }
    else
    {
        return Queue->Rear->Data;
    }
    
}



