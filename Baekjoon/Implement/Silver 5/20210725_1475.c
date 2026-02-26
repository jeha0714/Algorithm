#include <stdio.h>
#include <math.h>


int how_Long(int num) { //입력받은 수의 길이를 정해주는 함수
    
    
    if (num / 100000 != 0) {
        return 6;
    }
    else if (num / 10000 != 0) {
        return 5;
    }
    else if (num / 1000 != 0) {
        return 4;
    }
    else if (num / 100 != 0) {
        return 3;
    }
    else if (num / 10 != 0) {
        return 2;
    }
    else {
        return 1;
    }
    
}


void how_Many(int num, int length, int array[]) { //각 자리의 숫자를 알아내고 array에 +1해주는 함수.
    
    int N = num;
    int N_Length = length;
    
    array[(N / (int)(pow(10, N_Length - 1)))] += 1;
    
    for (int i = N_Length - 1 ; i > 0 ; i--) {
        
        array[(N % (int)(pow(10, i)) / (int)pow(10, i - 1))] += 1;
    }
    
}



int main() {
    int array_Num[10]= {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //0~9까지 나온 횟수를 저장할 배열.
    int N, max_Num = 0, num_Length;//N은 방 번호, max_Num은 배열에서 저장된 가장 큰 수를 저장할 변수.
    //num_Length는 입력받은 숫자의 길이를 저장할 변수.
    
    scanf("%d", &N);
    
    num_Length = how_Long(N);
    how_Many(N, num_Length, array_Num);
    
    
    if ((array_Num[6] + array_Num[9]) % 2 == 0) { //6과 9는 하나의 카드로 대체 가능하기에 2개당 1세트로 침.
        
        array_Num[6] = (array_Num[6] + array_Num[9]) / 2;
    }
    else { //(array_Num[6] + array_Num[9]) % 2 != 0
        
        array_Num[6] = (array_Num[6] + array_Num[9]) / 2 + 1;
    }
    
    
    for (int i = 0 ; i < 9; i++) { //배열 전체를 돌면서 max_Num을 확인하는 변수.
        
        if (max_Num < array_Num[i]) {
            max_Num = array_Num[i];
        }
        
    }
    
    
    printf("%d", max_Num);
    

    
    return 0;
}