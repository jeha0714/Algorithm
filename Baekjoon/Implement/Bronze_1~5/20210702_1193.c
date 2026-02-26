#include <stdio.h>

int main() {
    int X,sum_I =0; // sub_I로 반복문 i와 범위를 정해서 i값을 이용해서 분모 분자 합을 알 수 있는 점을 이용.
    scanf("%d", &X);
    
    for (int i = 1 ; ; i++) {
        
        sum_I += i;
        
        if (X == 1) {
            printf("1/1");
            break;
        }
        
        else if (X > (sum_I - i) && X <= sum_I && (i % 2 == 0)) { // 짝수인 경우
            printf("%d/%d", i + X - sum_I  , sum_I - X + 1 );
            break;
        }
        
        else if (X > (sum_I - i) && X <= sum_I && (i % 2 != 0)) { // 홀수인 경우
            printf("%d/%d", sum_I - X + 1, i + X - sum_I   );
            break;
        }
    }
    
    
    return 0;
}