#include <stdio.h>

int main()
{
    int n; scanf("%d", &n);
    long long sum_All = 0;
    
    for (int now = 0 ; now < n ; now++)
    {
        int num; scanf("%d", &num );
        
        sum_All += num;
        
    }
    
    printf("%lld", sum_All - n + 1);
    
    
    return 0;
}
