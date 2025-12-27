#include <stdio.h>

int main()
{
    // 다각형을 이루는 N개의 점
    int N; scanf("%d", &N );
    
    // N개의 점의 좌표를 저장 할 배열 첫번째 열은 x좌표, 두번째 열은 y좌표를 의미
    long long spot_Location[ N ][ 2 ];
    for ( int i = 0 ; i < N ; i++ )
        scanf("%lld %lld", &spot_Location[ i ][ 0 ], &spot_Location[ i ][ 1 ] );

    // 신발끈 정리를 이용한 다각형의 면적 구하기
    long double S = 0.0;
    for (int i = 0 ; i < N ; i++ )
    {
        if ( i == ( N - 1 ) )
            S += ( spot_Location[i][0] * spot_Location[0][1] - spot_Location[0][0] * spot_Location[i][1] );
        
        else
            S += ( spot_Location[i][0] * spot_Location[i + 1][1] - spot_Location[i][1] * spot_Location[i + 1][0] );
        
    }
    if ( S >= 0 )
        S /= 2;
    else
        S = ( S * -1 / 2 );
    
    // 소수점 아래 둘째 자리에서 반올림 하기
    if ( (int)( S * 100 )% 10 >= 5 )
        S = ( S / 0.1 * 0.1 + 0.1 );
    else
        S = ( S / 0.1 * 0.1 );
    
    // 출력
    printf("%.1Lf", S );

    return 0;
}
