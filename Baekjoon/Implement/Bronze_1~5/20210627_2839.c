#include <stdio.h>

int main() {
    
    int N; //설탕무게
    int large_Max; //5키로가 최대 몇개 넣을 수야 있는지
    int checkcode = 1; //5와 3으로 구성이 안되는 경우를 체크하기위한 변수값.
    
    scanf("%d", &N);
    large_Max = N / 5;
    
    
    for(int i = large_Max; i>=0 ; i--) {
        if (((N - 5 * i) % 3) !=0) {
            continue;
        }
        else {
            checkcode = 0;
            printf("%d \n", i+((N - 5*i)/3));
            break;
        }
    }
    
    if(checkcode == 1) {
        printf("-1");
    }
    
    return 0;
}