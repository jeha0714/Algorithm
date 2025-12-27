#include <stdio.h>

// 각 행은 index+1로 끝나는 경우의 수가 주어짐.
// 각 열은 index+1의 수가 주어질 때를 의미함.
int End_num[100000][3] ={0,};

int main() {
    
    // 진행 할 촐 테스트 케이스의 개수가 주어짐
    int test_Case; scanf("%d", &test_Case );
    
    // End_num배열의 index 0~2까지의 열의 기본 값이 주어짐.
    End_num[0][0] = 1, End_num[0][1] = 0, End_num[0][2] = 0;
    End_num[1][0] = 0, End_num[1][1] = 1, End_num[1][2] = 0;
    End_num[2][0] = 1, End_num[2][1] = 1, End_num[2][2] = 1;
    
    
    while( test_Case-- > 0 )
    {
        // 테스트를 진행해볼 정수가 주어짐.
        int test_Num; scanf("%d", &test_Num );
        
        for ( int i = 3 ; i < test_Num ; i++ )
        {
            // 해당 열 세 개의 행에 0이 아닌 값이 하나라도 존재한다면 jump -> 계산된 경우는 건너뛰기 위함.
            if ( End_num[i][0] != 0 && End_num[i][1] != 0 && End_num[i][2] != 0 )
                continue;
            
            // 끝자리수가 1,2,3으로 끝난경우에 따라 적절하게 -1 -2 -3 한 열의 값을 불러와서 더해준다.
            // 이때 같은 수를 연속으로 사용하지 않도록 해준다.
            End_num[ i ][0] = ( End_num[ i - 1 ][1] + End_num[ i - 1 ][2] ) % 1000000009;
            End_num[ i ][1] = ( End_num[ i - 2 ][0] + End_num[ i - 2 ][2] ) % 1000000009;
            End_num[ i ][2] = ( End_num[ i - 3 ][0] + End_num[ i - 3 ][1] ) % 1000000009;
        }
        
        // 결과값을 문제로 주어진 형태에 맞게 출력함.
        long long result = ( (long long)End_num[ test_Num - 1 ][0] + (long long)End_num[ test_Num - 1 ][1] 
                            +  (long long)End_num[ test_Num - 1 ][2] ) % 1000000009;
        printf("%lld\n", result );
    }
    
    
    
    
    return 0;
}