#include <stdio.h>

int main() {
    
    int N, M;
    int result; //세장의 합을 저장할 변수.
    scanf("%d %d", &N, &M);
    int array_Card[N];
    
    for(int i = 0 ; i < N ; i++) {
        scanf("%d", &array_Card[i]);
    }
    result = array_Card[0] + array_Card[1] + array_Card[2]; //result의 값을 초기화.
    
    for(int i = 0; i < N; i++) { //모든 경우의 수를 계산하기 위해 3장 선택하는 것을 반복문으로 구현.
        
        for (int k = i + 1 ; k < N; k++) {
            
            for (int j = k + 1 ; j < N ; j++) {
                
                int code1, code2;
                code1 = M - result  >= 0? M - result : result - M ; //code1은 기존 result와 M의 차를 저장.
                code2 = M - (array_Card[i] + array_Card[k] + array_Card[j]); //code2는 i,j,k의 합을 M과 뺄셈한 결과를 저장.
                
                if(code2 < 0) { //M을 넘지 않는 수여야 하므로 i,j,k로 새롭게 만들어진 합이 M을 넘는경우를 여기서 막음.
                    continue;
                }
                
                if(code1 >= code2) { //다음과 같이 조건을 걸어서 result를 구함. 
                                    //초기 설정 result가 M보다 크다 할지언정 답이 존재하는 문제이므로 만족하는 i,j,k로 구성된 code2값이 무조건 나옴.
                    result = array_Card[i] + array_Card[k] + array_Card[j];
                }
                  
            }
        }
    }
    
    printf("%d", result);
    
    return 0;
}