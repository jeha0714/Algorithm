#include <stdio.h>


void check_array(int array_Num[]) { //각 자리수가 10이 넘는 경우를 파악하여 다음 자리수에 +1 해준다.
    
    for (int i = 19 ; i >= 0 ; i--) {
        
        if (array_Num[i] >= 10) {
            
            array_Num[i] %= 10;
            array_Num[i - 1]++;
        }//자리수의 값이 10이 넘는 경우 %10으로 값을 변경해준 후 다음 자리 수에 +1 해준다.
        
    }
    
}

int find_more_Three_Six(int array_Num[]) { //각 자리수를 확인하여 6이 3개 이상 있는지 확인한다.
    
    for (int i = 19; i >= 2; i--) {
        
        if (array_Num[i] == 6 && array_Num[i - 1] == 6 && array_Num[i - 2] ==6) {
            return 0;
        }
    }
    
    return 1;
}

void show_Array(int array_Num[]) {
    
    int i_m_not_Zero;
    //맨 앞에서 부터 0이 아닌 배열의 인덱스를 찾는다.
    for (int i = 0 ; i < 20 ;i++) {
        
        if (array_Num[i] != 0) {
            
            i_m_not_Zero = i;
            break;
        }
        
    }
    
    //0이 아닌 인덱스부터 차례로 출력한다.
    for (int i = i_m_not_Zero ; i < 20; i++) {
        
        printf("%d", array_Num[i]);
    }
    
}



int main() {
    
    int N; //N번째 숫자를 출력.
    int now_Num_for_N = 0; //666이 나올때마다 조건을 만족하는 몇 번째 수 인지 알려주는 변수.
    int array_Num[20]; //답을 찾기 위해 사용되는 공간.
    scanf("%d", &N);
    
    for (int i = 0 ; i < 20; i++) {array_Num[i] = 0;} //array_Num의 모든 배열 요소를 0으로 초기화.
    
    
    
    while (1) { //1부터 +1해서 찾는 알고리즘.
        
        //1의 자릿 수를 +1 해준다.
        array_Num[19] += 1;
        
        //각 자리 수가 10넘는 경우 계산.
        check_array(array_Num);
        
        //6이 3번 연속 나오는지 확인할 수 있도록 하고 조건에 부합할 경우 now_Num_for_N++ 해준다.
        if (find_more_Three_Six(array_Num) == 0) {now_Num_for_N++;}
        
        
        if (now_Num_for_N == N) {break;}//N번째 수를 발견 시 break 걸고 해당 수를 출력.
        
    }
    
    
    show_Array(array_Num); //N번째 수를 출력.
    
    
    return 0;
}