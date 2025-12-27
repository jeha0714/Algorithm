#include <stdio.h>


void make_Star (int main_Num, int size_of_Star, char array_Star[][main_Num], int x_Location, int y_Location) {
    

    if (size_of_Star == 3) {
        
        for (int x = 0 ; x < 3; x++) { //배열의 행
            for (int y = 0 ; y < 3; y++) { //배열의 열
    
                if (x == 1 && y == 1) {
                    array_Star[x_Location + x][y_Location + y] = ' ';
                }
                else  {
                    
                    array_Star[x_Location + x][y_Location + y] = '*';
                }

            }//배열의 열
            
        }//배열의 행
    
        
    }
    else { //size_of_Star가 3이 아닌 9이상일 경우. (3의 배수임.)

        for (int spot = 1; spot <= 9; spot++) {

            if (spot == 1) {

                make_Star(main_Num, size_of_Star / 3, array_Star, size_of_Star / 3 * 0 + x_Location, size_of_Star / 3 * 0 + y_Location);
            }
            else if (spot == 2) {

                make_Star(main_Num, size_of_Star / 3, array_Star, size_of_Star / 3 * 0 + x_Location, size_of_Star / 3 * 1 + y_Location);
            }
            else if (spot == 3) {

                make_Star(main_Num, size_of_Star / 3, array_Star, size_of_Star / 3 * 0 + x_Location, size_of_Star / 3 * 2 + y_Location);
            }
            else if (spot == 4) {

                make_Star(main_Num, size_of_Star / 3, array_Star, size_of_Star / 3 * 1 + x_Location, size_of_Star / 3 * 0 + y_Location);
            }
            else if (spot == 5) {

                continue;
            }
            else if (spot == 6) {

                make_Star(main_Num, size_of_Star / 3, array_Star, size_of_Star / 3 * 1 + x_Location, size_of_Star / 3 * 2 + y_Location);
            }
            else if (spot == 7) {

                make_Star(main_Num, size_of_Star / 3, array_Star, size_of_Star / 3 * 2 + x_Location, size_of_Star / 3 * 0 + y_Location);
            }
            else if (spot == 8) {

                make_Star(main_Num, size_of_Star / 3, array_Star, size_of_Star / 3 * 2 + x_Location, size_of_Star / 3 * 1 + y_Location);
            }
            else if (spot == 9) {

                make_Star(main_Num, size_of_Star / 3, array_Star, size_of_Star / 3 * 2 + x_Location, size_of_Star / 3 * 2 + y_Location);
            }

        }

    }


}


 

int main() {

    int N; //N은 3의 제곱.
    scanf("%d", &N);
    char array_Star[N][N];
    
    for (int i = 0; i < N; i++) {//빈칸으로 초기화.

        for (int j = 0; j < N ; j++) {
            
            (*(array_Star + i))[j] = ' ';
        }
    }



    make_Star(N, N, array_Star, 0, 0); //재귀 함수 시작.

    for (int i = 0; i < N; i++) {//만들어진 별을 출력!

        for (int j = 0; j < N ; j++) {

            printf("%c", (*(array_Star + i))[j]);
        }

        printf("\n");
    }
    

    return 0;
}