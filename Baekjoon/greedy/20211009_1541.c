#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    
    char String[51]; scanf("%s", String); // 입력으로 주어지는 식을 저장하는 배열
    int string_Len = strlen( String ); // 식의 길이
    
    int index_Num_Start = 0; // 문자열에서 숫자가 끝나는 시점.
    int result = 0; // 결과값.
    int sum_Beside_Minus = 0; // 마이너스 연산자 사이의 숫자들의 합.
    short code = 0; // 첫 마이너스 연산자를 만났을 때는 그냥 result에 다 더하고 가만히 있고 값을 1로 변경해준다.
    
    for (int now_Index = 0 ; now_Index < string_Len ; now_Index++ )
    {
        
        // 연산자위치까지 now_Index를 이동.
        while ( String[ now_Index ] != '+' && String[ now_Index ] != '-' && String[ now_Index ] != '\0' )
        {
            now_Index++;
        }
        
        // + 연산자인 경우 
        if ( String[ now_Index ] == '+' )
        {
            // 우선 다 더한다.
            int num = atoi( &String[ index_Num_Start ] );
            sum_Beside_Minus += num;
        }
        
        // - 연산자인 경우
        else if ( String[ now_Index ] == '-' )
        {
            // 첫 마이너스 연산자를 만난 경우와 이후의 경우를 다르게 판단.
            
            if ( code == 0 )
            {
                // result에 sum_Beside_Minus값을 그냥 더해준다.
                int num = atoi( &String[ index_Num_Start ] );
                sum_Beside_Minus += num;
                result += sum_Beside_Minus;
                sum_Beside_Minus = 0;
                
                code = 1;
            }
            
            else if ( code == 1 )
            {
                // 마이너스 앞 연산자 까지 더한 후 결과값에서 뺀다.
                int num = atoi( &String[ index_Num_Start ] );
                sum_Beside_Minus += num;
                result -= sum_Beside_Minus;
                sum_Beside_Minus = 0;
            
            }
            
        }
        
        // 문자열의 끝인 경우.
        else if ( String[ now_Index ] == '\0' )
        {
            
            // 마이너스 연산자가 한번도 안나온 경우 
            if ( code == 0 )
            {
                // sum_Beside_Minus 값을 result에 더해준다.
                int num = atoi( &String[ index_Num_Start ] );
                sum_Beside_Minus += num;
                result += sum_Beside_Minus;
                
                break;
            }
            
            // 마이너스 연산자가 한번이라도 나온 경우
            else if ( code == 1 )
            {
                // 문자열 앞 숫자까지 더한 후 결과값에서 뺀다.
                int num = atoi( &String[ index_Num_Start ] );
                sum_Beside_Minus += num;
                result -= sum_Beside_Minus;
                
                break;
            }
                
        }
        
        // 연산자 다음으로 숫자가 시작하는 배열의 인덱스 시점을 정해준다.
        index_Num_Start = now_Index + 1;
        
    }
    
    
    printf("%d", result);
    
    return 0;
}