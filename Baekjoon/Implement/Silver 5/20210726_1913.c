#include <stdio.h>

int main() {
    int N, num = 1; //N은 배열 크기, num은 입력될 숫자.
    int x, y, find_Num; //x,y는 반환할 find_Num의 위치를 저장할 변수. find_Num은 찾을 숫자를 저장할 변수.
    int run_Twice = 1, handle = 8; //방향을 나타내는 변수로 2는 아래, 6은 오른쪽, 8은 위, 4는 왼쪽을 뜻함.
    int heng = 0, yul = 0; //heng은 행, yul은 열.
    scanf("%d %d", &N, &find_Num);
    int array_Snail[N][N];
    
    heng = N / 2; yul = N / 2;
    array_Snail[heng][yul] = 1; num++;
    
    
    // 아래 알고리즘
    // 11 22 33 44 이런식으로 두번씩 움직인다. but 마지막은 세번 움직이므로 마지막은 따로 구현. 
    // 2번식 움직이는 것만 아래 for문으로 구현.
    for (int i = 1; i < N ;) {
        
        
        if (run_Twice == 1) {
            
            if (handle == 2) {
                
                for (int j = 0; j < i ; j++) {
                    
                    heng++;
                    array_Snail[heng][yul] = num; num++;
                
                }
                handle = 4;
                
            }
            else if (handle == 4) {
                
                for (int j = 0; j < i ; j++) {
                    
                    yul--;
                    array_Snail[heng][yul] = num; num++;
                
                }
                handle = 8;
                
            }
            else if (handle == 8) {
                
                for (int j = 0; j < i ; j++) {
                    
                    heng--;
                    array_Snail[heng][yul] = num; num++;
                
                }
                handle = 6;
                
            }
            else if (handle == 6) {
                
                for (int j = 0; j < i ; j++) {
                    
                    yul++;
                    array_Snail[heng][yul] = num; num++;
                
                }
                handle = 2;
                
            }
            
            
            run_Twice = 2;
        }
        else { //run_Twice == 2
            
            
            if (handle == 2) {
                
                for (int j = 0; j < i ; j++) {
                    
                    heng++;
                    array_Snail[heng][yul] = num; num++;
                
                }
                handle = 4;
                
            }
            else if (handle == 4) {
                
                for (int j = 0; j < i ; j++) {
                    
                    yul--;
                    array_Snail[heng][yul] = num; num++;
                
                }
                handle = 8;
                
            }
            else if (handle == 8) {
                
                for (int j = 0; j < i ; j++) {
                    
                    heng--;
                    array_Snail[heng][yul] = num; num++;
                
                }
                handle = 6;
                
            }
            else if (handle == 6) {
                
                for (int j = 0; j < i ; j++) {
                    
                    yul++;
                    array_Snail[heng][yul] = num; num++;
                
                }
                handle = 2;
                
            }
            
            
            run_Twice = 1; i++;
        }
        
    }
    
    
    
    for (int i = 0; i < (N - 1) ;i++) { //마지막 세번째로 handle = 8인경우를 구현.
        
        heng--;
        array_Snail[heng][yul] = num; num++;
    }
    
    
    for (int i = 0 ; i < N; i++) { //배열 출력.
        
        for (int j = 0 ; j < N ; j++) {
            
            printf("%d ", array_Snail[i][j]);
            if (find_Num == array_Snail[i][j]) { //원하는 숫자의 위치를 반환하기 위해 if문 사용.
                x = i; y = j;    
            }
            
        }
        
        printf("\n");
    }
    
    printf("%d %d", x + 1, y + 1); //+1을 하는 이유는 배열은 1이 아닌 [0][0]부터 시작하기 때문.
    
    return 0;
}