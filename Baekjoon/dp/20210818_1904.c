#include <stdio.h>
#include <stdlib.h>

void Tile(int N, int *array_Tile);



int main() {
    
    int N = 0; // 2진수 길이가 N
    int* array_Tile = (int* )malloc(sizeof(int)*1000001);
    
    for (int now_index = 0; now_index < 1000001; now_index++) { //배열 내 모든 값을 0으로 초기화.
        array_Tile[now_index] = 0;
    }
    
    scanf("%d", &N); //N값 입력받기.
    
    Tile(N, array_Tile);

    printf("%d", array_Tile[N] % 15746);
    
    
    
    return 0;
}



void Tile(int N, int* array_Tile)
{
    if (N == 1)
    {
        array_Tile[1] = 1;
    }
    else if (N == 2)
    {
        array_Tile[2] = 2;
    }
    else 
    {
        if ( array_Tile[N - 1] == 0 ) 
        {
            Tile(N - 1, array_Tile);
        }
        
        if ( array_Tile[N - 2] == 0 )
        {
            Tile(N - 2, array_Tile);
        }
        
        if (array_Tile[N - 1] > 15746 || array_Tile[N - 2] > 15746) 
        {
            array_Tile[N - 1] = array_Tile[N - 1] % 15746;
            array_Tile[N - 2] = array_Tile[N - 2] % 15746;
        }
        array_Tile[N] = array_Tile[N - 1] + array_Tile[N - 2];
    }
    
}