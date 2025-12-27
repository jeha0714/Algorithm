#include <stdio.h>
#include <stdlib.h>


// 오름차순 정리 함수
int compare( const void * first , const void * second )
{
    return *(int *)first - *(int *)second;
}



int main()
{
    // 수열의 크기
    int N; scanf("%d", &N);
    
    // 수열의 각 수가 저장될 배열
    int array[ N ];
    for ( int i = 0 ; i < N ; i++ )
        scanf("%d", &array[ i ] );
    
    // 오름차순으로 배열 내부를 정리
    qsort( array, N, sizeof( array[0] ), compare );

    // 우선 음수가 끝나는 인덱스의 위치를 찾는다. ( 이분 탐색 이용 )
    int last_Minus_Index = -1;
    int start = 0, end = N, mid = ( start + end ) / 2;
    while ( start <= end )
    {
        if ( array[ mid ] < 0 )
            start = mid + 1;
        else
            end = mid - 1;
        
        mid = ( start + end ) / 2;
    }
    if ( array[ mid ] < 0 )
        last_Minus_Index = mid;
    else
        last_Minus_Index = mid - 1;
    //printf("%d", last_Minus_Index )
    
    
    // last_Minus_Index == N - 1 인 배열 내 수가 모두 음수인 경우
    if ( last_Minus_Index + 1 == N )
    {
        // 이 경우는 배열의 시작부터 끝까지 두개 씩 묶어가며 최대값을 구한다.
        int result = 0 ;
        for ( int now_Index = 0 ; now_Index < N - 1 ; now_Index += 2 )
        {
            result += ( array[ now_Index ] * array[ now_Index + 1 ] );
        }
        
        if ( N % 2 == 1 )
            result += array[ N - 1 ];
        
        
        printf("%d", result);
    }
    
    // last_Minus_Index == -1 인 배열 내 음수가 없는 경우 => 모두 양수인 경우
    else if ( last_Minus_Index == -1 )
    {
        // 이 경우는 배열의 맨 끝 부분부터 0이 나오기 전까지 두개 씩 묶어가며 최대값을 구한다.
        
        // 우선 0 혹은 1이 둘 중 제일 끝에 위치한 인덱스의 값을 구한다.
        int last_one_Or_zero = -1;
        int start = 0, end = N, mid = ( start + end ) / 2;
        while ( start <= end )
        {
            if ( array[ mid ] == 0 || array[ mid ] == 1 )
                start = mid + 1;
            else
                end = mid - 1;
            
            mid = ( start + end ) / 2;
        }
        if ( array[ mid ] == 0 || array[ mid ] == 1 )
            last_one_Or_zero = mid;
        else if ( array[ 0 ] != 0 && array[ 0 ] != 1 )
            last_one_Or_zero = last_Minus_Index;
        else
            last_one_Or_zero = mid - 1;
        //printf("%d\n", last_one_Or_zero );
        
        // 1 혹은 0 중 제일 뒤의 수 뒷편을 인덱스가 가장 높은 것 2개씩 짝지어 곱한 후 만약 하나가 남는다면 더해버린다.
        int result = 0;
        for ( int now_Index = N - 1 ; now_Index > last_one_Or_zero + 1 ; now_Index-=2 )
        {
            result += ( array[ now_Index ] * array[ now_Index - 1 ] );
        }
        
        if ( ( N - last_one_Or_zero + 1 ) % 2 == 1 && last_one_Or_zero != N )
            result += array[ last_one_Or_zero + 1 ];
          
        // 남아있는 0과 1은 모두 더해버린다.
        for ( int now_Index = 0 ; now_Index <= last_one_Or_zero ; now_Index++ )
            result += array[ now_Index ];
        
        
        printf("%d", result );
    }
    
    // 0 <= last_Minus_Index < N - 1 인 경우로 음수와 양수가 함께 있는 경우
    else
    {
        // 우선 0 혹은 1이 둘 중 제일 끝에 위치한 인덱스의 값을 구한다.
        int last_one_Or_zero = -1;
        int start = 0, end = N, mid = ( start + end ) / 2;
        while ( start <= end )
        {
            if ( array[ mid ] == 0 || array[ mid ] == 1 || array[mid] < 0 )
                start = mid + 1;
            else
                end = mid - 1;
            
            mid = ( start + end ) / 2;
        }
        if ( array[ mid ] == 0 || array[ mid ] == 1 )
            last_one_Or_zero = mid;
        else if ( array[ 0 ] != 0 && array[ 0 ] != 1 )
            last_one_Or_zero = last_Minus_Index;
        else
            last_one_Or_zero = mid - 1;
        //printf("%d\n", last_one_Or_zero );
        
        
        // 음수의 개수가 홀수인 경우
        if ( ( last_Minus_Index + 1 ) % 2 == 1 )
        {
            int result = 0 ;
            
            // 우선 음수인 부부은 2개씩 짝을 지어 곱한다.
            for ( int now_Index = 0 ; now_Index < last_Minus_Index - 1 ; now_Index += 2 )
            {
                result += ( array[ now_Index ] * array[ now_Index + 1 ] );
            }
            
            // 음수 하나 남는 것을 array[ last_Minus_Index + 1 ] != 0 인경우 array[ last_Minus_Index ]를 더한다.
            if ( array[ last_Minus_Index + 1 ] != 0 )
                result += array[ last_Minus_Index ];
            
            
            // 다음은 양수 차례로
            // 1 혹은 0 중 제일 뒤의 수 뒷편을 인덱스가 가장 높은 것 2개씩 짝지어 곱한 후 만약 하나가 남는다면 더해버린다.
            for ( int now_Index = N - 1 ; now_Index > last_one_Or_zero + 1 ; now_Index-=2 )
            {
                result += ( array[ now_Index ] * array[ now_Index - 1 ] );
            }
            
            if ( ( N - last_one_Or_zero + 1 ) % 2 == 1 && last_one_Or_zero != N )
                result += array[ last_one_Or_zero + 1 ];
            
            // 남아있는 0과 1은 모두 더해버린다.
            for ( int now_Index = last_Minus_Index + 1 ; now_Index <= last_one_Or_zero ; now_Index++ )
                result += array[ now_Index ];
            
            
            printf("%d", result ); 
        }
        
        // 음수의 개수가 짝수인 경우
        else
        {
            int result = 0 ;
            
            // 우선 음수인 부부은 2개씩 짝을 지어 곱한다.
            for ( int now_Index = 0 ; now_Index < last_Minus_Index ; now_Index += 2 )
            {
                result += ( array[ now_Index ] * array[ now_Index + 1 ] );
            }
            
            // 다음은 양수 차례로
            // 1 혹은 0 중 제일 뒤의 수 뒷편을 인덱스가 가장 높은 것 2개씩 짝지어 곱한 후 만약 하나가 남는다면 더해버린다.
            for ( int now_Index = N - 1 ; now_Index > last_one_Or_zero + 1 ; now_Index-=2 )
            {
                result += ( array[ now_Index ] * array[ now_Index - 1 ] );
            }
            
            if ( ( N - last_one_Or_zero + 1 ) % 2 == 1 && last_one_Or_zero != N )
                result += array[ last_one_Or_zero + 1 ];
              
            // 남아있는 0과 1은 모두 더해버린다.
            for ( int now_Index = last_Minus_Index + 1 ; now_Index <= last_one_Or_zero ; now_Index++ )
                result += array[ now_Index ];
            
            
            printf("%d", result );
        }
        
    }
    
    
    
    return 0;
}