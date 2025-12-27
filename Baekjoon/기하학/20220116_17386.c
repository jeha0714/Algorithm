#include <stdio.h>
#include <math.h>

int main()
{
    // 두 선분을 이루는 양 끝 점 4개가 주어짐.
    int x1,x2,x3,x4,y1,y2,y3,y4;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2 );
    scanf("%d %d %d %d", &x3, &y3, &x4, &y4 );

    
    /* 선분이 아닌 직선인 경우 기울기 같지 않다면 무조건 교차점이 발생한다. */
    
    // L1, L2의 기울기를 각각 구한다.
    double L1_Inclination = (double)( y2 - y1 ) / (double)( x2 - x1 );
    double L2_Inclination = (double)( y4 - y3 ) / (double)( x4 - x3 );
    
    
    // 기울기가 없는 x=0, x=3 같은 경우
    if ( x2 - x1 == 0 || x4 - x3 == 0 )
    {
        // 두 선분이 모두 x = a 와 같은 기울기가 없는 경우
        if ( x2 - x1 == 0 && x4 - x3 == 0 )
        {
            // x = a 의 a값이 서로 다른 경우
            if ( x1 != x3 )
                printf("0");
                
            // 같은 경우
            else
            {
                // 특정 y값이 다른 선분 사이에 있는지 확인하면 된다.
                
                int L1_small_Y = y1 < y2 ? y1 : y2;
                int L1_big_Y = y1 < y2 ? y2 : y1;
                
                if ( ( L1_small_Y <= y3 && y3 <= L1_big_Y ) || ( L1_small_Y <= y4 && y4 <= L1_big_Y ) )
                    printf("1");
                else
                    printf("0");
            }
        }
        
        // 둘 중 하나의 선분만이 기울기가 없는 경우
        else
        {
            // 우선 기울기가 없는 x값이 기울기가 있는 선분 사이에 포함되는지 여부를 확인
            // 포함안된다면 겹치지 않으며
            // 포함된다면 각각 직선이라 생각하고 기울기가 있는 선분을 중심으로 교점을 구한다.
            // 이후 그 교점의 y좌표가 기울기가 없는 선분에 포함되는지 여부를 확인.
            
            if ( x2 - x1 == 0 )
            {
                int L2_small_X = x3 < x4 ? x3 : x4;
                int L2_big_X = x3 < x4 ? x4 : x3;
                
                int L1_small_Y = y1 < y2 ? y1 : y2;
                int L1_big_Y = y1 < y2 ? y2 : y1;
                
                
                double L2_C = (double)y3 - L2_Inclination * (double)x3;
                double cross_Spot_Y = L2_Inclination * x1 + L2_C;
                
                
                if ( ( L2_small_X <= x1 && x1 <= L2_big_X ) && 
                    ( (double)L1_small_Y <= cross_Spot_Y && cross_Spot_Y <= (double)L1_big_Y )  )
                    printf("1");
                else
                    printf("0");
            }
            
            else
            {
                int L1_small_X = x1 < x2 ? x1 : x2;
                int L1_big_X = x1 < x2 ? x2 : x1;
                
                int L2_small_Y = y3 < y4 ? y3 : y4;
                int L2_big_Y = y3 < y4 ? y4 : y3;
                
                
                double L1_C = (double)y1 - L1_Inclination * (double)x1;
                double cross_Spot_Y = L1_Inclination * x1 + L1_C;
                
                
                if ( ( L1_small_X <= x3 && x3 <= L1_big_X ) && 
                    ( (double)L2_small_Y <= cross_Spot_Y && cross_Spot_Y <= (double)L2_big_Y )  )
                    printf("1");
                else
                    printf("0");
            }
            
        }
        
    }
    
    
    // 기울기가 같은 경우
    else if ( L1_Inclination == L2_Inclination )
    {
        // 한 선분 위에 양 끝점이 존재한다면 선분은 교차한다고 볼 수 있다.
        int L1_small_X = x1 < x2 ? x1 : x2;
        int L1_big_X = x1 < x2 ? x2 : x1;
        
        int L1_small_Y = y1 < y2 ? y1 : y2;
        int L1_big_Y = y1 < y2 ? y2 : y1;
        
        
        if ( ( ( L1_small_X <= x3 && x3 <= L1_big_X ) && ( L1_small_Y <= y3 && y3 <= L1_big_Y ) ) || 
        ( ( L1_small_X <= x4 && x4 <= L1_big_X ) && ( L1_small_Y <= y4 && y4 <= L1_big_Y ) ) )
            printf("1");
        else
            printf("0");
        
    }
    
    // 기울기가 다른 경우
    else
    {
        //직선이라면 무조건 교차점이 발생하지만 선분이기에 교차점이 생길수도 안생길수도 있다.
        // 직선이라 가정하고 일차방적식 풀이를 통해 교차점을 구하고 
        //그 교차점이 L1, L2 선분 사이에 있으면 교차점이 생긴다고 판단.
        
        // 일차방정식의 상수값
        double L1_C = (double)y1 - L1_Inclination * (double)x1;
        double L2_C = (double)y3 - L2_Inclination * (double)x3;
        
        // 기울기가 큰 값을 찾음
        long double big_Inclination = L1_Inclination < L2_Inclination ? L2_Inclination : L1_Inclination;

        
        if ( big_Inclination == L1_Inclination )
        {
            // 직선이라 생각하고 교차점을 구한다.
            double cross_Spot_X = ( L2_C - L1_C ) / ( L1_Inclination - L2_Inclination );
            double cross_Spot_Y = L1_Inclination * cross_Spot_X + L1_C;
            int beside = 0;
            
            
            // L1 선분위에 교차점이 있는지 파악한다.
            int L1_small_X = x1 < x2 ? x1 : x2;
            int L1_big_X = x1 < x2 ? x2 : x1;
            
            int L1_small_Y = y1 < y2 ? y1 : y2;
            int L1_big_Y = y1 < y2 ? y2 : y1;
            
            
            if ( ( (double)L1_small_X <= cross_Spot_X && cross_Spot_X <= (double)L1_big_X ) && 
            ( (double)L1_small_Y <= cross_Spot_Y && cross_Spot_Y <= (double)L1_big_Y ) )
                beside++;


            // L2 선분위에 교차점이 있는지 파악한다.
            int L2_small_X = x3 < x4 ? x3 : x4;
            int L2_big_X = x3 < x4 ? x4 : x3;
            
            int L2_small_Y = y3 < y4 ? y3 : y4;
            int L2_big_Y = y3 < y4 ? y4 : y3;
            
            
            if ( ( (double)L2_small_X <= cross_Spot_X && cross_Spot_X <= (double)L2_big_X ) && 
            ( (double)L2_small_Y <= cross_Spot_Y && cross_Spot_Y <= (double)L2_big_Y ) )
                beside++;
            
            
            // 교차점이 두 선분 위에 모두 있다면 (beside == 2) 교차한다.
            if ( beside == 2 )
                printf("1");
            else
                printf("0");
            
        }
        
        else if ( big_Inclination == L2_Inclination )
        {
            // 직선이라 생각하고 교차점을 구한다.
            double cross_Spot_X = ( L1_C - L2_C ) / ( L2_Inclination - L1_Inclination );
            double cross_Spot_Y = L1_Inclination * cross_Spot_X + L1_C;
            int beside = 0;
            
            
            // L1 선분위에 교차점이 있는지 파악한다.
            int L1_small_X = x1 < x2 ? x1 : x2;
            int L1_big_X = x1 < x2 ? x2 : x1;
            
            int L1_small_Y = y1 < y2 ? y1 : y2;
            int L1_big_Y = y1 < y2 ? y2 : y1;
            
            
            if ( ( (double)L1_small_X <= cross_Spot_X && cross_Spot_X <= (double)L1_big_X ) && 
            ( (double)L1_small_Y <= cross_Spot_Y && cross_Spot_Y <= (double)L1_big_Y ) )
                beside++;


            // L2 선분위에 교차점이 있는지 파악한다.
            int L2_small_X = x3 < x4 ? x3 : x4;
            int L2_big_X = x3 < x4 ? x4 : x3;
            
            int L2_small_Y = y3 < y4 ? y3 : y4;
            int L2_big_Y = y3 < y4 ? y4 : y3;
            
            
            if ( ( (double)L2_small_X <= cross_Spot_X && cross_Spot_X <= (double)L2_big_X ) && 
            ( (double) L2_small_Y <= cross_Spot_Y && cross_Spot_Y <= (double)L2_big_Y ) )
                beside++;
            
            
            // 교차점이 두 선분 위에 모두 있다면 (beside == 2) 교차한다.
            if ( beside == 2 )
                printf("1");
            else
                printf("0");
            

        }

        
    }
    
    
    return 0;
}
