#include <stdio.h>

int main() {
    char num_A[10010], num_B[10010]; //2개의 큰 수를 받을 배열.
    int num_Result[10010]; // A + B 결과값을 저장 할 배열.
    int length_A, length_B; //숫자 A 와 B 길이 변수.
    int change_A, change_B;
    int next_Up = 0; // 배열 연산 중 자리 수 합이 10이상일 경우 다음자리수에 +1을 해주기 위해 만든 변수.
    scanf("%s %s", num_A, num_B);
    
    for(int i = 0; ; i++) {
        if (num_A[i] == '\0') {
            length_A = i;
            break;
        }
    }
    for(int i = 0; ; i++) {
        if (num_B[i] == '\0') {
            length_B = i;
            break;
        }
    }
    //길이는 \0전까지 숫자열까지만 해당되도록 설정.
    
    
    change_A = length_A; 
    change_B = length_B;
    //두 변수의 사용처는 배열 연산을 하면서 값을 -1씩 진행시킬것임.
    
    
    
    //알고리즘 시작
    //[0]번째 배열은 비워둔 상태로 일단 길이가 가장 큰 배열을 기준으로 대입 연산을 시작한다.
    
    for (int i = length_A < length_B ? length_B + 1 : length_A + 1 ; i >= 0 ;i--) {
        
        
        if ((num_A[change_A] % 48) + (num_B[change_B] % 48) >= 10) { //자리수의 합이 10이상인 경우
            
            num_Result[i] = ((num_A[change_A] % 48) + (num_B[change_B] % 48)) % 10 + next_Up;
            next_Up = 1;
            change_A--; change_B--;
        }
        else if (((num_A[change_A] % 48) + (num_B[change_B] % 48)) == 9 && next_Up == 1) { //자리수의 합이 9면서 올림수의 값이 1인 경우.
            num_Result[i] = 0;
            next_Up = 1;
            change_A--; change_B--;
        }
        else { // 자리수와 올림 수 합이 9이하인 경우.
            num_Result[i] = (num_A[change_A] % 48) + (num_B[change_B] % 48) + next_Up;
            next_Up = 0;
            change_A--; change_B--;
        }
        
        if (change_A < 0 || change_B < 0) {break;}
        
    }
    
    //길이가 짧은 배열을 기준으로 위 연산을 진행함.
    //밑으로는 길이가 긴 배열의 나머지 자리수들의 합을 진행시킬것임.
    
    if (length_A > length_B) {
        
        for (int i = length_A - length_B ; i >= 0; i--) {
            
            if (num_A[i - 1] % 48 == 9 && next_Up == 1) {
                num_Result[i] = 0;
                next_Up = 1;
            }
            else {
                num_Result[i] = next_Up + (num_A[i-1] % 48);
                next_Up = 0;
            }
        }
    }
    else if (length_A < length_B) {
        
        for (int i = length_B - length_A ; i >= 0; i--) {
            
            if (num_B[i - 1] % 48 == 9 && next_Up == 1) {
                num_Result[i] = 0;
                next_Up = 1;
            }
            else {
                num_Result[i] = next_Up + (num_B[i-1] % 48);
                next_Up = 0;
            }
        }
    }
    else { //두 숫자의 길이가 같은 경우.
        
        if (next_Up == 1) {
            num_Result[0] = 1;
        }
        else {
            num_Result[0] = 0;
        }
        
    }
    

    if (num_Result[0] == 0) { //맨 앞 문자열이 0일경우와 아닐경우(1인경우) 를 구분해서 정답을 출력.
        for ( int i = 1; i <= (length_A < length_B ? length_B  : length_A ) ; i++) {
            printf("%d", num_Result[i]);
        }
    }
    else {
        for ( int i = 0 ; i <= (length_A < length_B ? length_B : length_A) ; i++) {
            printf("%d", num_Result[i]);
        }
    }
    

    return 0;
}