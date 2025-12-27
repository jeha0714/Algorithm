#include <stdio.h>
#include <string.h>



int main() {
    
    int main_String_Length, boom_String_Length; // 주어지는 문자열과 폭발 문자열의 길이 저장
    char main_String[1000002];
    char result_String[1000002];
    char boom_String[37];
    int current_Index = 0; // result_String의 현재 인덱스 위치를 나타냄.
    
    scanf("%s %s", main_String, boom_String);
    
    main_String_Length = strlen( main_String );
    boom_String_Length = strlen( boom_String );
    
    
    
    for ( int now_Index = 0 ; now_Index < main_String_Length ; now_Index++ )
    {
        // result_String의 현재 인덱스가 폭발 문자열의 길이보다 작을 경우 push 우선.
        result_String[ current_Index++ ] = main_String[ now_Index ];
         
        result_String[ current_Index ] = '\0';
         
        // result_String의 현재 인덱스가 폭발 문자열의 길이보다 클 경우 
        // 배열의 탑부터 폭발 문자열 길이만큼 폭발 문자열과 비교하여 폭발 유무 확인.
        if ( current_Index  + 1 >= boom_String_Length  )
        {
            if ( strncmp( &result_String[ current_Index - boom_String_Length ] , boom_String, boom_String_Length) == 0 )
            {
                int go_Back = current_Index - boom_String_Length;
                
                while ( current_Index != go_Back )
                {
                    result_String[ --current_Index ] = ' ';
                }
                    
            }
            
        }
         
    }
    
    
    // result_String의 마지막 위치에 널값 삽입
    result_String[ current_Index ] = '\0';
    
    if ( result_String[0] == '\0' ) { printf("FRULA"); }
    else { printf("%s", result_String); }
    
    return 0;
}