#include <stdio.h>

int main() {
    
    int N, M, change_Min = 64; //N, M은 행 열, change_Min은 변경할 횟수.
    scanf("%d %d", &N, &M);
    char array_Chess[N][M]; //array_Chess는 입력받을 체스판, cutting_Chess은 8*8로 잘라진 체스판.
    char array_WB[8][8], array_BW[8][8];
    
    for (int i = 0 ; i < N ; i++) { // array_Chess내부를 전부 공백으로 초기화.
        
        for (int j = 0 ; j < M; j++) {
            
            array_Chess[i][j] = ' ';    
        }
    }
    
    for (int i = 0 ; i < 8 ; i++) { // array_WB를 WB반복으로 대입.
        
        for (int j = 0 ; j < 8; j++) {
            
            if ((i + j) % 2 == 0) {array_WB[i][j] = 'W';}
            else {array_WB[i][j] = 'B';}
        }
    }
    for (int i = 0 ; i < 8 ; i++) { // array_BW를 BW반복으로 대입.
        
        for (int j = 0 ; j < 8; j++) {
            
            if ((i + j) % 2 == 0) {array_BW[i][j] = 'B';}
            else {array_BW[i][j] = 'W';}
        }
    }
    
    
    for (int i = 0 ; i < N ; i++) { //array_Chess에 대입 할 체스판 입력받기.
        
        scanf("%s", array_Chess[i]);
    }

    //그냥 비교.
    //1. 체스판 짜르기
    //2. WB, BW 비교
    //3. 짤라진 체스판 하나씩 다 비교.
    

    
    for (int change_Heng = 0 ; change_Heng < N - 7 ; change_Heng++) { //고정 시킬 범위 change_Heng을 기준으로 +0~+7함.
        
        for (int change_Yul = 0 ; change_Yul < M - 7 ; change_Yul++) { //고정 시킬 범위 change_Yul을 기준으로 +0~+7 함.
            
            
            
            
            int WB_Case_Wrong = 0, BW_Case_Wrong = 0; //WB와 BW를 각각 개별 대조시켜 다른 경우 +1해줄 변수.
            
            for (int i = 0 ; i < 8 ; i++) {
                
                for (int j = 0 ; j < 8 ; j++) {
                    
                        if (array_Chess[change_Heng + i][change_Yul + j] != array_WB[i][j]) { 
                            WB_Case_Wrong++;
                        }
                        if (array_Chess[change_Heng + i][change_Yul + j] != array_BW[i][j]) {
                            BW_Case_Wrong++;
                        }
                        
                }
                
            } //자른 체스판이랑 비교.
            
            if (change_Min > WB_Case_Wrong || change_Min > BW_Case_Wrong) { //더 작은값을 change_Min에 대입.
                change_Min = WB_Case_Wrong > BW_Case_Wrong ? BW_Case_Wrong : WB_Case_Wrong; 
            }

        }
        
    }
    
    
    
    
    printf("%d", change_Min);
    
    
    return 0;
}