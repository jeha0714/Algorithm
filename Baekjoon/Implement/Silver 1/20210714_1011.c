#include <stdio.h>

int use_Min_machine (int x, int y) {
    
    long length = y - x;
    long sum_Num  = 0, run_Twice = 1, plus_Num = 1;
    //sum_Num을 이용해서 length의 범위를 찾은 다음 반환값을 출력.
    //run_Twice는 오름차순의 각 숫자를 2번씩 더하기 위해 사용되는 변수
    //plus_Num은 sum_Num에 더하기 위해 사용되는 변수.
    
    
    
    for (int i = 1 ; i <= length ; i++) {
        
        if (run_Twice == 1) {
            
            if (length > sum_Num && length <= sum_Num + plus_Num) {
                
                return i;
            }
            else {
                
                run_Twice = 2;
                sum_Num += plus_Num;
            }
            
        }
        else {
            
            if (length > sum_Num && length <= sum_Num + plus_Num) {
                
                return i;
            }
            else {
                
                sum_Num += plus_Num;
                run_Twice = 1; plus_Num++;
            }
            
        }
        
    }
    
    
}


int main() {
    int T;
    scanf("%d", &T);
    
    for (int i = 0 ; i < T ; i++) {
        long x,y;
        scanf("%ld %ld", &x, &y);
        
        printf("%d\n", use_Min_machine(x,y));
        
    }
    
    return 0;
}