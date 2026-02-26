#include <stdio.h>

int main() {
    int x,y;//x = 월 , y = 일
    int sum_Day = 0;
    scanf("%d %d", &x, &y);
    
    for (int i = 1 ; i < x ; i++) {
        
        if ((i == 1) || (i == 3) || (i == 5) || (i == 7) || (i == 8) || (i == 10) || (i == 12) ) {
            sum_Day += 31;
        }
        
        else if((i == 4) || (i == 6) || (i == 9) || (i == 11) ) {
            sum_Day += 30;
        }
        
        else {
            sum_Day += 28;
        }
    }
    sum_Day += y; 
    //sum_Day를 7로 나누어 나머지를 통해 요일 예측 가능.
    

    if (sum_Day % 7 == 0) {
        printf("SUN");
    }
    else if (sum_Day % 7 == 1) {
        printf("MON");
    }
    else if (sum_Day % 7 == 2) {
        printf("TUE");
    }
    else if (sum_Day % 7 == 3) {
        printf("WED");
    }
    else if (sum_Day % 7 == 4) {
        printf("THU");
    }
    else if (sum_Day % 7 == 5) {
        printf("FRI");
    }
    else {
        printf("SAT");
    }
    
    
    return 0;
}