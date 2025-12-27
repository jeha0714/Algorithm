#include <stdio.h>

int main() {
    
    int min_Result = 0; //연산의 최솟값을 저장한 변수
    int current_Location = 1; // 큐 내부에서 현재 위치를 저장한 변수
    
    int num_N;
    int N, M; // 큐의 크기 N, 뽑아내려고 하는 수의 개수 M;
    scanf("%d %d", &N, &M); num_N = N;
    
    int array_Num[N]; //인덱스가 0부터 N -1 까지 있는 배열. index +1 이라 생각해서 큐라고 생각.
    for (int now_Index = 0 ; now_Index < N; now_Index++ ) { array_Num[now_Index] = 1; } //해당 인덱스 값이 1인경우 pop이 안된 상태를 의미.
    
    int pop_Num[M]; // 뽑아내려고 하는 수들이 저장된 배열
    for (int now_Index = 0 ; now_Index < M ; now_Index++ ) { scanf("%d", &pop_Num[now_Index]); }

    
    for ( int now_Index_Try = 0; now_Index_Try < M ; now_Index_Try++ )
    {
        int moving_Way1 = 0; //뽑아내려는 수를 찾으러 오른쪽으로 이동시키는 방법
        int moving_Way2 = 0;// 뽑아내려는 수를 찾으러 왼쪽으로 이동시키는 방법
        
        
        if ( current_Location == pop_Num[now_Index_Try] ) //현재 위치가 current_Location와 같은 경우
        { 
            
            moving_Way1 = 0;
            
            array_Num[ current_Location - 1 ] = 0;
            while ( array_Num[current_Location - 1] == 0 )
            {
                if ( N == 1 ) { break; }
                
                if ( current_Location == num_N )
                {
                    current_Location = 1;
                }
                    
                else { current_Location++; }
                
            }

            
        }
        
        // current_Location보다 pop_Num위치가 오른쪽에 있는경우  moving_Way1 값으로 구함.
        else if ( current_Location < pop_Num[now_Index_Try] )
        {
            // 현재 위치에서 오른쪽으로 이동. 단, 존재하는 수 (1로 등록)을 참고하며 갈 것
            while ( current_Location != pop_Num[now_Index_Try] )
            {
                // 다음 +1 한 수가 존재하는 경우
                if ( array_Num[ current_Location - 1 ] == 1 )
                {
                    moving_Way1++;
                    current_Location++;
                }
                // 다음 +1 한 수가 존재하지 않는 경우
                else
                {
                    current_Location++;
                }
                
            }
            
            // current_Location와 pop_Num이 같은 경우 해당 값을 pop(0으로 초기화)해주고 다음 수로 이동.
            array_Num[ current_Location - 1 ] = 0;
            while ( array_Num[current_Location - 1] == 0 )
            {
                if ( current_Location == num_N )
                {
                    current_Location = 1;
                }
                
                else { current_Location++; }
                
            }

        }
        
        
        // current_Location보다 pop_Num위치가 오른쪽에 있는경우  moving_Way2 값으로 구함.
        else if ( current_Location > pop_Num[now_Index_Try] )
        {
            // 현재 위치에서 왼쪽으로 이동. 단, 존재하는 수 (1로 등록)을 참고하며 갈 것
            while ( current_Location != pop_Num[now_Index_Try] )
            {
                // 다음 +1 한 수가 존재하는 경우
                if ( array_Num[ current_Location - 1 ] == 1 )
                {
                    moving_Way2++;
                    current_Location--;
                }
                // 다음 +1 한 수가 존재하지 않는 경우
                else
                {
                    current_Location--;
                }
                
            }

            // current_Location와 pop_Num이 같은 경우 해당 값을 pop(0으로 초기화)해주고 다음 수로 이동.
            array_Num[ current_Location - 1 ] = 0;
            while ( array_Num[current_Location - 1] == 0 )
            {
                if ( current_Location == num_N )
                {
                    current_Location = 1;
                }
                
                else { current_Location++; }
                
            }

        }
        
        
        if ( moving_Way1 == 0 ) { moving_Way1 = N - moving_Way2; }
        else { moving_Way2 = N - moving_Way1; }
        
        
        if ( moving_Way1 >= moving_Way2 ) { min_Result += moving_Way2; }
        else { min_Result += moving_Way1; }
        
        
        N--; // 큐 내부에 원소 하나가 pop 된 것을 표현
    }
    
    
    printf("%d", min_Result );
    
    
    return 0;
}