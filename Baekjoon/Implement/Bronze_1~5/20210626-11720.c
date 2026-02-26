#include<stdio.h>

int main()
{
    int howManyNum;
    char array_Num[100];
    int sumAll=0;    
    
    scanf("%d", &howManyNum);
    scanf("%s", array_Num);
    
    //하나하나를 int로 변환해야함.
    
    for (int i=0;;i++){
        
        if(array_Num[i] == '\0') {
             break;   
        }
        else {
            if (array_Num[i] == '0') {
                sumAll +=0;
            }
            else if (array_Num[i] == '1') {
                sumAll +=1;
            }
            else if (array_Num[i] == '2') {
                sumAll +=2;
            }
            else if (array_Num[i] == '3') {
                sumAll +=3;
            }
            else if (array_Num[i] == '4') {
                sumAll +=4;
            }
            else if (array_Num[i] == '5') {
                sumAll +=5;
            }
            else if (array_Num[i] == '6') {
                sumAll +=6;
            }
            else if (array_Num[i] == '7') {
                sumAll +=7;
            }
            else if (array_Num[i] == '8') {
                sumAll +=8;
            }
            else if (array_Num[i] == '9') {
                sumAll +=9;
            }
            else {
                continue;
            }
        }
    
    }
    
    printf("%d",sumAll);
    
    return 0;
}