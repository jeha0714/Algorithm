#include <stdio.h>
#include <stdlib.h>


/* Queue 변수 영역 */
int Front = 0; // pop하는데 사용되는 변수
int Rear = 0; // push하는데 사용되는 변수



/* Queue 관련 함수 영역 */

int Is_Size()
{
    if (Rear >= Front) { return Rear - Front; }
    else if ( Front > Rear ) { return Front - Rear; }
    
    return 0;
}


// push
void EnQueue ( int num, int * Queue, int Capacity )
{
    if ( Rear == Capacity )
    {
        Queue[Rear] = num;
        Rear = 0;
    }
    
    else 
    {
        Queue[Rear++] = num;
    }
    
}


// pop 메모리 내 값 제거 안함.
int DeQueue ( int * Queue, int Capacity ) 
{
    if ( Front == Capacity )
    {
        int Position = Queue[Front];
        Front = 0;
        
        return Position;
    }
    
    else
    {
        return Queue[Front++];
    }
    
}


// pop이지만 삭제함.
void DeleteQueue ( int * Queue, int Capacity )
{
    if ( Front == Capacity )
    {
        Front = 0;
    }
    
    else
    {
        Front++;
    }
    
}






int main() {
    
    
    int N, now_Num = 0;
    int delete_Num = 0;
    scanf("%d", &N);
    
    // 큐를 동적할당.
    int * Queue = (int *)malloc(sizeof(int) * (N) );
    
    for( int now_Index = 1; now_Index < ( N + 1 ) ; now_Index++ )
    {
        Queue[Rear++] = now_Index;
    }
    
    
    for ( int now_Index = 0 ; delete_Num < N - 1 ; now_Index++ )
    {
        if ( Queue[now_Index] != 0 )
        {
            if ( now_Num == 0 )
            {
                Queue[now_Index] = 0;
                delete_Num++;
                now_Num = 1;
            }
            
            else if ( now_Num == 1 )
            {
                now_Num = 0;
            }
            
        }
        
        else if ( Queue[now_Index] == 0 )
        {
            //continue;
        }
        
        
        if ( now_Index == N - 1 ) { now_Index = -1; }
        
    }
    
    for (int now_Index = 0 ; now_Index < N; now_Index++ )
    {
        if ( Queue[now_Index] != 0 ) { printf("%d", Queue[now_Index] ); break; }
    }
    
    
    
    return 0;
}


