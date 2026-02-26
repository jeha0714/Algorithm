#include<stdio.h>

int main()
{
    int num1,num2;
    int check1,check2;
    
    scanf("%d %d", &num1,&num2);
    
    check1 = (num1/100)+(num1%100/10*10)+(num1%10*100);
    check2 = (num2/100)+(num2%100/10*10)+(num2%10*100);

    if (check1> check2) {
        printf("%d", check1);
    }
    else {
        printf("%d", check2);
    }
    return 0;
}