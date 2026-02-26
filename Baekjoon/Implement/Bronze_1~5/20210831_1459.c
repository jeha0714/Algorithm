#include <stdio.h>

int main() {
    
    int End_Location_X, End_Location_Y;
    int block_W, block_S;
    
    scanf("%d %d %d %d", &End_Location_X, &End_Location_Y, &block_W, &block_S);
    
    
    if (block_W * 2 <= block_S) //대각선 길이가 블럭 두칸보다 긴 경우
    {
        printf("%lld", (long long)End_Location_X * block_W + (long long)End_Location_Y * block_W);
    }
    
    else // 대각선 길이가 블럭 두칸보다 짧은 경우
    {
        int big_Num = End_Location_X > End_Location_Y ? End_Location_X : End_Location_Y;
        int small_Num = End_Location_X <= End_Location_Y ? End_Location_X : End_Location_Y;
        
        if ( block_W * 2 <= block_S * 2 )
        {
            printf("%lld", (long long)small_Num * block_S + (long long)(big_Num - small_Num) * block_W );
        }
        
        else
        {
            if ( ( big_Num - small_Num ) % 2 == 0 )
            {
                printf("%lld", (long long)small_Num * block_S + (long long)(big_Num - small_Num) * block_S );
            }
            
            else
            {
                printf("%lld", ( (long long)small_Num * block_S ) + ( (long long)(big_Num - small_Num) * block_S ) - block_S + block_W);
            }
        }
        
    }
    
    
    
    
    
    return 0;
}