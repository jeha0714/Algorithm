#include <stdio.h>

int main() {
    
    int M,N, sum_All = 0, min_Num; //sum_All은 총합 변수, min_Num은 최솟값 찾기 위한 변수.
    scanf("%d %d", &M, &N);
    
    for(int i = M ; i <= N ; i++) {
        int help_Code = 0; // 소수임을 증명하기 위해 도와주는 변수.
        
        if ( i == 1 ){ //1은 소수가 아님!
            continue;
        }
        
        for (int j = 2 ; j < i ; j++) {
            
            if ( i % j == 0) {
                help_Code  = 1;
                break;
            }
        }
        
        if (help_Code == 0 && sum_All == 0) { //맨 처음 발견한 소수만 출력할 방법을 찾음. 이후 두번째 소수 부터는 반영 안됨.
            min_Num = i;
        }
        
        if (help_Code == 0) {
            sum_All += i;
        }
    }
    
    if (sum_All == 0) {
        printf("-1");
    }
    else {
        printf("%d\n%d", sum_All, min_Num);
    }
    
    return 0;
}