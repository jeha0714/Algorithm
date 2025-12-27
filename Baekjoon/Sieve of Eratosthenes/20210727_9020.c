#include <stdio.h>
#include <math.h>


void Sieve_of_Eratosthenes(int n, int array_Prime_Num[]) {
    
    double root_Num = pow(n, 0.5);
    int how_many_Prime = 0; //how_many_Prime는 root_Num보다 작은 소수의 개수.
    int array_root_Prime[(int)root_Num]; //root_num보다 작은 소수를 저장할 배열
    
    for (int i = 0 ; i < (int)root_Num ; i++) { //array_root_Prime전체 값 0으로 초기화
        array_root_Prime[i] = 0;
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
        
        for (int j = 2 ; j * array_root_Prime[i] <= n; j++) {
            
            array_Prime_Num[array_root_Prime[i] * j] = 1;
        }
        
    }
    
    
    
}



int main() {
    int T;
    scanf("%d", &T);
    
    for (int i = 0 ; i < T ; i++) {//T번의 테스트 실행.
        
        int n;
        scanf("%d", &n);
        int min_num = 0, max_num = n; //이후에 소수들 중 차를 최소화 하기 위해 이용되는 변수.
        int array_Prime_Num[n + 1];
        
        for (int i = 0 ; i < n + 1 ; i++) { // array_main_Prime전체 값 0으로 초기화
            array_Prime_Num[i] = 0;
        }
        
        
        Sieve_of_Eratosthenes(n, array_Prime_Num); //에라토스테네스의 체를 걸쳐 소수만 판별.
        
        
        for (int i = 2 ; i <= (n / 2) ; i++) { //소수 2부터 시작하여 n/2까지 반복하며 차가 최소인 값을 도출.
            
            if (array_Prime_Num[i] == 0 && array_Prime_Num[n - i] == 0) { //i와 n-i의 합이 n이면서 소수인 조건.
                
                if (max_num - min_num > array_Prime_Num[n - i] - array_Prime_Num[i]) { //차가 기존 설정 값보다 최소인 경우 새로 지정.
                    
                    min_num = i; 
                    max_num = n - i;
                }
                
            } 
                
        }
        
        printf("%d %d\n", min_num, max_num);
        
    }
     
    
    return 0;
}