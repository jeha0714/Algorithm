#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Front = 0;
int Rear = 0;


extern void push(int num, int * Queue);
extern int pop(int * Queue);
extern int size(int * Queue);
extern int empty(int * Queue);
extern int front(int * Queue);
extern int back(int * Queue);





int main() {
    
    int N; // 명령의 수 N
    scanf("%d", &N);
    
    int * Queue = (int *)malloc(sizeof(int) * ( N + 1 ));
    
    
    for (int num_Try = 0; num_Try < N; num_Try++ )
    {
        char order[10];
        scanf("%s", order);
        
        
        if ( strcmp(order, "push") == 0 )
        {
            int input_Num;
            scanf("%d", &input_Num);
            
            push(input_Num, Queue);
        }
        
        else if ( strcmp(order, "pop") == 0 )
        {
            printf("%d\n", pop(Queue) );
        }
        
        else if ( strcmp(order, "size") == 0 )
        {
            printf("%d\n", size(Queue) );
        }
        
        else if ( strcmp(order, "empty") == 0 )
        {
            printf("%d\n", empty(Queue) );
        }
        
        else if ( strcmp(order, "front") == 0 )
        {
            printf("%d\n", front(Queue) );
        }
        
        else if ( strcmp(order, "back") == 0 )
        {
            printf("%d\n", back(Queue) );
        }
        
    }
    
    
    
    
    return 0;
}


/*큐 함수 영역*/

void push(int num, int * Queue)
{
    Queue[Rear] = num;
    
    Rear++;
}


int pop(int * Queue)
{
    if ( Queue[Front] == 0 )
    {
        return -1;
    }
    
    else
    {
        int answer = Queue[Front++];
        Queue[Front - 1] = 0;
        
        return answer;
    }
        
}


int size(int * Queue)
{
    return Rear - Front ;
}


int empty(int * Queue)
{
    if ( Front - Rear == 0 )
    {
        return 1;
    }
    
    else
    {
        return 0;
    }
    
}


int front(int * Queue)
{
    if ( Queue[Front] == 0 )
    {
        return -1;
    }
    
    else
    {
        return Queue[Front];
    }
}


int back(int * Queue)
{
    if ( Queue[Rear - 1] == 0 )
    {
        return -1;
    }
    
    else
    {
        return Queue[Rear - 1];
    }
}


