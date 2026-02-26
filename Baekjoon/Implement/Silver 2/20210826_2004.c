#include <stdio.h>


long long Find_prime_Two(int num) //소인수 분해 결과 2의 지수 반환
{
    long long num_Two = 0;
    
    for (long long start_Two = 2 ; ; start_Two*=2 )
    {
        if ( num / start_Two == 0 ) {break;}
        else { num_Two += (num / start_Two); }
    }

    
    return num_Two;
}


long long Find_prime_Five(int num) //소인수 분해 결과 5의 지수 반환
{
    long long num_Five = 0;
    
    for (long long start_Five = 5 ; ; start_Five*=5 )
    {
        if ( num / start_Five == 0 ) {break;}
        else { num_Five += (num / start_Five); }
    }
    
    
    return num_Five;
}


int main() {
    
    int n,m; // n C m 의 n 과 m .
    long long prime_Two_n, prime_Five_n; //n의 2의 지수와 5의 지수
    long long prime_Two_m, prime_Five_m; // m의 2의 지수와 5의 지수
    long long prime_Two_nm, prime_Five_nm; // n-m의 2의 지수와 5의 지수 이항계수를 계산하기 위해 n-m!이 사용됨.
    long long min_two_or_five;
    
    scanf("%d %d", &n, &m);
    
    // 함수를 사용하여 2와 5의 지수를 구함.
    prime_Two_n = Find_prime_Two(n); prime_Five_n = Find_prime_Five(n);
    prime_Two_m = Find_prime_Two(m); prime_Five_m = Find_prime_Five(m);
    prime_Two_nm = Find_prime_Two(n - m); prime_Five_nm = Find_prime_Five(n - m);
    
    // n의 2와 5의 지수를 m과 n-m의 2와 5의 지수로 뺀 다음 2와 5의 지수중 작은 값을 대입 할 시 0의 개수가 나옴.
    min_two_or_five = ( prime_Two_n - prime_Two_m - prime_Two_nm ) >= ( prime_Five_n - prime_Five_m - prime_Five_nm ) ? ( prime_Five_n - prime_Five_m - prime_Five_nm ) : ( prime_Two_n - prime_Two_m - prime_Two_nm ); 
    
    
    printf("%lld", min_two_or_five );
    
    return 0;
}