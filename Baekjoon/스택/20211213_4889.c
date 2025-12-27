#include <stdio.h>
#include <string.h>

int main()
{
    for( int now_Try = 1;  ; now_Try++ )
    {
        char stack[ 2001 ]; // 스택
        
        char String[ 2001 ]; // 문자열
        scanf("%s", String );
        
        // - 가 하나 이상 주어질 경우 반복문 종료
        if ( String[0] == '-' )
            break;
        
        
        int String_Len = strlen( String ); // String의 길이
        int stack_Index = 0; // stack 배열의 인덱스
        
        // 안정적인지 판별하기 위해 스택을 이용해 push 및 pop 진행
        for ( int now_Index = 0 ; now_Index < String_Len ; now_Index++ )
        {
            if ( String[ now_Index ] == '{' )
                stack[ stack_Index++ ] = '{';
                
            
            else if ( String[ now_Index ] == '}' )
            {
                if ( stack[ stack_Index - 1 ] == '{' )
                    stack_Index -= 1;
                    
                else
                    stack[ stack_Index++ ] = '}';
            }
            
        }
        
        // 스택 삽입이 끝난 뒤
        
        // 스택이 비었다면
        if ( stack_Index == 0 )
            printf("%d. 0\n", now_Try );
        
        //스택에 뭔가 남아있다면
        else
        {
            int change = 0;
            
            for ( ; stack_Index > 0 ; )
            {
                if ( stack[ stack_Index -1 ] == stack[ stack_Index -2 ] )
                {
                    change += 1;
                    stack_Index -= 2;
                }
                
                else if ( stack[ stack_Index -1 ] != stack[ stack_Index -2 ] )
                {
                    change += 2;
                    stack_Index -= 2;
                }
                
            }
            
            
            printf("%d. %d\n", now_Try, change );
        }
        
    }

    return 0;
}
