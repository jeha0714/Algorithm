#include <stdio.h>
#include <math.h>

int main()
{
    // 3개의 점의 좌표가 주어짐. 0열은 x좌표 1열은 y좌표
    long double spots[ 3 ][2];
    for (int i = 0 ; i < 3 ; i++ )
        scanf("%Lf %Lf", &spots[ i ][0], &spots[ i ][1] );

    
    /* 두번째 점이 첫번째 점보다 왼쪽에 있는 경우 */
    if ( spots[1][0] < spots[0][0] )
    {
        // 1,2 번째 점으로 이루어진 선을 이루는 함수를 구함 ( 기울기와 상수 )
        long double inclination = ( spots[1][1] - spots[0][1] ) / ( spots[1][0] - spots[0][0] );
        long double C = spots[0][1] - inclination * spots[0][0];
        
        // 함수에 세번째 점 x좌표( spots[2][0] )을 대입했을 때 나오는 값
        long double line_Y = inclination * spots[2][0] + C;
        
        // 세번째 점의 y좌표가 line_Y값보다 클 경우
        if ( round( spots[2][1] ) > round( line_Y ) )
            printf("-1");
        
        // 세번째 점의 y좌표가 line_Y값보다 작을 경우
        else if ( round( spots[2][1] ) < round( line_Y ) )
            printf("1");
            
        // line_Y와 세번째 점의 y가 같아 일직선인 경우 
        else //(double)spots[2][1] == line_Y
            printf("0");
        
    }
    
    /* 두번째 점이 첫번째 점보다 오른쪽에 있는 경우 */
    else if ( spots[1][0] > spots[0][0] )
    {
        // 1,2 번째 점으로 이루어진 선을 이루는 함수를 구함 ( 기울기와 상수 
        
        long double inclination = ( spots[1][1] - spots[0][1] ) / ( spots[1][0] - spots[0][0] );
        long double C = spots[0][1] - inclination * spots[0][0];
        
        // 함수에 세번째 점 x좌표( spots[2][0] )을 대입했을 때 나오는 값
        long double line_Y = inclination * spots[2][0] + C;
        
        // 세번째 점의 y좌표가 line_Y값보다 클 경우
        if ( round( spots[2][1] ) > round( line_Y ) )
            printf("1");
        
        // 세번째 점의 y좌표가 line_Y값보다 작을 경우
        else if ( round( spots[2][1] ) < round( line_Y ) )
            printf("-1");
            
        // line_Y와 세번째 점의 y가 같아 일직선인 경우 
        else //(double)spots[2][1] == line_Y
            printf("0");
    }
    
    
    /* 첫번째 점과 두번째 점이 y축 값이 동일 한 경우 */
    else // spots[1][0] == spots[0][0]
    {
        
        // 세번째 점 또한 x축 값이 동일한 경우 일직선인 경우
        if ( spots[2][0] == spots[1][0] )
            printf("0");
        
        // 두번째 점이 첫번째 점보다 위에 있는 경우
        else if ( spots[1][1] > spots[0][1] )
        {
            // 세번째 점이 연장 선의 왼쪽에 있는 경우
            if ( spots[2][0] < spots[0][0] )
                printf("1");
            
            // 세번째 점이 연장 선의 오른쪽에 있는 경우
            else if ( spots[2][0] > spots[0][0] )
                printf("-1");
            
        }
        
        // 두번째 점이 첫번째 점보다 아래에 있는 경우
        else if ( spots[1][1] < spots[0][1] )
        {
            // 세번째 점이 연장 선의 왼쪽에 있는 경우
            if ( spots[2][0] < spots[0][0] )
                printf("-1");
            
            // 세번째 점이 연장 선의 오른쪽에 있는 경우
            else if ( spots[2][0] > spots[0][0] )
                printf("1");
        }
        
    }
    

    return 0;
}
