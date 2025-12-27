#include <stdio.h>


int stack[500001];
int top = -1;



 void push(int num)
 {
     stack[++top] = num;
 }
 
void pop()
{
    top--;
    
}



int main() {
    
    int made_Num_Length; // 만만들어져야할 수의 길이
    int num_Length, num_Delete; // num_Length자리 수와 num_Delete개의 지워질 수
    
    scanf("%d %d", &num_Length, &num_Delete);
    
    made_Num_Length = num_Length - num_Delete;
    
    char array_Num[ num_Length ]; // num_Length자리수에 해당하는 숫자를 저장할 배열
    scanf("%s", array_Num);
    
    
    
    for ( int now_Index = 0 ; now_Index < num_Length ; now_Index++ )
    {
        //stack이 비었을 시 우선 채워준다.
        if ( top == -1 ) { push( now_Index ); }
        
        else //스택에 하나라도 있을 시
        {
            // 스택의 탑보다 현재인덱스의 저장된 값이 작은 경우는 남은 index 수를 확인 후
            if ( array_Num[ stack[ top ] ] > array_Num[ now_Index ] )
            {
                // 남은 인덱스가 만들어져야할 수 길이보다 클 경우에는 
                // push.
                if ( num_Length - now_Index + 1 > made_Num_Length )
                {
                    push( now_Index );
                }
                
                // 남은 인덱스가 만들어져야할 수 길이와 같을 경우에는 (작을 경우가 존재해서는 안됨.)
                // 그대로 스택 push.
                else
                {
                    push( now_Index );
                }
                
            }
            
            // 스택의 탑보다 현재인덱스의 저장된 값이 큰 경우는 남은 index 수를 확인 후
            else if ( array_Num[ stack[ top ] ] == array_Num[ now_Index ] )
            {
                push( now_Index );
            }
            
            else if ( array_Num[ stack[ top ] ] < array_Num[ now_Index ] )
            {
                // 남은 인덱스가 만들어져야할 수 길이보다 클 경우에는 
                // 탑을 계속 팝함과 동시에 그 인덱스의 값보다 작을때와 탑과 남아있는 인덱스로도 수를 만들 수 있을 때 까지
                // pop 후 값을 push.
                
                while ( top != -1 && array_Num[ stack[ top ] ] < array_Num[ now_Index ] && num_Length - now_Index + top + 1 > made_Num_Length )
                {
                    pop();
                }
                    
                push( now_Index );
                
            }
            
        }
        
    }
    
    
    for (int now_Index = 0; now_Index < made_Num_Length ; now_Index++ )
    {
        printf("%c", array_Num[ stack[now_Index] ] );
    }
    
    
    
    return 0;
}
