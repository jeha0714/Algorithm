#include <stdio.h>

int stack_Num_Index[1000000];
int index_top = -1;

extern void push(int index);
extern void pop();



int main() {
    
    int num_All; //수열에 들어있는 수의 개수
    scanf("%d", &num_All);
    
    int num_Array[num_All]; //수열이 입력될 배열
    int result_Array[num_All]; //오큰수가 저장될 배열
    for (int now_Index = 0 ; now_Index < num_All ; now_Index++) { num_Array[now_Index] = 0; result_Array[now_Index] = -1; }
    
    for (int now_Index = 0; now_Index < num_All; now_Index++)
    {
        // 값을 입력받는다.
        scanf("%d", &num_Array[now_Index]);
        
        if ( index_top == -1 )
        {
            push ( now_Index );
        }
        
        else if ( num_Array[now_Index] <= num_Array[ stack_Num_Index[index_top] ] )
        {
            push ( now_Index );
        }
        
        else if ( num_Array[now_Index] > num_Array[ stack_Num_Index[index_top] ] )
        {
            while ( num_Array[now_Index] > num_Array[ stack_Num_Index[index_top] ] && index_top != -1 )
            {
                result_Array[ stack_Num_Index[index_top] ] = num_Array[now_Index];
                pop();
            }
            
            push ( now_Index );
        }
        
        
        
    }
    
    // 결과값 출력
    for (int now_Index = 0; now_Index < num_All; now_Index++) { printf("%d ", result_Array[now_Index] ); }
    
    
    return 0;
}


void push(int index)
{
    stack_Num_Index[++index_top] = index;
}


void pop() 
{ 
    index_top--;
}

