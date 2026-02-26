#include<stdio.h>

int main()
{
    int array_Say[8];
    int code = 0;
    
    for (int i=0;i<8;i++) {
        scanf("%d",&array_Say[i]);
    }
    
    for (int i=1;i<9;i++){
        if (i ==8 && array_Say[i-1] == 8){
            printf("ascending");
            code = 1;
        }
        else if(array_Say[i-1] == i) {
            continue;
        }
        else {
            break;
        }
    }
    
    for (int i=1;i<9;i++){
        if (i == 8 && array_Say[i-1] == 1){
            printf("descending");
        }
        else if(array_Say[i-1] + i == 9) {
            continue;
        }
        else {
            if (code == 1) {
                break;
            }
            else {
                printf("mixed");
                break;
            }
        }
    }
    
    return 0;
}