#include <stdio.h>

int main() {
    
    int num_Stair; scanf("%d", &num_Stair); // 계단의 개수
    int score_Stair[ num_Stair ]; // 아래 계단부터 순서대로 계단에 쓰여진 점수
    int max_each_Stair[ num_Stair ]; // 각 계단까지 올라오면서 얻을 수 있는 가장 큰 점수
    int how_Get[ num_Stair ]; // 각 계단의 최고점을 얻기위해 해당 계단을 마지막에 어떻게 왔는지. 1은 1계단 2는 2계단 1은 점프.
    int max_Score = 0; // 게임에서 얻을 수 있는 최대 점수를 저장한 변수값.
    
    for (int index = 0; index < num_Stair ; index++ ) 
    { 
        scanf("%d", &score_Stair[ index ] ); 
        max_each_Stair[ index ] = 0;
        how_Get[ index ] = 0;
    }
    
    // max_each_Stair의 1~2 ( 0 ~ 1 인덱스)계단들은 직접 값을 설정.
    if ( num_Stair > 1 )
        max_each_Stair[ 1 ] = score_Stair[ 0 ] + score_Stair[ 1 ]; how_Get[ 1 ] = 2;
        
    max_each_Stair[ 0 ] = score_Stair[ 0 ]; how_Get[ 0 ] = 1;
    
    // 각 케이스를 연속되던 점프해서 오던 모든 상황을 고려해서 최대인경우를 구함. -> 밑계단의 값이 사용되나..?
    for (int index = 2 ; index < num_Stair ; index++ )
    {
        // 전의 계단에 오기까지 점프나 1계단을 밟은 경우.
        if ( how_Get[ index - 1 ] != 2 )
        {
            // 전 계단을 통해 현재 계단을 밟았을 때의 최대값과 전전의 계단에서 점프해온 경우의 최대값을 구한다.
            int one_Before = max_each_Stair[ index - 1 ] + score_Stair[ index ];
            int jump_Before = max_each_Stair[ index - 2 ] + score_Stair[ index ];
            
            if ( jump_Before < one_Before )
            {
                max_each_Stair[ index ] = one_Before;
                how_Get[ index ] = 2;
            }
            else
            {
                max_each_Stair[ index ] = jump_Before;
                how_Get[ index ] = 1;
            }
            
        }
        
        // 전의 계단에 오기까지 2계단을 밟은 경우.
        else if ( how_Get[ index - 1 ] == 2 )
        {
            // 전전계단에서 점프해온 경우와 전전전계단에서 전계단으로 점프해온 후 현재계단으로 도착한 경우 중
            // 최대값을 저장.
            int jump_Before = max_each_Stair[ index - 2 ] + score_Stair[ index ];
            int one_Before = max_each_Stair[ index - 3 ] + score_Stair[ index - 1 ] + score_Stair[ index ];
            
            if ( jump_Before < one_Before )
            {
                max_each_Stair[ index ] = one_Before;
                how_Get[ index ] = 2;
            }
            else
            {
                max_each_Stair[ index ] = jump_Before;
                how_Get[ index ] = 1;
            }
                
        }
        
    }
    
        
    printf("%d", max_each_Stair[ num_Stair - 1 ] );
    
    return 0;
}