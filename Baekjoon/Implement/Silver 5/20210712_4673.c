#include <stdio.h>

int d (int X) { //문제를 만족하는 함수 d 구현.
    
    int length;
    
    if (X / 10000 == 1) {
        length = 5;
    }
    else if (X / 1000 >= 1 && X / 1000 < 10){
        length = 4;
    }
    else if (X % 1000 / 100 >= 1 && X % 1000 / 100 < 10){
        length = 3;
    }
    else if (X % 100 / 10 >= 1 && X % 100 / 10 < 10){
        length = 2;
    }
    else {
        length = 1;
    }
    
    if (length == 5) {
        return (X + (X / 10000 + X % 10000 / 1000 + X % 1000 / 100 + X % 100 / 10 + X % 10));
    }
    else if (length == 4) {
        return (X + (X / 1000 + X % 1000 / 100 + X % 100 / 10 + X % 10));
    }
    else if (length == 3) {
        return (X + (X / 100 + X % 100 / 10 + X % 10));
    }
    else if (length == 2) {
        return (X + (X / 10 + X % 10));
    }
    else {
        return X + X;
    }
    
}



int main() {
    
    int array_Num[10010]; //숫자 1부터 10000까지 저장해줄 배열.
    int True_Or_False[10010]; // 위 배열의 i번재 숫자가 셀프 넘버인지 알려주는 배열,
    
    for(int i = 1 ; i <= 10000 ; i++) {
        array_Num[i-1] = i;
        True_Or_False[i-1] = 0; //숫자 i가 배열 위치에서 == 0 일경우 셀프넘버
    }
    
    
    for(int i = 1; i <= 10000; i++) {
        int code = d(i); //code는 생성자가 있다!
        
        if(code > 10000) {
            continue;
        }
        
        True_Or_False[code - 1] = 1; //생성자가 있는 수는 다음 배열 값에서 1로 표시.
    }
    
    
    for(int i = 0; i < 10000 ; i++) {
        
        if (True_Or_False[i] == 0) { //생성자가 없는 0인경우만 출력.
            printf("%d\n",  array_Num[i]);
        }
    }
    
    return 0;
}