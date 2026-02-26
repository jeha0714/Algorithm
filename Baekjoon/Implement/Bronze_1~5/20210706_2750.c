#include <stdio.h>

int main() {
    
    int N;
    scanf("%d", &N);
    
    int array[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }

    
    for (int i = 0; i < N; i++) {
        
        for (int j = i + 1; j < N ; j++) {
            
            int swap_Help;
            
            if(array[i] > array[j]) {
                
                swap_Help = array[i];
                array[i] = array[j];
                array[j] = swap_Help;
            }
        }
    }
    
    for (int i = 0; i< N; i++) {
        printf("%d\n", array[i]);
    }
    
    return 0;
}