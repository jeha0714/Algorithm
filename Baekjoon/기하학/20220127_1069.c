#include <stdio.h>
#include <math.h>


// 주어진 세 수중 가장 작은 값을 찾는 함수
long double find_min ( long double num1, long double num2, long double num3 )
{
    long double result;
    
    if ( num1 < num2 )
    {
        if ( num1 < num3 )
            result = num1;
        else
            result = num3;
    }
    
    else // (num1 >= num2)
    {
        if ( num2 < num3 )
            result = num2;
        else
            result = num3;
    }
    
    return result;
}



int main()
{
    // 은진이가 서 있는 좌표 (X,Y)와 T초에 D만큼 움직이는 점프할 경우의 값 등이 주어진다.
    int X, Y, D, T;
    
    while ( scanf("%d %d %d %d", &X, &Y, &D, &T) != EOF )
    {
        // (X,Y)에서 원점까지의 거리
        long double len_with_O = sqrt( X*X + Y*Y );
        
        // 같은 시간 동안 점프한 거리보다 걸어간 거리가 긴 경우
        if ( (long double)D / (long double)T <= 1.0 )
        {
            printf("%.13Lf", len_with_O );
        }
        
        // 같은 시간 동안 점프한 거리보다 걸어간 거리가 짧은 경우
        else
        {
            // 한 번 점프 할 때 len_with_O보다 작은 경우
            if ( len_with_O > (long double)D )
            {

                // len_with_O까지 덜 간 후 걸어간 경우
                long double fail_jump_walk = ( (long double)( (int)len_with_O / D * T ) + (long double)( len_with_O - (long double)( (int)len_with_O / D * D ) ) );
                    
                // len_with_O보다 더 간 후 되돌아 간 경우
                long double more_jump_walk = ( (long double)( ( (int)len_with_O / D + 1 ) * T ) + ( (long double)( ( (int)len_with_O / D + 1 ) * D ) ) - len_with_O ); 
                    
                // len_with_O를 점프만 해서 간 경우
                long double only_jump = ( ( (int)len_with_O / D + 1 ) * T );
                    
                    
                long double result = find_min( fail_jump_walk, more_jump_walk, only_jump );
                printf("%.13Lf", result );
                
            }
            
            // 한 번 점프 할 때 len_with_O와 같은 경우
            else if ( len_with_O == (long double)D )
            {
                printf("%d.0", T ); //
            }
            
            // 한 번 점프 할 때 len_with_O보다 큰 경우
            else if ( len_with_O < (long double)D )
            {
                // 점프 두 번 한 경우
                long double twice_jump = (long double )T * 2;
                
                // 오로지 걸었을 때보다 한번 점프하고 되돌아 걸어간 경우
                long double more_jump_walk = (long double)T + (long double) D - len_with_O;


                long double result = find_min( twice_jump, more_jump_walk, len_with_O );
                printf("%.13Lf", result );
                
            }
            
        }
        
    }
    
    
    return 0;
}