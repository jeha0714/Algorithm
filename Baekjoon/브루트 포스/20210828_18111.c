#include <stdio.h>

int main() {
    
    short N, M, max_Land; ////세로 N 가로 M, 땅의 높이.
    int B, min_Time = 64000000; //현재 가지고 있는 블록 B, 사용된 시간이 저장될 변수 min_Time
    scanf("%hd %hd %d", &N, &M, &B);
    
    short array[N][M];
    for (int length = 0; length < N; length++ )
    {
        for (int width = 0 ; width < M ; width++ )
        {
            scanf("%hd", &array[length][width]);
        }
    }
    
    
    //브루트포스 알고리즘으로 0부터 256까지 진행.
    for (int num_Block = 0 ; num_Block <= 256 ; num_Block++ ) //num_Block을 기준으로 땅의 높이가 정해짐.
    {
        int use_Block = 0; //+값일 경우 남는 블록, -값일 경우 사용할 블록.
        int this_chance_Time = 0;
        
        
        for (int length = 0; length < N; length++ )
        {
            for (int width = 0 ; width < M ; width++ )
            {
                use_Block += ( array[length][width] - num_Block );
                
                if ( array[length][width] > num_Block ) // 샇여진 블록 개수가 기준 블록보다 클 경우
                {
                    this_chance_Time += ( ( array[length][width] - num_Block ) * 2 );
                }
                else if ( array[length][width] < num_Block ) // 샇여진 블록 개수가 기준 블록보다 작은 경우
                {
                    this_chance_Time += ( ( num_Block - array[length][width] ) * 1 );
                }
                else // 샇여진 블록 개수가 기준 블록보다 같은 경우
                {
                    continue;
                }
                    
            }
                
        }
        
        
        
        if ( ( use_Block + B ) >= 0 ) //주어진 블록보다 사용될 블럭수가 적은 경우
        {
            if (min_Time >= this_chance_Time )
            {
                min_Time = this_chance_Time;
                max_Land = num_Block;
            }
            
            else
            {
                continue;
            }
            
        }
        else //주어진 블록보다 사용될 블럭수가 많은 경우 불가능한 경우.
        {
            continue;
        }
        
        
    }
    
    
    printf("%d %d", min_Time, max_Land);
    
    
    return 0;
}