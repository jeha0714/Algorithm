#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


// 사용 가능한 버튼만 이용했는지 알기 위함 함수
int can_Use_All_Button( char array_now_Try[] , int array_now_Try_Length , int array_break_Button[] )
{
    for (int now_Index = 0 ; now_Index < array_now_Try_Length ; now_Index++ )
    {
        // array_break_Button의 값이 1은 버튼이 고장남을 의미. 
        if ( array_break_Button[ array_now_Try [ now_Index ] % 48 ] == 1 )
        {
            return 0;
        }
        
    }
    
    // return값이 1인경우는 정상 진행, 0 인경우는 사용 불가한 버튼을 사용한 경우 반환.
    return 1;
}





int main() {
    
    int now_Channel = 100; // 현재 채널
    char num_Char[7]; // 이동하려고 하는 채널을 char형으로 저장
    int move_Channel = 0; // 이동하려는 채널을 int형 배열로 저장
    
    int num_break_Button; // 고장난 버튼의 개수
    int array_break_Button[ 10 ] = { 0 }; // 고장난 버튼을 저장한 배열 0은 사용가능 1은 고장남.
    
    int first_Plus_Minus = 0; //+ - 버튼으로만 이동한 횟수를 저장한 변수

    
    scanf("%s", num_Char);
    move_Channel = atoi(num_Char);

    
    scanf("%d", &num_break_Button);
    for (short i = 0 ; i < num_break_Button ; i++ ) 
    {
        // 고장난 버튼이 무엇인지 입력받으면서 고장났다고 1로 초기화시키기.
        int break_Button;
        scanf("%d", &break_Button);
        array_break_Button[ break_Button ] = 1;
    }
    
    
    // + - 버튼으로만 움직인 횟수를 계산
    first_Plus_Minus = move_Channel - now_Channel >= 0 ? move_Channel - now_Channel : now_Channel - move_Channel;
    
    
    /* 사용가능한 모든 버튼을 이용하여 움직인 횟수를 계산 */
    
    // 브루트포스 알고리즘으로 0부터 500000 까지 대입 후 
    // 사용 할 수 없는 버튼이 있는 경우 continue, 전부 사용 가능 할 시 + - 추가 연산으로 총 버튼 사용횟수를 계산
    // 기존 first_Plus_Minus의 값과 비교 후 작을 시 그 값으로 초기화시키기.
    
    for (int now_Try = 0 ; now_Try < 1000001 ; now_Try++ )
    {
        char array_now_Try[8]; // now_Try가 문자열로 저장되었을 때
        int array_now_Try_Length; // 문자열로 저장된 정수의 길이
        
        sprintf(array_now_Try, "%d", now_Try); // 정수를 문자열로 변환
        array_now_Try_Length = strlen ( array_now_Try );
        
        // 사용불가능한 버튼이 있는지 판단
        if ( can_Use_All_Button( array_now_Try, array_now_Try_Length, array_break_Button ) == 1 )
        {
            // 사용가능한 버튼들만 사용한 경우 그 값이 현재 기록된 버튼 누른 횟수보다 판단 후 기록 최신화.
            if ( first_Plus_Minus > array_now_Try_Length + abs( now_Try - move_Channel ) )
            {   
                //printf("%d\n", now_Try);
                first_Plus_Minus = array_now_Try_Length + abs( now_Try - move_Channel );
            }
            
            
        }
        else if ( can_Use_All_Button( array_now_Try, array_now_Try_Length,array_break_Button ) == 0 )
        // 사용 불가능한 버튼이 하나라도 있는 경우 continue
        {
            continue;
        }
        
    }
    
    
    printf("%d", first_Plus_Minus );
    
    return 0;
}