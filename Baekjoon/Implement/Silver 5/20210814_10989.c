#include <stdio.h>

int main() {
    
    int N; //N개의 수가 주어짐.
    int now_Location = 1; //현재 위치 및 현재 숫자를 의미. 
    int now_Location_Output = 0, num_Output = 0;
    short array_N[10001]; // 10000보다 같거나 작은 수들을 count하기 위해 10000까지 인덱스가 있는 배열 생성.
    // array_N[i]는 숫자 i의 등장 횟수를 의미.
    
    
    scanf("%d", &N); //N개의 수 대입
    
    for (int i = 1; i <= 10000 ; i++) {array_N[i] = 0; } //배열 내부의 값을 0으로 초기화.
    
    for (int i = 0 ; i < N ; i++) {
        
        int say_Num;
        scanf("%d", &say_Num); //차례대로 수를 입력받고
        
        array_N[say_Num]++; //입력받은 수의 count를 +1 해줌.
    }
    
    
    //for문 하나로 시간복잡도 O(n)이 나옴.
    
    for (; num_Output < N ;) { //총 출력 횟수가 N이랑 같을 때 까지만 진행.
        
        if (array_N[now_Location] == now_Location_Output) { //배열에 저장되어있던 등장횟수와 출력 횟수가 동일할 경우.
            
            now_Location_Output = 0; //다음 숫자를 위해 출현 횟수 0으로 초기화.
            now_Location++; // 다음 숫자로 이동.
            continue; //아래 코드를 넘기기 위해 continue 사용.
        }
        
        printf("%d\n", now_Location); //now_Location의 수를 출력.
        now_Location_Output++; //해당 숫자 출현 횟수를 +1
        num_Output++; //총 출력 횟수 +1

        
    }
    
    
    
    
    return 0;
}