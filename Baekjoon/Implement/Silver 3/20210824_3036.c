#include <stdio.h>


//최대공약수를 찾아서 반환하는 함수.
int Find_GCD (int main_Length, int compare_Lenth)
{
    //둘 중 작은 수를 변수에 저장.
    int GCD = 0;
    int small_Num = main_Length > compare_Lenth ? compare_Lenth : main_Length;
    
    for (int current_Num = small_Num; current_Num >= 1; current_Num--)
    {//둘 중 작은수부터 -1씩 하면서 최대공약수 찾기.
        if (main_Length % current_Num == 0 && compare_Lenth % current_Num == 0) {GCD = current_Num; break;}
    }
    
    return GCD;
}



int main() {
    
    int N; //링의 개수 N이 주어짐.
    
    scanf("%d", &N);
    
    int ring_Length[N]; //N개의 링의 반지름이 저장 될 배열.
    for (int now_Index = 0 ; now_Index < N; now_Index++) //ring의 반지름을 순서대로 받기.
    {
        scanf("%d", &ring_Length[now_Index]);
    }
    
    
    for (int now_Index= 1; now_Index < N; now_Index++ )
    {
        //1. 첫 번째 링과 비교할 링의 최대공약수를 찾아야함.
        int GCD = 0;
        GCD = Find_GCD(ring_Length[0], ring_Length[now_Index] );
        
        //2. 최대공약수를 기준으로 ( 기준 링 반지름 / 최대공약수 ) / ( 비교 할 링 반지름 / 최대공약수 )를 출력.
        printf("%d/%d\n", ring_Length[0]/GCD, ring_Length[now_Index] /GCD);
        
    }
    
    
    return 0;
}