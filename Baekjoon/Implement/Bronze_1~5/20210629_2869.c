#include<stdio.h>

int main()
{
    long long A,B,V;
    int up_High =0;
    long result;
    
    scanf("%lld %lld %lld",&A,&B,&V);
    
    if ((V-A)%(A-B) == 0) {
        result = (V-A)/(A-B) + 1;
    }
    else {
        result = (V-A)/(A-B) +2;
    }
    
    printf("%d", result);
    
    return 0;
}