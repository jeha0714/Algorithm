#include <stdio.h>
#include <string.h>


void getFailFunc ( char P[], int P_Length, int P_String_PI[]  )
{
    int i = 0, j = 1;
    
    P_String_PI[0] = 0;
    
    for ( ; j < P_Length ; j++ )
    {
        while ( i > 0 && P[ i ] != P[ j ] )
            i = P_String_PI[ i - 1 ];
        
        if ( P[ i ] == P[ j ])
            P_String_PI[ j ] = ++i;
        else
            P_String_PI[ j ] = 0;
        
    }
    
}


void KMP ( char * main_String, int main_S_Length, char * P_String, int P_Length, int PI[], int * Count )
{
    int i = 0, j = 0;
    
    for ( ; i < main_S_Length ; i++ )
    {
        while ( main_String[ i ] != P_String[ j ] )
        {
            if ( j == 0 )
                break;
            
            j = PI[j - 1];
        }
        
        if ( main_String[ i ] == P_String[ j ] )
        {
            j++;
            
            if ( j == P_Length )
            {
                *Count += 1;
                j = PI[j - 1];
            }
            
        }
        
    }
    
}






int main() {
    
    int Count = 0; // main_String에 P(N)이 몇 군데 포함되어 있는지 저장하는 변수
    int N, M; // N은 문제에 해당하는 P(N)속 N을 의미, M은 main_String의 길이
    scanf("%d %d", &N, &M);
    
    char P_String[2*N + 2];
    int P_String_PI[2*N + 1];
    char main_String[M]; // 문자열 main_String이 주어짐.
    scanf("%s", main_String);
    
    // P(N)을 P_String에 정의해줌.
    P_String[0] = 'I';
    for (int now_Index = 1; now_Index < 2*N + 1 ; now_Index++ )
    {
        if ( now_Index % 2 == 0 )
            P_String[ now_Index ] = 'I';
        else
            P_String[ now_Index ] = 'O';
    }
    P_String[2*N + 1] = '\0';
    
    
    //main_String인덱스 처음부터 범위되는 곳 까지 비교하면서 reuslt값을 증가시켜줌.
    getFailFunc( P_String, strlen(P_String), P_String_PI);
    KMP( main_String, strlen(main_String), P_String, strlen(P_String), P_String_PI, &Count);
    
    // 결과 값 출력
    printf("%d", Count );
    
    return 0;
}