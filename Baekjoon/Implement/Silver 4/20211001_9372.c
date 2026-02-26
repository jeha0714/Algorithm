#include <stdio.h>

int main() {
    
    int test_Case; // 테스트 케이스의 수
    scanf("%d", &test_Case);
    
    for (int now_Try = 0; now_Try < test_Case ; now_Try++ )
    {
        int num_Nation, num_Airplane; // 국가의 수와 비행기의 종류 수
        scanf("%d %d", &num_Nation, &num_Airplane);
        
        int array_Location[num_Airplane][2];
        for(int now_row = 0; now_row < num_Airplane ; now_row++)
            scanf("%d %d", &array_Location[ now_row ][0], &array_Location[ now_row ][1]);
        
        printf("%d\n", num_Nation - 1);
    }
    
    
    
    
    
    
    
    return 0;
}