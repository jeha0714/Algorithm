#include <stdio.h>
#include <stdlib.h>

// 큰 수 계산 함수
void countS(int n) 
{
	long long a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		b *= 2;
		a = a * 2 + 1;
		b += a / 1000000000000000000;
		a %= 1000000000000000000;
	}
	if ( b == 0)
        printf("%lld\n", a);
    else
        printf("%lld%lld\n", b, a);
}

// 왼쪽으로 움직 일 때 
void moving_Left( short location_Hanoi[], short wonpan )
{
    if ( location_Hanoi[ wonpan ] == 1 )
    {
        printf("1 3\n");
        location_Hanoi[ wonpan ] = 3;
    }
    
    else
    {
        printf("%d %d\n", location_Hanoi[ wonpan ], location_Hanoi[ wonpan ] - 1 );
        location_Hanoi[ wonpan ]--;
    }
    
}

// 오른쪽으로 움직 일 때
void moving_Right( short location_Hanoi[], short wonpan )
{
    if ( location_Hanoi[ wonpan ] == 3 )
    {
        printf("3 1\n");
        location_Hanoi[ wonpan ] = 1;
    }
    
    else
    {
        printf("%d %d\n", location_Hanoi[ wonpan ], location_Hanoi[ wonpan ] + 1 );
        location_Hanoi[ wonpan ]++;
    }
    
}

// 하노이 탑 움직일 때 재귀함수.
void calculate_Hanoi( short num_Hanoi, short now_Wonpan, short location_Hanoi[] )
{
    if ( now_Wonpan < 1 ) 
        return;
    
    else
    {
        calculate_Hanoi( num_Hanoi, now_Wonpan - 1, location_Hanoi );
        
        
        if ( ( num_Hanoi + now_Wonpan ) % 2 == 0 )
        {
            moving_Left( location_Hanoi, now_Wonpan );
        }
        
        else 
        {
            moving_Right( location_Hanoi, now_Wonpan);
        }
        
        
        calculate_Hanoi( num_Hanoi, now_Wonpan - 1, location_Hanoi );
    }
    
}



int main() {
    
    short num_Hanoi, now_Wonpan; // 장대에 쌓인 원판의 총 개수
    scanf("%hd", &num_Hanoi);
    now_Wonpan = num_Hanoi;
    
    short location_Hanoi[ num_Hanoi + 1 ]; // 원판의 현재 위치를 저장한 배열 1~3
    for (short now_Index = 0; now_Index < num_Hanoi + 1; now_Index++) { location_Hanoi[now_Index] = 1; }
    
    if ( num_Hanoi <= 20 )
    {
        countS( num_Hanoi ); 
        calculate_Hanoi( num_Hanoi, now_Wonpan, location_Hanoi );
    }
    else
        countS( num_Hanoi ); 
    
    return 0;
}