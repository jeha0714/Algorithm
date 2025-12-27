#include <stdio.h>


int how_Know_num_Moving(int num) { //3개의 장대이므로 간단한 공식을 통해 옮긴횟수가 도출됨. 재귀함수 사용
    
    if (num == 1) {
        return 1;
    }
    else {
        return ( how_Know_num_Moving(num - 1) * 2 ) + 1;
    }
    
}


void show_Moving(int num, int hanoi_Stick[], int hanoi_Size ) { //재귀 함수를  이용하여 하노이 탑 이동 과정을 출력.
    //차례대로 원판의 개수(유동), 장대에 따른 원파의 위치를 나타낸 배열, 원판의 개수(이 값은 고정값임.)

    if (num == 1) {
        
        if (hanoi_Size % 2 == 0) //전체 원판의 개수가 짝수 일 때
        {
            if (hanoi_Stick[hanoi_Size] == 3) {
                //짝수번째 판은 3번째 장대에서 오른쪽으로 움직일 때 1번째 장대로 이동한다.
                
                printf("%d ", hanoi_Stick[hanoi_Size]);
                hanoi_Stick[hanoi_Size] = 1;
                printf("%d\n", hanoi_Stick[hanoi_Size]);
            }
            
            else { //1,2번째 장대에 있을 때는 한칸씩 오른쪽 장대로 이동시켜준다.
            
                printf("%d ", hanoi_Stick[hanoi_Size]++); //오른쪽으로 한 칸 이동.
                printf("%d\n", hanoi_Stick[hanoi_Size]);
            }
            
        }
        else if (hanoi_Size % 2 != 0) //전체 원판의 개수가 홀수 일 때
        {
            if (hanoi_Stick[hanoi_Size] == 1) {
                //홀수번째 판은 1번째 장대에서 왼쪽으로 움직일 때 3번째 장대로 이동한다.
                
                printf("%d ", hanoi_Stick[hanoi_Size]);
                hanoi_Stick[hanoi_Size] = 3;
                printf("%d\n", hanoi_Stick[hanoi_Size]);
            }
            
            else { //2,3번째 장대에 있을 때는 한칸씩 왼쪽 장대로 이동시켜준다.
            
                printf("%d ", hanoi_Stick[hanoi_Size]--); //왼쪽으로 한 칸 이동.
                printf("%d\n", hanoi_Stick[hanoi_Size]);
            }
            
        }
        
    }
    else { // num != 1
        
        show_Moving(num - 1, hanoi_Stick, hanoi_Size); //중심을 기준으로 이동하는 원판이 대칭적이다.
        
        
        if ( (hanoi_Size - num) % 2 != 0 ) { //맨 아래 원판을 기준으로 홀수 번째 원판일 때.
            //홀수 번 째는 왼쪽으로 이동.
            
            if ( hanoi_Stick[hanoi_Size - num] == 3) {
                //짝수번째 판은 3번째 장대에서 오른쪽으로 움직일 때 1번째 장대로 이동한다.
                    
                printf("%d ", hanoi_Stick[hanoi_Size - num]);
                hanoi_Stick[hanoi_Size - num] = 1; 
                printf("%d\n", hanoi_Stick[hanoi_Size - num]);
            }
                
            else  {//1,2번째 장대에 있을 때는 한칸씩 오른쪽 장대로 이동시켜준다.
                    
                printf("%d ", hanoi_Stick[hanoi_Size - num]++); //오른쪽으로 한 칸 이동.
                printf("%d\n", hanoi_Stick[hanoi_Size - num]);
            }
            
        }
        
        else if ( (hanoi_Size - num) % 2 == 0 ) { //맨 아래 원판을 기준으로 짝수 번 째 원판일 때
            //짝수 번 째 오른쪽으로 이동.
            
            if ( hanoi_Stick[hanoi_Size - num] == 1) {
                //홀수번째 판은 1번째 장대에서 왼쪽으로 움직일 때 3번째 장대로 이동한다.
                
                printf("%d ", hanoi_Stick[hanoi_Size - num]);
                hanoi_Stick[hanoi_Size - num] = 3;
                printf("%d\n", hanoi_Stick[hanoi_Size - num]);
            }
                
            else { //2,3번째 장대에 있을 때는 한칸씩 왼쪽 장대로 이동시켜준다.
                    
                printf("%d ", hanoi_Stick[hanoi_Size - num]--); //왼쪽으로 한 칸 이동.
                printf("%d\n", hanoi_Stick[hanoi_Size - num]);
            }
            
        }
        
        
        show_Moving(num - 1, hanoi_Stick, hanoi_Size); //중심을 기준으로 이동하는 원판이 대칭적이다.
        
    } // num != 1 일 때 끝
    
} //show_Moving의 끝



int main() {
    
    int N; //장대에 쌓인 원판의 개수
    int num_Moving = 0; // 원판을 옮긴 횟수
    
    scanf("%d", &N);
    
    int hanoi_Stick[N + 1]; //하노이 원판을 설정 인덱스 1이 가장 밑에 원판이며 N인덱스가 가장 위 원판을 의미!
    for (int i = 0 ; i <= N ; i++) {hanoi_Stick[i] = 1;} //모든 값을 1로 초기화하여 모든 원판이 1장대에 있다는것을 의미!
    
    //옮긴 횟수부터 구하기.
    num_Moving = how_Know_num_Moving(N);
    printf("%d\n", num_Moving);
    
    
    //하노이 탑 이동 과정을 출력.
    show_Moving(N, hanoi_Stick, N);
    

    return 0;
}