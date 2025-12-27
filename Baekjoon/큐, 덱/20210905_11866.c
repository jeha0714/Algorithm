#include <stdio.h>
#include <stdlib.h>


/* 구조체 선언 영역 */
typedef struct tagNode
{
    int Data;
    struct tagNode * NextNode;
    
}Node;


typedef struct tagLinkedQueue
{
    Node * Front;
    Node * Rear;
    int Count;
    
}LinkedQueue;


/* 아래 함수들 재 등록 영역 */
extern void LQ_CreateQueue(LinkedQueue** Queue);
extern void LQ_DestroyQueue(LinkedQueue* Queue);
extern Node* LQ_CreateNode(int NewData);
extern void LQ_DestroyNode(Node* _Node);
extern void LQ_Enqueue(LinkedQueue* Queue, Node* NewNode);
extern int LQ_Dequeue(LinkedQueue* Queue);




int main() {
    
    int N, K;
    int Output = 0;
    scanf("%d %d", &N, &K);
    
    // 큐 생성
    LinkedQueue * Queue;
    LQ_CreateQueue( &Queue );
    
    
    // 큐 내부에 수열 입력 및 연결
    for (int num = 1; num <= N; num++)
    {
        Node * NewNode;
        NewNode = LQ_CreateNode(num);
        
        LQ_Enqueue(Queue, NewNode);
    }
    
    // K 번째 수를 차례로 출력.
    printf("<");
    for (int now_Num = 1; now_Num <= K  ; now_Num++ )
    {
        
        if ( now_Num == K )
        {
            printf("%d", LQ_Dequeue(Queue) );
            Output++;
        }
        
        else 
        {
            int moving_Num = LQ_Dequeue(Queue);
            
            Node * NewNode;
            NewNode = LQ_CreateNode(moving_Num);
            
            LQ_Enqueue( Queue, NewNode );
        }
        
    }
    
    
    for (int now_Num = 1; Output < N  ; now_Num++ )
    {
        
        if ( now_Num == K )
        {
            printf(", %d", LQ_Dequeue(Queue) );
            now_Num = 0;
            Output++;
        }
        
        else 
        {
            int moving_Num = LQ_Dequeue(Queue);
            
            Node * NewNode;
            NewNode = LQ_CreateNode(moving_Num);
            
            LQ_Enqueue( Queue, NewNode );
        }
        
    }
    printf(">");
    
    
    
    
    return 0;
}




/* 큐 관련 함수 영역 */

// 큐 생성
void LQ_CreateQueue ( LinkedQueue ** Queue )
{
    (*Queue) = (LinkedQueue *)malloc(sizeof(LinkedQueue));
    
    (*Queue)->Front = NULL;
    (*Queue)->Rear = NULL;
    (*Queue)->Count = 0;
    
}

// 큐 제거
void LQ_DestroyQueue (LinkedQueue *Queue)
{
    free(Queue);
}


// 노드 생성
Node * LQ_CreateNode ( int NewData )
{
    Node * NewNode = (Node *)malloc(sizeof(Node));
    
    NewNode->Data = NewData;
    NewNode->NextNode = NULL;
    
    return NewNode;
}


// 노드 제거
void LQ_DestroyNode (Node * _Node )
{
    free(_Node);
}


// 노드 push
void LQ_Enqueue ( LinkedQueue * Queue, Node * NewNode)
{
    if (Queue-> Front == NULL)
    {
        Queue->Front = NewNode;
        Queue->Rear = NewNode;
        Queue->Count++;
    }
    
    else
    {
        Queue->Rear->NextNode = NewNode;
        Queue->Rear = NewNode;
        Queue->Count++;
    }
    
}


// 노드 pop
int LQ_Dequeue ( LinkedQueue * Queue)
{
    int Front = Queue->Front->Data;
    Node * Destroy = Queue->Front;
    
    if ( Queue->Front->NextNode == NULL )
    {
        Queue->Front = NULL;
    }
    
    else
    {
        Queue->Front = Queue->Front->NextNode;
    }
    
    Queue->Count--;
    free (Destroy);
    
    return Front;
}




