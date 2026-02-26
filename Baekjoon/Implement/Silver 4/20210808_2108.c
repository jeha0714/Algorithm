#include <stdio.h>
#include <stdlib.h>


int compare(const void * first, const void * second) { // 주어진 수들 오름차순 정리.
    
    if ( *(int *)first < *(int *)second ) {return -1;}
    else if ( *(int *)first == *(int *)second ) {return 0;}
    else {return 1;}
    
}




int main() {
    
    int N; //수의 개수 N
    int sum_All = 0; //평균을 구할 때 사용 될 변수와 최빈값에 사용될 변수.
    int how_Many_Appear = -1, Appear_Max = -1, check_Code = -1; //얼마나 자주 등장했는지의 변수와 최빈값을 저장하는 변수와 
    //최빈값이 여러 개 있을 경우 두 번째로 작은 값을 알아낼 때 사용될 변수.
    scanf("%d", &N);
    int array_N[N], num_N[8001]; //array_N은 N개의 수가 들어갈 배열, num_N은 각 숫자가 출현한 횟수가 저장될 배열.(음수값 때문에 배열의 크기가 커짐.)
    
    for (int i = 0; i <= 8000 ; i++) {num_N[i] = 0;} //배열의 모든 값을 0으로 초기화.
    
    for (int i = 0 ; i < N ;i++) { //배열에 수들 입력
        scanf("%d", &array_N[i]);
        sum_All += array_N[i]; //입력됨과 동시에 전체 합 구하기.
        
        if (array_N[i] > 0) { num_N[array_N[i] + 4000 ]++; } //입력된 값이 양수일 경우 num_N[i + 4000]부터 출현을 +1 해줌.
        else if (array_N[i] < 0) { num_N[ array_N[i] + 4000 ]++; } //입력된 값이 음수일 경우 num_N[3999] ~ num_N[0]까지 -1 ~ -4000의 출현을 +1.
        else if (array_N[i] == 0) { num_N[4000]++; } //입력된 값이 0인경우 array_N[4000]의 출현 +1
        
    }
    
    
    
    qsort(array_N, N, sizeof(array_N[0]), compare); //퀵정렬로 오름차순 정리.
    
    
 
    //산술평균 출력. (소수점 이하 첫 째 자리에서 반올림)
    if ( (double)sum_All / (double)N - (double)(sum_All / N) >= 0.5 || (double)sum_All / (double)N - (double)(sum_All / N) <= -0.5 ) { 
        //평균이 양수이거나 음수일 때
        
        if ( (double)sum_All / (double)N - (double)(sum_All / N) < 0 ) { //평균이 음수인 경우 반올림 적용.
            printf("%d\n", sum_All / N - 1);
        }
        else if ( (double)sum_All / (double)N - (double)(sum_All / N) >= 0 ) { //평균이 양수인 경우 반올림 적용.
            printf("%d\n", sum_All / N + 1); 
        }
        
    }
    else { //반올림을 안해도 되는 상황일 때
        printf("%d\n", sum_All / N);
    }
    
    //중앙값 출력 (N은 항상 홀수라고 문제조건에 주어져있음.)
    printf("%d\n", array_N[N / 2]);
    
    //최빈값 출력 (여러개 있을 때 두번째로 작은 값 출력.)
    for (int i = 0; i <= 8000 ;i++) {
        
        if ( num_N[i] >  how_Many_Appear ) {
            
            how_Many_Appear = num_N[i];
            check_Code = -1;
            
            if (i < 4000) { Appear_Max = i - 4000 ; } 
            else if (i == 8000) { Appear_Max = 4000; }
            else if ( i >= 4000) { Appear_Max = i % 4000 ;}
            
        }
        else if ( num_N[i] == how_Many_Appear && check_Code == -1) { //최빈값이 같고 두번째로 작은 수인 경우.
            
            how_Many_Appear = num_N[i];
            check_Code = 0;
            
            if (i < 4000) { Appear_Max = i - 4000 ; } 
            else if (i == 8000) { Appear_Max = 4000; }
            else if ( i >= 4000) { Appear_Max = i % 4000 ; }
            
        }
        else if ( num_N[i] == how_Many_Appear && check_Code == 0) { //최빈값이 같고 세번째이상으로 작은 수인 경우.
            
            continue;
        }
        
    }
    printf("%d\n", Appear_Max);
    
    //범위를 출력. (최댓값 최솟값 차이)
    printf("%d\n", array_N[N - 1] - array_N[0]);    
    
    
    
    return 0;
}