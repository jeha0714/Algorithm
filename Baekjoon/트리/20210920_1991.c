#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 노드 구조체 선언
typedef struct tagNode
{
    struct tagNode * left_Child;
    struct tagNode * right_Child;
    
    char Data;
}Node;


/* 함수 재선언 영역 */
extern Node * Create_Node( char NewData );
extern void Destroy_Node( Node * _Node );
extern void Destroy_Tree ( Node * Root );
extern void PreorderPrintTree( Node * Root );
extern void InorderPrintTree( Node * Root );
extern void PostPrintTree( Node * Root );



int main() {
    
    int num_Node; // 노드의 개수
    Node * Root = NULL;
    
    scanf("%d", &num_Node);
    getchar();
    
    Node * Node_Point[num_Node];
    Root = NULL;
    
    // 노드 연결
    for (int now_Try = 0 ; now_Try < num_Node ; now_Try++ )
    {
        char Parent, left, right; // 각각 부모와 자식들의 노드
        
        scanf("%c %c %c", &Parent, &left, &right );

        if ( Root == NULL ) // 트리가 존재하지 않는 경우 트리부터 생성
        {
            Root = Create_Node( Parent );
            Node_Point[ (int)Parent % 65 ] = Root;
            
            if ( left != '.' )
            {
                Node * Left_Node = Create_Node( left );
                Node_Point[ (int)left % 65 ] = Left_Node;
                
                Root->left_Child = Left_Node;
            }
            
            if ( right != '.' )
            {
                Node * Right_Node = Create_Node( right );
                Node_Point[ (int)right % 65 ] = Right_Node;
                
                Root->right_Child = Right_Node;
            }
            
        }
        
        else // Root 가 존재할 때
        {
            Node * Parent_Node = Node_Point[ (int)Parent % 65 ];
            
            if ( left != '.' )
            {
                Node * Left_Node = Create_Node( left );
                Node_Point[ (int)left % 65 ] = Left_Node;
                
                Parent_Node->left_Child = Left_Node;
            }
            
            if ( right != '.' )
            {
                Node * Right_Node = Create_Node( right );
                Node_Point[ (int)right % 65 ] = Right_Node;
                
                Parent_Node->right_Child = Right_Node;
            }
            
        }
        
        getchar();
    }
    
    
    //전위순환
    PreorderPrintTree( Root );
    printf("\n");
    
    //중위순환
    InorderPrintTree( Root );
    printf("\n");
    
    //후위순환
    PostPrintTree( Root );
    printf("\n");
    
    
    return 0;
}



/* 트리 함수 영역 */

Node * Create_Node( char NewData )
{
    Node * NewNode = (Node *)malloc( sizeof(Node) );
    
    NewNode->left_Child = NULL;
    NewNode->right_Child = NULL;
    
    NewNode->Data = NewData;
    
    return NewNode;
}

void Destroy_Node( Node * _Node )
{
    free( _Node );
}

void Destroy_Tree ( Node * Root )
{
    if ( Root == NULL )
    {    return;}
        
    // 왼쪽 트리 제거
    Destroy_Tree( Root->left_Child );
    
    // 오른쪽 트리 제거
    Destroy_Tree( Root->right_Child );
    
    //본인 제거
    Destroy_Node( Root );
    
}

// 전위순환
void PreorderPrintTree( Node * Root )
{
    if ( Root == NULL )
    {    return;}
        
    printf("%c", Root->Data);
    
    // 왼쪽 트리 
    PreorderPrintTree(Root->left_Child);
    
    // 오른쪽 트리
    PreorderPrintTree(Root->right_Child);
}


// 중위순환
void InorderPrintTree( Node * Root )
{
    if ( Root == NULL )
    {    return;}
    
    // 왼쪽 트리 
    InorderPrintTree(Root->left_Child);
    
    printf("%c", Root->Data);
    
    // 오른쪽 트리
    InorderPrintTree(Root->right_Child);
}


// 후위순환
void PostPrintTree( Node * Root )
{
    if ( Root == NULL )
    {    return;}
    
    // 왼쪽 트리 
    PostPrintTree(Root->left_Child);
    
    // 오른쪽 트리
    PostPrintTree(Root->right_Child);
    
    printf("%c", Root->Data);
}





