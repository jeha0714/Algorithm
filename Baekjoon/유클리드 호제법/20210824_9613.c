#include <stdio.h>


int Find_GCD(int num1, int num2)
{
    if ( num1 == 0 && num2 == 0 )
    {
        return 0;
    }
    else if ( (num1 == 0 && num2 != 0) || (num1 != 0 && num2 == 0) )
    {
        int not_Zero = num1 != 0 ? num1 : num2;
        return not_Zero;
    }
    
    else if ( num1 >= num2 )
    {
        if ( num1 % num2 == 0) {return num2;}
        else 
        {
            int namoji;
            namoji = num1 % num2;
            return Find_GCD(num2, namoji);
        }
        
    }
    
    else if ( num1 < num2 )
    {
        if ( num2 % num1 == 0) {return num1;}
        else 
        {
            int namoji;
            namoji = num2 % num1;
            return Find_GCD(num1, namoji);
        }
        
    }
    
    return 0;
}




int main() {
    
    int test_Case; //테스트 횟수.
    
    scanf("%d", &test_Case);
    
    for (int try_Num = 0 ; try_Num < test_Case ; try_Num++ )
    {
        long long result_All = 0; // 각 테스트 당 가능한 모든 쌍의 GCD의 합을 저장할 변수.
        int integer_Num; //각 테스트의 주어지는 수의 개수.
        scanf("%d", &integer_Num);
        
        int array_Num[integer_Num]; //주어진 수를 저장하는 배열.
        for (int now_Index = 0 ; now_Index < integer_Num ; now_Index++ ){scanf("%d", &array_Num[now_Index]); }
        
        
        for (int main_Index = 0 ; main_Index < integer_Num ; main_Index++ )
        {
            for (int sub_Index = main_Index + 1 ; sub_Index < integer_Num ; sub_Index++ )
            {
                result_All += Find_GCD(array_Num[main_Index], array_Num[sub_Index] );
            }
            
        }
        
        printf("%lld\n", result_All);
    }
    
    
    
    
    return 0;
}