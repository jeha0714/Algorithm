#include<stdio.h>

int main()
{
    char say_What[16];
    int sumAll=0;
    
    scanf("%s", say_What);
    
    for (int i=0;;i++) {
        if (say_What[i] =='\0') {
            break;
        }
        else {
            if (say_What[i]%65>=0 && say_What[i]%65 <=2) {
                sumAll += 3;
            }
            else if (say_What[i]%65>=3 && say_What[i]%65 <=5) {
                sumAll += 4;
            }
            else if (say_What[i]%65>=6 && say_What[i]%65 <=8) {
                sumAll += 5;
            }
            else if (say_What[i]%65>=9 && say_What[i]%65 <=11) {
                sumAll += 6;
            }
            else if (say_What[i]%65>=12 && say_What[i]%65 <=14) {
                sumAll += 7;
            }
            else if (say_What[i]%65>=15 && say_What[i]%65 <=18) {
                sumAll += 8;
            }
            else if (say_What[i]%65>=19 && say_What[i]%65 <=21) {
                sumAll += 9;
            }
            else if (say_What[i]%65>=22 && say_What[i]%65 <=25) {
                sumAll += 10;
            }
        }
        
    }
    
    printf("%d", sumAll);
    
    return 0;
}