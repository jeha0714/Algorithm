#include <stdio.h>

long long a, b, c, d, e;

// 큰 수 계산 함수
void calculate_Big_Num( long long num )
{
    e += num;
    
    d += ( e / 100000000000000000);
    e = ( e % 100000000000000000);
    
    c += ( d / 100000000000000000);
    d = ( d % 100000000000000000);
    
    b += ( c / 100000000000000000);
    c = ( c % 100000000000000000);
    
    a += ( b / 100000000000000000);
    b = ( b % 100000000000000000);
}

// 큰 수 출력 함수
void print_Big_Num()
{
    if ( a == 0 && b == 0 && c == 0 && d == 0 )
        printf("%lld", e);
    else if ( a == 0 && b == 0 && c == 0 )
        printf("%lld%.17lld", d, e);
    else if ( a == 0 && b == 0 )
        printf("%lld%.17lld%.17lld", c, d, e);
    else if ( a == 0 )
        printf("%lld%.17lld%.17lld%.17lld", b, c, d, e);
    else 
        printf("%lld%.17lld%.17lld%.17lld%.17lld", a, b, c, d, e);
}




int main() {
    
    int num_City; scanf("%d", &num_City); // 도시의 수
    int road_Length[ num_City - 1 ]; // 인접한 두 도시를 연결하는 도로의 길이를 저장한 배열
    for (int i = 0 ; i < num_City - 1 ; i++ ) { scanf("%d", &road_Length[ i ] ); }
    int oil_Price[ num_City ]; // 제일 왼쪽 도시부터 주유소의 리터당 가격.
    for (int i = 0 ; i < num_City ; i++ ) { scanf("%d", &oil_Price[ i ] ); }
    
    long long now_Moving = 0; // 현재 리터 당 오일로 움직인 거리
    int now_Price = oil_Price[ 0 ]; // 현재 리터 당 오일 가격
    
    for (int now_Index = 1 ; now_Index < num_City ; now_Index++ )
    {
        // 현재 도시의 오일 가격이 저장된 오일 가격보다 싸다면
        // 이 도시까지 움직인 거리를 min_Result에 가격측정해서 더한 후 now_Price를 현재 도시의 오일로 저장. 
        if ( now_Price > oil_Price[ now_Index ] )
        {
            now_Moving += road_Length[ now_Index - 1 ];
            calculate_Big_Num( (long long)now_Moving * (long long)now_Price );
            now_Moving = 0;
            
            now_Price = oil_Price[ now_Index ];
        }
        
        else
            now_Moving += road_Length[ now_Index - 1 ];
        
    }
    
    calculate_Big_Num( now_Moving * now_Price );
    print_Big_Num();
    
    return 0;
}