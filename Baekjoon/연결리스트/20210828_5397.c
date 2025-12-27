#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//노드 구성요소.
typedef struct tagNode
{
    char text_Data;
    struct tagNode * PrevNode;
    struct tagNode * NextNode;
    char cursur; //해당 노드의 커서가 앞에 있는지 뒤에 있는지 알려준느 값 0은 앞 1은 뒤를 의미.
    
}Node;


extern Node * Create_Node (char NewData);
extern void Append_Front_Node( Node ** Current );
extern void Append_Back_Node( Node ** Current );
extern void Append_Bagic_Node( Node ** Current, Node * NewNode );
extern void Delete_Node( Node ** Current );



int main() {
    
    int test_Case; //테스트 케이스
    scanf("%d", &test_Case);
    
    
    for (int num_Try = 0; num_Try < test_Case ; num_Try++ )
    {// 테스트 케이스 하나하나 시작.
        
        
        Node * Current = NULL; //연결리스트의 현재 부분을 알려줄 노드 포인터
        unsigned int string_Length; //문자열의 길이를 저장 할 변수.
        char array_String[1000002]; //길이가 L인 문자열 입력받기.
        
        scanf("%s", array_String);
        
        string_Length = strlen(array_String);


        //문자 하나하나 받아들이면서 조건 실행.
        for (unsigned int now_Index = 0; now_Index < string_Length ; now_Index++ )
        {
            if ( array_String[now_Index] == '<' )
            {
                Append_Front_Node(&Current);
            }
            else if ( array_String[now_Index] == '>' )
            {
                Append_Back_Node(&Current);
            }
            else if ( array_String[now_Index] == '-' )
            {
                if ( Current != NULL)
                {
                    Delete_Node(&Current);
                }
                else {continue;}
                
            }
            else //문자값을 입력받았을 때
            {
                Node * NewNode = Create_Node( array_String[now_Index] );
                
                Append_Bagic_Node(&Current, NewNode);
            }
            
        }
        
        //비밀번호 출력.
        //우선 Current를 맨 앞 노드까지 이동시킨다.
        while ( Current != NULL && Current->PrevNode != NULL)
        {
            Current = Current->PrevNode;
        }
        //맨앞노드를 시작으로 맨끝 노드까지 문자 하나하나 출력하면서 이동.
        while ( Current != NULL && Current->NextNode != NULL )
        {
            printf("%c", Current->text_Data);
            Current = Current->NextNode;
        }
        if (Current != NULL) { printf("%c", Current->text_Data); }
        
        
        //노드를 free 시키기.
        //맨 뒤까지 이동된 노드를 앞으로 이동하면서 메모리 반환 시작.
        while ( Current != NULL && Current->PrevNode != NULL )
        {
            Current = Current->PrevNode;
            free ( Current->NextNode );
            Current->NextNode = NULL;
        }
        if ( Current != NULL)
        {
        free( Current );
        }
        
        printf("\n");
    }
    
    
    
    return 0;
}



/* 함수 구역 */

//노드 생성 함수.
Node * Create_Node (char NewData)
{
    Node * NewNode = (Node *)malloc(sizeof(Node));
    
    NewNode->text_Data = NewData;
    NewNode->PrevNode = NULL;
    NewNode->NextNode = NULL;
    NewNode->cursur = 1;
    
    return NewNode;
}

//커서를 앞으로 이동하는 함수.
void Append_Front_Node( Node ** Current )
{
    if ( (*Current) == NULL) {} //Current가 존재하지 않을 때.
    
    //Current가 맨 앞의 노드일 때
    else if ( (*Current) != NULL && (*Current)->PrevNode == NULL ) 
    {
        //맨 앞 노드이지만 다음 노드가 없는 경우
        if ( (*Current)->NextNode == NULL )
        {
            (*Current)->cursur = 0;
        }
        
        //맨 앞 노드이면서 다음 노드가 있는 경우.
        else
        {
            (*Current)->cursur = 0;
        }
        
    }
    
    //Current가 맨 뒤 노드 일 때
    else if ( (*Current) != NULL && (*Current)->PrevNode != NULL && (*Current)->NextNode == NULL  )
    {
        ( (*Current) = (*Current)->PrevNode );
    }
    
    //Current가 노드들 사이에 있을 때.
    else if ( (*Current) != NULL && (*Current)->PrevNode != NULL && (*Current)->NextNode != NULL ) 
    {
        ( (*Current) = (*Current)->PrevNode );
    }
    
}

