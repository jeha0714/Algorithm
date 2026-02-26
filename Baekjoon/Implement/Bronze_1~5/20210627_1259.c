#include <stdio.h>

int main() {
    
    while (1){
        char array_Num[100000];
        int check_code = 0;
        
        scanf("%s", array_Num);
        
        if(array_Num[0] == '0') {
            break;
        }
        else {
            int how_Long = 0; //주어진 정수의 길이 체크.
            for(int i =0; ;i++) {
                if(array_Num[i] == '\0') {break;}
                else {how_Long++;}
            }
            
            if(how_Long %2 ==0) {//길이 짝수인 경우
             
                for(int i =0; i < how_Long/2;i++) {
                    if(array_Num[i] != array_Num[how_Long-1-i]) {
                        check_code =1;
                        break;
                    }
                }
                if (check_code == 0) {
                    printf("yes\n");
                }
                else {
                    printf("no\n");
                }
                
            }
            else { // 길이 홀수인 경우
                
                for(int i =0; i <how_Long /2; i++) {
                    if(array_Num[i] != array_Num[how_Long-1-i]) {
                        check_code =1;
                        break;
                    }
                }
                if (check_code == 0) {
                    printf("yes\n");
                }
                else {
                    printf("no\n");
                }
            }
            
        }
        
    }
    
    return 0;
}