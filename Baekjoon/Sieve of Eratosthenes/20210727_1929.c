#include <stdio.h>
#include <math.h>

void Sieve_Of_Eratosthenes(int num, int array_Num[]) {
    
    double root_N = pow(num, 0.5);
    int array_Prime[num]; //root_N보다보다 작은 소수들을 저장할 배열.
    int how_Many_Prime_There = -1; //root_N보다 작은 소수들의 개수를 저장하는 변수.
    
    for (int i = 0 ; i < num ; i++) { //array_Prime 모든 값을 0으로 초기화.
        array_Prime[i] = 0;
    }
    
    
    for(int i = 2; i <= (int)root_N ; i++) { //root_N보다 같거나 작은 소수들을 구하기.
        
        int this_IS_Prime = 0;
        
        for (int j = 2 ; j < i ; j++) { 
            
            if (i % j == 0) {
                
                this_IS_Prime = 1;
                break;
            }
            
        }
        
        if (this_IS_Prime == 0) {
            array_Prime[++how_Many_Prime_There] = i;
        }
        
    }
    


    for (int i = 0; i <= how_Many_Prime_There ; i++) { //root_N보다 작은 소수들을 활용하여 배수 제거.
        
        for (int j = 2 ; array_Prime[i] * j <= num ; j++ ) {
            
            *(array_Num + (array_Prime[i] * j)) = 1; 
        }
        
    }
    
    
    
}



int main() {
    
    int M,N;
    scanf("%d %d", &M, &N);
    int array_Num[N+1];
    
    for (int i = 0 ; i < N + 1 ; i++) { //array_Num 모든 값을 0으로 초기화.
        array_Num[i] = 0;
    }
    
    
    Sieve_Of_Eratosthenes(N, array_Num);
    
    for(int i = M; i <= N ; i++) {
        
        if (i == 1) {
            continue;
        }
        
        if (array_Num[i] == 0) {
            printf("%d\n", i);
        }
        
    }
    
    
    return 0;
}