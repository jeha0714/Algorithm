#include <stdio.h>
#include <math.h>

const long double PI = 3.14159265358979;

int main()
{
    // 두 원의 중심과 각각의 반지름이 주어짐.
    long double x1, y1, r1, x2, y2, r2; 
    scanf("%Lf %Lf %Lf %Lf %Lf %Lf", &x1, &y1, &r1, &x2, &y2, &r2);

    // 두 원의 중심간의 거리
    long double each_center_Len = sqrt( (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1) ) ;
    
    // 두 원의 거리가 반지름 합보다 크거나 같을 경우
    if ( each_center_Len >= r1 + r2  )
    {
        printf("0.000");
    }
    
    // 두 원의 거리가 반지름 합보다 작을 경우
    else
    {
        // 큰 원이 작은 원을 삼킨 경우
        if ( ( r1 >= each_center_Len + r2 ) || ( r2 >= each_center_Len + r1 ) )
        {
            if ( r1 > r2 )
            {   
                // 원의 넓이 구하기
                long double result = r2 * r2 * PI;
                
                // 원의 넓이를 소수점 셋째자리에서 반올림
                result = round( result * 1000.0 ) / 1000.0;
                
                // 결과값 출력
                printf("%.3Lf", result );
            }
            else
            {
                // 원의 넓이 구하기
                long double result = r1 * r1 * PI;
                
                // 원의 넓이를 소수점 셋째자리에서 반올림
                result = round( result * 1000.0 ) / 1000.0;
                
                // 결과값 출력
                printf("%.3Lf", result );
            }
            
        }
        
        // 두개의 원이 같은 위치 같은 크기인 경우
        else if ( x1 == x2 && y1 == y2 )
        {
            // 두 원중 하나의 원의 넓이 구하기
            long double result = r2 * r2 * PI;
                
            // 원의 넓이를 소수점 셋째자리에서 반올림
            result = round( result * 1000.0 ) / 1000.0;
                
            // 결과값 출력
            printf("%.3Lf", result );
        }
        
        // 교차하는 영역이 서로 생기는 경우
        else
        {
            // 교차하는 점중 하나를 중심 두개와 이어 만든 삼각형에서의 중심좌표에서 만들어지는 각 원의 각도
            long double c1_Angle = acosl( ( r1*r1 + each_center_Len*each_center_Len - r2*r2 ) / ( 2.0 * r1 * each_center_Len ) );
            long double c2_Angle = acosl( ( r2*r2 + each_center_Len*each_center_Len - r1*r1 ) / ( 2.0 * r2 * each_center_Len ) );
            
            // 위에서 만들어진 삼각형을 두 중심을 밑변으로 한 경우의 높이
            long double h = r1 * sinl( c1_Angle );
            
            // 교차하는 영역의 넓이
            long double result = r1*r1*c1_Angle + r2*r2*c2_Angle - h*each_center_Len;
            
            // 교차 영역을 소수점 셋째자리에서 반올림
            result = round( result * 1000.0 ) / 1000.0;
            
            //결과값 출력
            printf("%.3Lf", result );

        }
        
    }
    return 0;
}