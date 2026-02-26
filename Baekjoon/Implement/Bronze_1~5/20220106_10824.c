#include <stdio.h>

int main()
{
    long long a, b, c, d; scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    
    long long result = 0;
    
    for (int i = 1; i <= 100000; i *= 10)
    {
        if ( b / i > 0 && b / ( i * 10 ) == 0 )
            result += ( a * i * 10 + b );
    }
    for (int i = 1; i <= 100000; i *= 10)
    {
        if ( d / i > 0 && d / ( i * 10 ) == 0 )
            result += ( c * i * 10 + d );
    }
    
    printf("%lld", result );

    return 0;
}
