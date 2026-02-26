#include <stdio.h>

int main() {
    
    int A,B, main_Sum = 0, sub_Sum = 0;
    int code = 1;
    scanf("%d %d", &A, &B);
    
    for (int i = 1 ; i < A ;) { //A번째 전까지 합을 구하는 반복문.
        
        for (int j = 1; j <=code ; j++) {
            
            if (i < A) {
                sub_Sum += code;
                i++;
            }
                break;
            }
        }
        
        code++;
    }
    
    code = 1; //1부터 더해야하므로 초기화.
    
    for (int i = 0 ; i < B ;) { //B번째까지 합을 구하는 반복문.
        
        for (int j = 1; j <=code ; j++) {
            
            if (i < B) {
                main_Sum += code;
                i++;
            }
            else {
                break;
            }
        }
        
        code++;
    }
    
    printf("%d", main_Sum - sub_Sum);
    
    return 0;
}