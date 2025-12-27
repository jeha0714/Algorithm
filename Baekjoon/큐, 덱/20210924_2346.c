#include <stdio.h>
#include <stdlib.h>


/* 구조체 영역 */

typedef struct tagNode
{
    struct tagNode * PrevNode;
    struct tagNode * NextNode;
    
    int Index;
    int Data;
    
}Node;

/* 함수 영역 */

// 덱 내부 연결될 노드 생성 함수
Node * Create_Node ( int NewData , int now_Index)
{
    Node * NewNode = (Node *)malloc( sizeof( Node ) );
    
    NewNode->PrevNode = NULL;
    NewNode->NextNode = NULL;
    
    NewNode->Data = NewData;
    NewNode->Index = now_Index;
    
    return NewNode;
}


// 덱 내부 노드 제거 함수
void Destroy_Node ( Node * _Node )
{
    free(_Node);
}

// 덱 내부의 노드와 연결
void Append_Node ( Node * NewNode, Node ** Head )
{
    // 풍선 내부에 적힌 번호를 적을 변수.
    if ( (*Head) == NULL )
    {
        (*Head) = NewNode;
        NewNode->PrevNode = NewNode;
        NewNode->NextNode = NewNode;
    }
    
    // 덱에 노드가 하나라도 존재 할 경우
    else 
    {
        Node * Current = (*Head);
        
        while ( Current->NextNode != (*Head) )
        {
            Current = Current->NextNode;
        }
        
        NewNode->NextNode = Current->NextNode;
        Current->NextNode->PrevNode = NewNode;
        Current->NextNode = NewNode;
        NewNode->PrevNode = Current;
    }
    
}

// 덱 내부의 노드를 연결 제거
int Quit_Node ( Node ** Head, int num_Data )
{
    //헤드의 전후로 연결.
    if ( (*Head)->NextNode != (*Head) )
    {
        (*Head)->PrevNode->NextNode = (*Head)->NextNode;
        (*Head)->NextNode->PrevNode = (*Head)->PrevNode;
    }
    
    
    Node * Current = (*Head);
    int return_Num = 0; 
    
    // 적절하게 이동.
    if ( num_Data > 0)
    {
        while ( num_Data != 0)
        {
            Current = Current->NextNode;
            num_Data--;
        }
        
    }
    
    else if ( num_Data < 0 )
    {
        while ( num_Data != 0)
        {
            Current = Current->PrevNode;
            num_Data++;
        }
        
    }

    
    //Destroy_Node( (*Head) );
    
    // 새로운 헤드는 Current
    (*Head) = Current;
    printf("%d ", Current->Index + 1 );
    return_Num = Current->Data;
    

    return return_Num;
}





int main() {
    
    int balloon_Num; // 풍선의 개수를 입력받을 변수
    int move_Num = 0;
    Node * Head = NULL;
    
    scanf("%d", &balloon_Num);
    
    // 수를 차례대로 입력받으며 풍선 노드 생성
    for (int now_Index = 0 ; now_Index < balloon_Num ; now_Index++ )
    {
        int NewData; // 풍선 내부에 적힌 번호를 적을 변수.
        scanf("%d", &NewData);
        
        Node * NewNode = Create_Node( NewData, now_Index );
        Append_Node( NewNode , &Head );

    }
    

    // 처음부터 풍선을 제거해나가기 시작
    for(int now_Try = 0 ; now_Try < balloon_Num ; now_Try++ )
    {
        move_Num = Quit_Node( &Head, move_Num );
    }
    
    
    
    return 0;
}