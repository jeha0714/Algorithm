#include <stdio.h>

int people_Living(int k,int n) { //k층 n호 몇 명인지 바로 알아내는 함수. <재귀 함수로 사용!!!!!>
    if (k == 0) {
        return n;
    }
    else if (k == 1) {
        int result = 0;
        for (int i = 1; i <= n ; i++) {
            result += i;
        }
        return result;
    }
    
    else {
        int result = 0;
        for (int i = 1; i <= n ; i++) {
            result += people_Living(k-1,i);
        }
        return result;
        
    }
}

int main() {
    
    int T; //테스터 데이터의 개수.
    
    //조건 : 단, 아파트에는 0층부터 있고 각층에는 1호부터 있으며, 0층의 i호에는 i명이 산다.
    
    scanf("%d", &T);
    
    for (int i = 0 ; i < T ; i++) { //해당 테스트 횟수 반복문.
        int how_Many_Pp = 0; //총 인원수를 의미.
        int k,n; //k는 층수 n은 해당 층수의 호수를 의미.
        scanf("%d %d", &k, &n);
        
        printf("%d \n", people_Living(k,n));
    }
    
    
    
    
    return 0;
}