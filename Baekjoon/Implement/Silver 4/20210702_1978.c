#include <stdio.h>

int main() {
    
    int N, result = 0;
    scanf("%d", &N);
    int array_Num[N]; //N개 만큼 주어지는 수를 배열에 저장.
    
    for(int i = 0; i < N ; i++) { //N개 수 삽입.
        scanf("%d", &array_Num[i]);
    }
    
    for(int i = 0; i < N; i++) {
        int help_Code = 0; //이 변수를 통해 소수일 경우 개수에 포함시킴.
        
        if (array_Num[i] == 1) { //1은 소수가 아님!
            continue;
        }
        
        for (int j = 2; j < array_Num[i] ; j++) {
            if (array_Num[i] % j == 0) {
                help_Code = 1;
                break;
            }
        }
        
        if (help_Code == 0) {
            result++;
        }
        
    }
    
    printf("%d", result);
    
    return 0;
}