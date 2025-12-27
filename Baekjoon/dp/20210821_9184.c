#include <stdio.h>
#include <stdlib.h>

// -50 ~ -1의 값은 [0 ~ 49] 0 ~ 50의 값은 [50 ~ 100]

void w (int ***array_W, int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        array_W[a + 50][b + 50][c + 50] = 1;
    }
    
    else if (a > 20 || b > 20 || c > 20)
    {
        if (array_W[70][70][70] == -51) // a=20 b=20 c=20일 경우의 값이 존재하지 않을 경우.
        {
            w(array_W, 20, 20, 20);
        }
        
        array_W[a + 50][b + 50][c + 50] = array_W[70][70][70];
    }
    
    else if (a < b && b < c)
    {
        if ( array_W[a + 50][b + 50][c - 1 + 50] == -51 ) { w(array_W, a, b, c - 1); }
        
        if ( array_W[a + 50][b - 1 + 50][c - 1 + 50] == -51 ) { w(array_W, a, b - 1, c - 1); }
        
        if ( array_W[a + 50][b - 1 + 50][c + 50] == -51 ) { w(array_W, a, b - 1, c); }
        
        array_W[a + 50][b + 50][c + 50] = array_W[a + 50][b + 50][c - 1 + 50] + array_W[a + 50][b - 1 + 50][c - 1 + 50] - array_W[a + 50][b - 1 + 50][c + 50];
    }
    
    else
    {
        if ( array_W[a - 1 + 50][b + 50][c + 50] == -51 ) { w(array_W, a - 1, b, c); }
        
        if ( array_W[a - 1 + 50][b - 1 + 50][c + 50] == -51 ) { w(array_W, a - 1, b - 1, c); }
        
        if ( array_W[a - 1 + 50][b + 50][c - 1 + 50] == -51 ) { w(array_W, a - 1, b, c - 1); }
        
        if ( array_W[a - 1 + 50][b - 1 + 50][c - 1 + 50] == -51 ) { w(array_W, a - 1, b - 1, c - 1); }
        
        array_W[a + 50][b + 50][c + 50] = array_W[a - 1 + 50][b + 50][c + 50] + array_W[a - 1 + 50][b - 1 + 50][c + 50] + array_W[a - 1 + 50][b + 50][c - 1 + 50] - array_W[a - 1 + 50][b - 1 + 50][c - 1 + 50];
    }
    
}




int main() {
    
    //int array_W[101][101][101]을 동적할당.
    int ***array_W = (int ***)malloc(sizeof(array_W) * 101); //x축 동적할당.
    for (int now_Index = 0; now_Index < 101; now_Index++) //y축 동적할당.
    {
        array_W[now_Index] = (int **)malloc(sizeof(int *) * 101);
    }
    
    for (int now_Index_X = 0 ;now_Index_X < 101; now_Index_X++) //z축 동적할당.
    {
        for(int now_Index_Y = 0 ; now_Index_Y < 101 ; now_Index_Y++)
        {
            array_W[now_Index_X][now_Index_Y]= (int*)malloc(sizeof(int) * 101);
        }
    }
    
    
    //다음으로 배열 내부의 모든 값을 -51로 초기화.
    for (int i = 0; i < 101 ; i++)
    {
        for (int j = 0; j < 101 ; j++)
        {
            for (int k = 0; k < 101 ; k++)
            {
                array_W[i][j][k] = -51;
            }
        }
    }
    
    
    //세 정수값 입력받기 시작. 무한반복문
    while (1)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        
        if (a == -1 && b == -1 && c == -1) {break;} //입력값이 모두 -1일 경우 break;
        
        w(array_W, a, b, c);
        
        printf("w(%d, %d, %d) = %d\n", a, b, c, array_W[a + 50][b + 50][c + 50]);
        
        
    }
    
    
    free(array_W);
   
    return 0;
}