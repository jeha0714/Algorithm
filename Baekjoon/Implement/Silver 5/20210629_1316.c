#include <stdio.h>

int main() {
    
    int N, result = 0;//result는 그룹단어 총 개수.
    scanf("%d", &N);
    
    for(int i = 0 ; i < N ; i++) {
        int check_Code = 0; //마지막 그룹단어 판별하기 위한 값.
        int how_Long = 0; //단어 길이 파악.
        
        char array_Word[101]; // 단어입력
        scanf("%s", array_Word);
        for(int j = 0; ; j++) { //단어 길이 파악 반복문.
            if (array_Word[j] != '\0') {how_Long++;}
            else {break;}
        }
        
        int array_Alp[26]; // 알파벳 배열 값 모두 0으로 초기화 후 알고리즘 시작
        for(int j = 0; j <26 ; j++) {
            array_Alp[j] = 0;
        }
        
        for(int j = 0 ; ; j++) {
            if (array_Word[j] == '\0') {break;}
            
            else { 
            //단어 입력받고 해당 Alp배열 증가 후 다음 문자가 동일한 경우 0으로 초기화 불일치 할 경우 증가만 하고 그룹단어 판별 값 증가.
            // if 문을 써서 Alp값이 0이 아닐경우 break걸고 check_Code값 미동.
                
                if (array_Alp[array_Word[j]%97] == 0) {
                    
                    array_Alp[array_Word[j]%97]++;
                    if (array_Word[j] == array_Word[j+1]) {
                        array_Alp[array_Word[j]%97] = 0;
                    }
                    check_Code++;
                }
                
                else {//array_Alp[array_Word[j]%97] != 0
                    break;
                }
            }
        }
        
        if (check_Code == how_Long) { //check_Code로 모든 단어를 거쳤을 경우 문자열 길이랑 동일. 중간에 break걸렸을 경우에만 불일치.
            result++;
        }
        else {
            continue;
        }
        
    }
    
    printf("%d", result); 
    
    return 0;
}