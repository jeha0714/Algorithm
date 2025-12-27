#include <stdio.h>
#include <math.h>


int Sieve_of_Eratosthenes(int num) {

    
    int how_many_Prime = 0, num_of_Prime = 0; //how_many_Prime는 root_Num보다 작은 소수의 개수, num_of_Prime은 num보다 작은 소수의 개수.
    double root_Num = pow(num, 0.5);
    int array_root_Prime[(int)root_Num], array_main_Prime[num + 1]; //root_num보다 작은 소수를 저장할 배열, 배수를 삭제 해줄 기록을 남겨줄 배열
    
    for (int i = 0 ; i < (int)root_Num ; i++) { //array_root_Prime전체 값 0으로 초기화
        array_root_Prime[i] = 0;
    }
    for (int i = 0 ; i < num + 1 ; i++) { // array_main_Prime전체 값 0으로 초기화
        array_main_Prime[i] = 0;
    }
    
    
    for (int i = 2 ; i <= (int)root_Num ; i++) { //root_Num까지의 소수를 찾기위한 과정.
        
        int help_Prime = 0;
        
        for (int j = 2 ; j < i ; j++) {
            
            if (i % j == 0) { // 중간에 배수라면 다음과 같은 조건이 걸림.
                
                help_Prime = 1;
                break;
            }    
            
        }
        
        if (help_Prime == 0) { //위에 j반복문을 다 돌고도 help_Prime이 0일경우 해당 수는 prime.
            array_root_Prime[how_many_Prime++] = i;    
        }
        
    }
    
    
    for (int i = 0 ; i < how_many_Prime ; i++) { //array_root_Prime에 저장된 소수를 사용하여 배수 제거.
        
        for (int j = 2 ; j * array_root_Prime[i] <= num; j++) {
            
            array_main_Prime[array_root_Prime[i] * j] = 1;
        }
        
    }
    
    
    
    for (int i = 2; i <= num ; i++) { //에라토스테네스의 체를 이용하고 걸러진 소수들의 개수를 계산.
        
        if (array_main_Prime[i] == 0) {
            num_of_Prime++;
        }
    }
    
    return num_of_Prime; //총 개수 반환.
}




int main() {
    
    while (1) { //0이라는 조건이 나올때까지 무한루프.
        
        int n, min_Result, max_Result;
        
        scanf("%d", &n);
        if (n == 0) {break;}
        
        min_Result = Sieve_of_Eratosthenes(n);
        max_Result = Sieve_of_Eratosthenes(2*n);
        
        printf("%d\n", max_Result - min_Result);
        
    }
    
    
    return 0;
}