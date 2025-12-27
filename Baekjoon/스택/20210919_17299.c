#include <stdio.h>

int Stack[ 1000001 ];
int top = -1;

void push(int num) { Stack[ ++top ] = num; }
int pop() { return Stack[ top-- ]; }



int main() {
    
    int array_Size; // 수열 array_A의 크기
    scanf("%d", &array_Size);
    
    int array_A[ array_Size ]; // 수열
    int array_Appear[ 1000001 ] = { 0 }; // 각 수가 등장한 횟수를 저장할 배열
    int result[ array_Size ];
    
    for (int now_Index = 0; now_Index < array_Size ; now_Index++ )
    {
        scanf("%d", &array_A[ now_Index ] ); //수열 입력받기
        array_Appear[ array_A[ now_Index ] ]++; //해당 수의 등장 횟수를 +1
    }
    
    for (int now_Index = 0; now_Index < array_Size ; now_Index++ )
    {
        if ( top == -1 ) { push( now_Index ); }
        
        else
        {
            // 값이 같은 경우
            if ( array_Appear[ array_A[ Stack[ top ] ] ] == array_Appear[ array_A[ now_Index ] ] )
            {
                push(now_Index);
            }
            
            // 현재 인덱스의 내부 값의 등장횟수가 탑의 인덱스의 내부 값의 등장횟수보다 클 때
            else if ( array_Appear[ array_A[ Stack[ top ] ] ] < array_Appear[ array_A[ now_Index ] ] )
            {
                //top의 등장횟수가 현재 인덱스의 등장횟수보다 클때 까지 pop
                while ( top != -1 && array_Appear[ array_A[ Stack[ top ] ] ] < array_Appear[ array_A[ now_Index ] ] )
                {
                    result[ Stack[ top ] ] = array_A[ now_Index ];
                    pop();
                }
                
                push(now_Index);
            }
            
            // 현재 인덱스의 내부 값의 등장횟수가 탑의 인덱스의 내부 값의 등장횟수보다 작을 때
            else if ( array_Appear[ array_A[ Stack[ top ] ] ] > array_Appear[ array_A[ now_Index ] ] )
            {
                push(now_Index);
            }
            
        }
        
    }
    
    //스택 내부에 남은 인덱스의 결과값을 -1로 대입.
    while ( top != -1 )
    {
        result[ Stack[ top ] ] = -1;
        pop();
    }
    
    // 결과값을 출력.
    for (int now_Index = 0 ; now_Index < array_Size; now_Index++ )
    {
        printf("%d ", result[ now_Index ] );
    }
    
    return 0;
}