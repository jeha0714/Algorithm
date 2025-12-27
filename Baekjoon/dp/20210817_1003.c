#include <stdio.h>
#include <stdlib.h>

//0과 1의 개수를 저장 할 구조체 선언.
typedef struct
{
    int num_Zero;
    int num_One;
    
}Zero_And_One;


void fibonacci( int N, Zero_And_One * array_Fibo );




int main() {
    
    scanf("%d", &T);
    
    Zero_And_One * array_Fibo = (Zero_And_One *)malloc(sizeof(Zero_And_One) * 41);
    for (int i = 0; i < 41; i++) 
    {
        array_Fibo[i].num_Zero = 0;
        array_Fibo[i].num_One = 0;
    }
    
    
    for (int run_Time = 0 ; run_Time < T ; run_Time++) //테스트 케이스 횟수만큼 실행.
    {
        int N; 
        scanf("%d", &N);
        
        fibonacci(N, array_Fibo);
        
        printf("%d %d\n", array_Fibo[N].num_Zero, array_Fibo[N].num_One);
    }
    
    
    
    return 0;
}


void fibonacci( int N, Zero_And_One * array_Fibo )
{
    if (N == 0) 
    {
        array_Fibo[0].num_Zero = 1;
    }
    else if (N == 1) 
    {
        array_Fibo[1].num_One = 1;
    }
    else 
    {
        if ( (array_Fibo[N - 1].num_One == 0 && array_Fibo[N - 1].num_Zero == 0) ) 
        {
            fibonacci(N - 1, array_Fibo);
        }
        
        if ( (array_Fibo[N - 2].num_One == 0 && array_Fibo[N - 2].num_Zero == 0) )
        {
            fibonacci(N - 2, array_Fibo);
        }
        
        //동적 배열 내부에 값을 저장.
        array_Fibo[N].num_Zero = array_Fibo[N - 1].num_Zero + array_Fibo[N - 2].num_Zero;
        array_Fibo[N].num_One = array_Fibo[N - 1].num_One + array_Fibo[N - 2].num_One;
    }
    
}