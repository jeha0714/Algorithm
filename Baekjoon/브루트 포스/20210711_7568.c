#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int weight[N], height[N]; //키랑 몸무게 저장 배열.
    int win_Num[N], Rank[N]; //비교했을 때 몇 명보다 덩치가 큰지 저장할 배열과, 순위를 정할 배열.
    
    for(int i = 0 ; i < N ; i++) {
        scanf("%d %d", &weight[i], &height[i]);
    }
    
    for(int i = 0 ; i < N ; i++) {
        int how_Many_Win = 0; //덩치가 얼마나 큰지 한명 한명 저장할 변수.
        
        for (int j = 0 ; j < N; j++) {
            
            if (weight[i] >= weight[j] || height[i] >= height[j]) { //덩치가 클 시 .
                //비기는 경우도 증가시키기 위해 위와 같은 조건을 걸음.
                how_Many_Win++;
            }
        }
        win_Num[i] = how_Many_Win; //i번째 사람이 덩치로 이긴 횟수를 i번째 배열에 저장.
        
    }
    
    
    for(int i = 0; i < N ; i++) { //
        
        Rank[i] = N - (win_Num[i] - 1); //win_Num[i]에서 1을 뺀 이유는 자기자신도 포함해서 증가시켰기 때문.
        //간단한 예제를 통해 확인하면 왜 위와 같은 값이 나오는지 결론이 나옴.
    }
    
    
    for(int i = 0; i < N ; i++) { //순위 출력.
        printf("%d ", Rank[i]);
    }
    
    return 0;
}