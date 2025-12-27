#include <stdio.h>


// 외적을 통한 세점의 위치 관계를 알아본다.
int CCW ( int main_x1, int main_y1, int main_x2, int main_y2, int main_x3, int main_y3 )
{
    long long result1 = (long long)( main_x1 - main_x2 ) * (long long)( main_y1 - main_y3 );
    long long result2 = (long long)( main_y1 - main_y2 ) * (long long)( main_x1 - main_x3 );

    if ( result1 - result2 > 0 )
        return 1;
    else if ( result1 - result2 == 0 )
        return 0;
    else if ( result1 - result2 < 0 )
        return -1;

    return -2;
}



int main()
{
    // 두 선분을 이루는 양 끝 점 4개가 주어짐.
    int x1,x2,x3,x4,y1,y2,y3,y4;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2 );
    scanf("%d %d %d %d", &x3, &y3, &x4, &y4 );


    // L1을 이루는 양 끝 선분과 L2를 이루는 양 끝 선분의 외적으로 인한 값을 구한다.
    int L2_first_spot_Relation = CCW( x1, y1, x2, y2, x3, y3 );
    int L2_second_spot_Relation = CCW( x1, y1, x2, y2, x4, y4 );


    /* L2를 이루는 두점이 각각 L1과 위치관계가 같은 경우 */
    if ( L2_first_spot_Relation == L2_second_spot_Relation )
    {

        // 이 경우는 L1, L2의 교차점이 없는 경우이다.
        if ( L2_first_spot_Relation == 1 || L2_first_spot_Relation == -1 )
        {
            printf("0");
        }

        // 이 경우는 L1, L2이 한직선 위에 두 선분이 존재한다.
        else if ( L2_first_spot_Relation == 0 )
        {
            int L1_big_X = x1 < x2 ? x2 : x1;
            int L1_small_X = x1 < x2 ? x1 : x2;
            int L1_big_Y = y1 < y2 ? y2 : y1;
            int L1_small_Y = y1 < y2 ? y1 : y2;

            int L2_big_X = x3 < x4 ? x4 : x3;
            int L2_small_X = x3 < x4 ? x3 : x4;
            int L2_big_Y = y3 < y4 ? y4 : y3;
            int L2_small_Y = y3 < y4 ? y3 : y4;


            // L1을 이루는 양 끝점 내부에 L2를 이루는 양 끝점 중 하나가 포함된다면 교차한다.
            if ( ( ( ( L1_small_X <= x3 && x3 <= L1_big_X ) && ( L1_small_Y <= y3 && y3 <= L1_big_Y ) ) || 
                ( ( L1_small_X <= x4 && x4 <= L1_big_X ) && ( L1_small_Y <= y4 && y4 <= L1_big_Y ) ) ) ||
                ( ( ( L2_small_X <= x1 && x1 <= L2_big_X ) && ( L2_small_Y <= y1 && y1 <= L2_big_Y ) ) || 
                ( ( L2_small_X <= x2 && x2 <= L2_big_X ) && ( L2_small_Y <= y2 && y2 <= L2_big_Y ) ) ) )
            {
                printf("1\n");
                
                // 교차점이 하나인 경우
                // 한 점만 좌표값이 일치하며 나머지 한점은 외부에 있는 것
                
                if ( ( ( x1 == x3 ) && ( y1 == y3 ) ) && ( ( x2 != x4 ) || ( y2 != y4 ) ) ) 
                {
                    if ( ( ( L1_small_X <= x4 && x4 <= L1_big_X ) && ( L1_small_Y <= y4 && y4 <= L1_big_Y ) ) || 
                        ( ( L2_small_X <= x2 && x2 <= L2_big_X ) && ( L2_small_Y <= y2 && y2 <= L2_big_Y ) ) )
                        return 0;
                    else
                        printf("%d %d", x3, y3);
                }
                else if ( ( ( x2 == x3 ) && ( y2 == y3 ) ) && ( ( x1 != x4 ) || ( y1 != y4 ) ) )
                {
                    if ( ( ( L1_small_X <= x4 && x4 <= L1_big_X ) && ( L1_small_Y <= y4 && y4 <= L1_big_Y ) ) || 
                        ( ( L2_small_X <= x1 && x1 <= L2_big_X ) && ( L2_small_Y <= y1 && y1 <= L2_big_Y ) ) )
                        return 0;
                    else
                        printf("%d %d", x3, y3);
                }
                
                
                else if ( ( ( x1 != x3 ) || ( y1 != y3 ) ) && ( ( x2 == x4 ) && ( y2 == y4 ) ) )
                {
                    if ( ( ( L1_small_X <= x3 && x3 <= L1_big_X ) && ( L1_small_Y <= y3 && y3 <= L1_big_Y ) ) || 
                        ( ( L2_small_X <= x1 && x1 <= L2_big_X ) && ( L2_small_Y <= y1 && y1 <= L2_big_Y ) ) )
                        return 0;
                    else
                        printf("%d %d", x4, y4);
                }
                else if ( ( ( x2 != x3 ) || ( y2 != y3 ) ) && ( ( x1 == x4 ) && ( y1 == y4 ) ) )
                {
                    if ( ( ( L1_small_X <= x3 && x3 <= L1_big_X ) && ( L1_small_Y <= y3 && y3 <= L1_big_Y ) ) || 
                        ( ( L2_small_X <= x2 && x2 <= L2_big_X ) && ( L2_small_Y <= y2 && y2 <= L2_big_Y ) ) )
                        return 0;
                    else
                        printf("%d %d", x4, y4);
                }
                
                
            }
            else
                printf("0");

        }

    }

    /* L2를 이루는 두점이 각각 L1과 위치관계가 다른 경우 */
    else
    {

        // 이 경우는 L1, L2의 교차점이 생길 수도 안 생길 수 도 있다.
        if ( L2_first_spot_Relation != 0 && L2_second_spot_Relation != 0 )
        {
            // L2을 이루는 양 끝 선분과 L1를 이루는 양 끝 선분의 외적으로 인한 값을 구한다.
            int L1_first_spot_Relation = CCW( x3, y3, x4, y4, x1, y1 );
            int L1_second_spot_Relation = CCW( x3, y3, x4, y4, x2, y2 );

            // L2를 기준으로 한 L1의 양 끝점 관계의 값이 다르다면 교차점이 발생한다.
            if ( L1_first_spot_Relation != L1_second_spot_Relation )
            {
                printf("1\n");
                
                
                // 직선의 방정식을 이용해서 교점을 구한다.
                
                // 우선 각 선분의 기울기를 구한다.
                // 기울기가 없는 경우와 둘 다 있는 경우를 구분한다.
                if ( x2 == x1 )
                {
                    long double L2_Inclination = (long double)( y4 - y3 ) / (long double)( x4 - x3 );
                    long double L2_C = (long double)y3 - L2_Inclination * (long double)x3;
                    
                    long double spot_Y = L2_Inclination * (long double)x1 + L2_C;
                    
                    printf("%d %.16Lf", x1, spot_Y );
                    /*if ( spot_Y - (int)spot_Y >= 0.0000000000000001 )
                        printf("%d %.16Lf", x1, spot_Y );
                    else
                        printf("%d %d", x1, (int)spot_Y );*/
                }
                
                else if ( x4 == x3 )
                {
                    long double L1_Inclination = (long double)( y2 - y1 ) / (long double)( x2 - x1 );
                    long double L1_C = (long double)y1 - L1_Inclination * (long double)x1;
                    
                    long double spot_Y = L1_Inclination * (long double)x3 + L1_C;
                    
                    printf("%d %.16Lf", x3, spot_Y );
                    /*if ( spot_Y - (int)spot_Y >= 0.0000000000000001 )
                        printf("%d %.16Lf", x3, spot_Y );
                    else
                        printf("%d %d", x3, (int)spot_Y );*/
                }
                
                else
                {
                    long double L1_Inclination = (long double)( y2 - y1 ) / (long double)( x2 - x1 );
                    long double L2_Inclination = (long double)( y4 - y3 ) / (long double)( x4 - x3 );
                
                    long double L1_C = (long double)y1 - L1_Inclination * (long double)x1;
                    long double L2_C = (long double)y3 - L2_Inclination * (long double)x3;
                    
                    long double spot_X = ( L2_C - L1_C ) / ( L1_Inclination - L2_Inclination );
                    long double spot_Y = L1_Inclination * spot_X + L1_C;
                    
                    printf("%.16Lf %.16Lf", spot_X, spot_Y );
                    /*if ( ( spot_X - (int)spot_X >= 0.0000000000000001 ) && ( spot_Y - (int)spot_Y >= 0.0000000000000001 ) )
                        printf("%.16Lf %.16Lf", spot_X, spot_Y );
                    else if ( ( spot_X - (int)spot_X ) >= 0.0000000000000001 )
                        printf("%.16Lf %d", spot_X, (int)spot_Y ); //
                    else if ( ( spot_Y - (int)spot_Y ) >= 0.0000000000000001 )
                        printf("%d %.16Lf", (int)spot_X, spot_Y ); //
                    else
                        printf("%d %d", (int)spot_X, (int)spot_Y );*/
                }
                
            }
            else
                printf("0");

        }

        // 이 경우는 L2의 양 끝 점 중 하나만이 L1과 직선을 이룬다.
        else
        {
            int L1_big_X = x1 < x2 ? x2 : x1;
            int L1_small_X = x1 < x2 ? x1 : x2;

            // 우선 L1과 직선을 이루는 한 점을 찾고 그 점이 L1 내부에 있는지 외부에 있는지 판단한다.
            if ( L2_first_spot_Relation == 0 )
            {
                if ( L1_small_X <= x3 && x3 <= L1_big_X )
                {
                    printf("1\n");
                    printf("%d %d", x3, y3 );
                }
                else
                    printf("0");
            }

            else if ( L2_second_spot_Relation == 0 )
            {
                if ( L1_small_X <= x4 && x4 <= L1_big_X )
                {
                    printf("1\n");
                    printf("%d %d", x4, y4 );
                }
                else
                    printf("0");
            }

        }

    }


    return 0;
}