#include<stdio.h>

int main()

{

    int N, M, T;

    scanf("%d %d", &N, &M);

    int array[N][M];

    

    for (int i=0; i <N; i++) {

        for (int j = 0; j < M ; j++) {

            scanf("%d", &array[i][j]);

        }

    }

    

    scanf("%d", &T);

    for (int i = 0; i < T; i++) {

        int x1,y1,x2,y2,result=0; 

        

        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        

        for (int j = x1 -1; j <x2 ; j++) {

            for (int k = y1 - 1; k < y2; k++) {

                result += array[j][k];

            }

        }

        printf("%d\n", result);

    }

    

    return 0;

}