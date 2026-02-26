#include <stdio.h>
#include <string.h>


int main() {
    int M; //수행해야 하는 연산의 수 M
    char array[10]; //연산함수를 입력받을 배열.
    int array_S[21]; //num값이 들어갈 배열. num값이 1~20이므로 [num]이 1인경우 집합에 속한것이며 [num]의 값이 0이면 집합에 속하지 않은 것.
    
    scanf("%d", &M);
    
    for (int i = 1 ; i <= 20 ; i++) { //모든 배열내 값을 0으로 초기화.
        array_S[i] = 0;
    }
    
    
    for (int i = 0 ; i < M ; i++) {
        
        int num;
        scanf("%s %d", array, &num);
        
        
        if (strcmp(array, "add") == 0) { //S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
            
            if (array_S[num] == 0) {
                
                array_S[num] = 1;
            }
            else {
                
                continue;
            }
            
        }
        else if (strcmp(array, "remove") == 0) { //S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
            
            if (array_S[num] == 1) {
                
                array_S[num] = 0;
            }
            else {
                
                continue;
            }
            
        }
        else if (strcmp(array, "check") == 0) { //S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
            
            if (array_S[num] == 1) {
                printf("1\n");
            }
            else {
                printf("0\n");
            }
            
        }
        else if (strcmp(array, "toggle") == 0) { //S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
            
            if (array_S[num] == 1) {
                
                array_S[num] = 0;
            }
            else {
                
                array_S[num] = 1;
            }
            
        }
        else if (strcmp(array, "all") == 0) { //{1, 2, ..., 20} 으로 바꾼다.
            
            for (int i = 1 ; i <= 20 ; i++) { //집합에 1~20을 대입하므로 [1] ~[20]을 1로 초기화.
                array_S[i] = 1;
            }
            
        }
        else if (strcmp(array, "empty") == 0) { //S를 공집합으로 바꾼다.
            
            for (int i = 1 ; i <= 20 ; i++) { //모든 배열내 값을 0으로 초기화.
                array_S[i] = 0;
            } 
            
        }
        
        
        
    }
    
    
    
    return 0;
}