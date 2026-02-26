#include <stdio.h>
#include <math.h>

int main() {
    
    int test_Case; // 테스트케이스의 개수
    scanf("%d", &test_Case);
    
    for ( int num_Try = 0; num_Try < test_Case; num_Try++ )
    {
        int start_X, start_Y, end_X, end_Y; //시작점과 도착지점의 좌표
        int planet_Num; //행성계의 개수
        int result = 0; // 최소의 행성계 진입 이탈 횟수
        
        scanf("%d %d %d %d", &start_X, &start_Y, &end_X, &end_Y);
        scanf("%d", &planet_Num);
        
        //행성의 좌표와 반지름을 입력받기.
        for (int i = 0 ; i < planet_Num; i++)
        {
            int planet_X, planet_Y, planet_R;
            double length_with_Start, length_with_End;
            
            scanf("%d %d %d", &planet_X, &planet_Y, &planet_R);
            
            length_with_Start = sqrt( pow(start_X - planet_X, 2) + pow(start_Y - planet_Y, 2) );
            length_with_End = sqrt( pow(end_X - planet_X, 2) + pow(end_Y - planet_Y, 2) );
            
            
            // 출발점과 도착점이 행성 내부에 존재할 때
            if ( planet_R > length_with_Start && planet_R > length_with_End )
            {
                continue;
            }
            
            // 출발점이 행성 내부에 있고 도착점이 행성 외부에 존재할 때
            else if ( planet_R > length_with_Start && planet_R < length_with_End )
            {
                result++;
            }
            
            // 출발점은 행성 외부에 있고 도착점이 행성 내부에 존재할 때
            else if ( planet_R < length_with_Start && planet_R > length_with_End )
            {
                result++;
            }
            
            // 출발점 도착점 모두 행성 외부에 있을 때
            else if ( planet_R < length_with_Start && planet_R < length_with_End )
            {
                continue;
            }
            
        }
        
        printf("%d\n", result);
    }
    
    
    
    
    
    return 0;
}