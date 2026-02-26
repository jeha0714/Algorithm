#include <stdio.h>


int main() {
    
    int N, result = 0;
    scanf("%d", &N);
    int array_Check[100]; //컴퓨터는 항상 100대 있음.
    
    for(int i = 0; i< 100; i++) {
        array_Check[i] = 0;
    }
    
    for(int i = 0 ; i < N; i++) {
        int num;
        scanf("%d", &num);
        
        if(array_Check[num-1] == 0) {
            array_Check[num-1] = 1;
        }
        else {
            result++;
        }
    }
    
    printf("%d", result);
    
    return 0;
}