//커서를 뒤로 이동하는 함수.
void Append_Back_Node( Node ** Current )
{
    if ( (*Current) == NULL ) {} //Current가 존재하지 않을 때
    
    //Current가 맨 앞의 노드일 때
    else if ( (*Current) != NULL && (*Current)->PrevNode == NULL ) 
    {
        //맨 앞 노드이지만 다음 노드가 없는 경우
        if ( (*Current)->NextNode == NULL )
        {
            if ( (*Current)->cursur == 0 ) //커서가 0인 경우
            {
                (*Current)->cursur = 1;
            }
            else //커서가 1인 경우
            {
                
            }
            
        }
        
        //맨 앞 노드이면서 다음 노드가 있는 경우.
        else if ( (*Current)->NextNode != NULL )
        {
            if ( (*Current)->cursur == 0 ) //커서가 0인 경우
            {
                (*Current)->cursur = 1;
            }
            else //커서가 1인 경우
            {
                (*Current) = (*Current)->NextNode;
            }
            
        }
        
        
        (*Current)->cursur = 1;
    } 
    
    //Current가 맨 뒤의 노드 일 때
    else if ( (*Current) != NULL && (*Current)->NextNode == NULL && (*Current)->PrevNode != NULL )  
    {
        //(*Current)->cursur = 1;
    } 
    
    // Current가 노드들 사이에 있을 때
    else if ( (*Current) != NULL && (*Current)->NextNode != NULL && (*Current)->PrevNode != NULL ) 
    {
        ( (*Current) = (*Current)->NextNode );
        //(*Current)->cursur = 1;
    }
    
}

//현재커서에 노드를 추가하는 함수.
void Append_Bagic_Node( Node ** Current, Node * NewNode )
{
    if ( (*Current) == NULL ) { (*Current) = NewNode; } //현재 Current의 값이 null인 경우.
    
    else if ( (*Current)->cursur == 0) //Current앞에 커서가 위치.
    {
        //Current가 맨 앞 노드 일 때
        if ( (*Current)->PrevNode == NULL)
        {
            (*Current)->PrevNode = NewNode;
            NewNode->NextNode = (*Current);
            (*Current)->cursur = 1;
            (*Current) = NewNode;
            (*Current)->PrevNode = NULL;
        }
        
        //else if ( (*Current)-> PrevNode != NULL) {}
        
    }
    
    else if ( (*Current)->cursur == 1) //Current 뒤에 커서가 위치.
    {
        //Current가 맨 뒤 노드 일 때.
        if ( (*Current)->NextNode == NULL && (*Current)->PrevNode != NULL ) 
        {
            (*Current)->NextNode = NewNode;
            NewNode->PrevNode = (*Current);
            (*Current) = NewNode;
        }
        
        //Current가 맨 앞 노드 일 때.
        else if ( (*Current)->NextNode != NULL && (*Current)->PrevNode == NULL ) 
        {
            (*Current)->NextNode->PrevNode = NewNode;
            NewNode->NextNode = (*Current)->NextNode;
            (*Current)->NextNode = NewNode;
            NewNode->PrevNode = (*Current);
            (*Current) = NewNode;
        }
        
        //Current가 맨 앞 노드인데 단독으로 존재
        else if ( (*Current)->NextNode == NULL && (*Current)->PrevNode == NULL ) 
        {
            (*Current)->NextNode = NewNode;
            NewNode->PrevNode = (*Current);
            (*Current) = NewNode;
        }
        
        // 노드가 노드 사이에 껴 있을 때
        else if ( (*Current)->NextNode != NULL ) //Current 앞 뒤로 노드가 있는 중간에 껴있는 경우 일 때.
        {
            (*Current)->NextNode->PrevNode = NewNode;
            NewNode->NextNode = (*Current)->NextNode;
            (*Current)->NextNode = NewNode;
            NewNode->PrevNode = (*Current);
            
            (*Current) = NewNode;
        }
    }
    
}

//커서앞 노드를 삭제.
void Delete_Node( Node ** Current )
{
    //Current값이 없을 경우
    if ( (*Current) == NULL )
    {
        
    }
    //Current값이 있는 경우
    
    //Current값이 제일 앞 노드인 경우
    else if ( (*Current)->PrevNode == NULL )
    {
        if ( (*Current)->cursur == 0) {}
        
        else if ( (*Current)->cursur == 1)
        {
            //Current 다음 노드가 존재하지 않는 경우
            if ( (*Current)->NextNode == NULL )
            {
                free ( (*Current) );
                (*Current) = NULL;
            }
            
            //Current 다음 노드가 존재하는 경우
            else if ( (*Current)->NextNode != NULL )
            {
                (*Current) = (*Current)->NextNode;
                free ( (*Current)->PrevNode );
                (*Current)->PrevNode = NULL;
                (*Current)->cursur = 0;
            }
        }
        
    }
    
    //Current값이 제일 끝인 경우
    else if ( (*Current)->PrevNode != NULL && (*Current)->NextNode == NULL )
    {
        (*Current) = (*Current)->PrevNode;
        free ( (*Current)->NextNode );
        (*Current)->NextNode = NULL;
    }
    
    //Current값이 노드 사이에 껴 있는 경우
    else if ( (*Current)->PrevNode != NULL && (*Current)->NextNode != NULL )
    {
        (*Current)->PrevNode->NextNode = (*Current)->NextNode;
        (*Current) = (*Current)->PrevNode;
        free ( (*Current)->NextNode->PrevNode );
        (*Current)->NextNode->PrevNode = (*Current);
    }
    

}


