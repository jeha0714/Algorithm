#include <stdio.h>


int check_Two(int num) {//소인수분해하면서 2의 개수를 찾고 반환.
    
    int now_Num = num;
    int how_Many = 0;
    
    for ( ; ;how_Many++) {
        
        if (now_Num % 2 == 0) {
            
            now_Num /= 2;
        }
        else {break;}
        
    }
    
    
    return how_Many;
}

int check_Five(int num) { //소인수분해하면서 5의 개수를 찾고 반환.
    
    int now_Num = num;
    int how_Many = 0;
    
    for ( ; ;how_Many++) {
        
        if (now_Num % 5 == 0) {
            
            now_Num /= 5;
        }
        else {break;}
        
    }
    
    
    return how_Many;
}



int main() {
    
    int N; // N까지 팩토리얼 계산.
    int array_Two_Five[2] ={0,0}; //index 0,1에는 각각 N까지 수가 나열되면서 소인수 분해 했을 경우 2와 5의 개수가 저장.
    
    scanf("%d", &N);
    
    for (int i = 1; i <= N ;i++) { //소인수분해를 진행하면서 2와 5의 개수를 저장.
            
        array_Two_Five[0] += check_Two(i);
        array_Two_Five[1] += check_Five(i);
    }
    
    //index중 적은 값을 출력.
    if (array_Two_Five[0] >= array_Two_Five[1]) {printf("%d", array_Two_Five[1]);} 
    else {printf("%d", array_Two_Five[0]);}


    return 0;
}