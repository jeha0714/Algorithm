#include <stdio.h>

int main() {
    
    int N, K, coin_All = 0; //coin_All은 동전 개수를 세어주는 변수.
    scanf("%d %d", &N, &K);
    int array_Coin[N];
    
    for(int i = 0; i < N ; i++) {
        scanf("%d", &array_Coin[i]);
    }
    
    for (int i = N - 1; i >= 0 ; i--) {
        
        if (K / array_Coin[i] != 0) {
            
            coin_All += K/array_Coin[i];
            K = K % array_Coin[i];
        }
    }
    
    printf("%d", coin_All);
   
    
    return 0;
}