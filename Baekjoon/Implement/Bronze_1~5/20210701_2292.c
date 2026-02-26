#include <stdio.h>

int sum6_All (int i) { // 벌집이 6의배수 형태로 둘러쌓이니 변수 i를 통해 몇 번 까지 둘러쌓이는지 알아내는 함수.
    
    if (i <= 0) {
        return 1;
    }
    else {
        return 6 * i + sum6_All(i - 1);
    }
}

int main() {
    
    int N;
    scanf("%d", &N);
    //벌집 개수가 1 6 12 18 24... 개로 주위로 늘어난다.
    //알고리즘을 반복문으로 i를 둔 후 i를 사용해서 범위내에 N이 존재한다면 i를 도출하는 형태로 가자.
    
    for(int i = 1; ; i++ ) {
        
        if(i == 1 && N == 1){
            printf("1");
            break;
        }
        else if(N <= sum6_All(i-1)  && N > sum6_All(i - 2) ) {
            
            printf("%d", i);
            break;
        }
    }
    
    
    return 0;
}