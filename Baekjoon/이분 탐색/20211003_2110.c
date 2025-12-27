#include <stdio.h>
#include <stdlib.h>


// qsort 오름차순 정렬을 위한 비교 함수
int compare( const void * first, const void * second )
{
    return *(int *)first - *(int *)second;
}


// 공유기의 수를 전부 사용하면서 공유기 사이의 now_Len 거리를 유지하는지 판단하는 함수
// 1을 반환 시 위의 조건을 모두 만족함 0을 반환 시 위의 조건 중 하나라도 만족을 못 한 경우
int BNS( int house_Location[] , int N, int C, int now_Len )
{
    int now_have_C = C - 2; // 현재 사용하고 남은 공유기의 수 양 끝을 미리 설치했다 생각해서 미리 -2함.
    int left = 0, right = N - 1; // 배열의 양 끝을 나타내는 인덱스를 나타내는 변수
    int last_C_Location = 0; // 바로 앞에 설치된 공유기의 위치.
    
    // 공유기를 다 설치하거나 left가 N -1 까지 갈때 까지 반복문 가동
    while ( now_have_C != 0 && left < N - 1 )
    {
        int mid = ( left + right ) / 2 ;
        
        // mid에 위치한 집이 마지막으로 설치한 공유기의 위치와 max_Len이상의 차이가 나며
        // mid - 1 에 위치한 집은 max_Len 미만의 값을 보일 때 
        // 그집에 공유기슬 설치 및 left = mid + 1 last_C_Location은 mid로 옮기고 right도 N - 1로 다시 옮겨준다.
        if (  house_Location[ mid ] - house_Location[ last_C_Location ] >= now_Len && house_Location[ mid - 1 ] - house_Location[ last_C_Location ] < now_Len)
        {
            now_have_C--; 
            left = mid + 1; 
            last_C_Location = mid; 
            right = N - 1; 
        }
        
        // mid 에 위치한 집이 가장 마지막으로 설치한 공유기의 위치와의 차이가 max_Len보다 작을 때 
        else if ( house_Location[ mid ] - house_Location[ last_C_Location ] < now_Len )
            left = mid + 1;
            
        else
            right = mid - 1;
        
    }
    
    
    if ( house_Location[ N - 1 ] - house_Location[ last_C_Location ] >= now_Len && now_have_C == 0 )
        return 1;
    else
        return 0;
}




int main() {
    
    int N, C; // 집의 개수 N 과 공유기 개수 C
    scanf("%d %d", &N, &C);
    
    int house_Location[ N ]; // 집의 위치를 저장한 배열
    for (int i = 0 ; i < N ; i++) { scanf("%d", &house_Location[ i ] ); }
    
    // 오름차순으로 정렬
    qsort ( house_Location, N, sizeof ( house_Location[ 0 ] ), compare );
    
    // len_Left는 공유기 사이의 최소 거리, len_Right는 공유기 사이의 최대 거리를 의미.
    int len_Left = 1, len_Right = ( house_Location[ N - 1 ] - house_Location[0] ) / ( C - 1 );
    
    
    // len_Mid를 이용한 이분탐색으로 len_Mid일 때는 1이 반환되고 len_Mid + 1일 때는 0 이 반환되는 경우를 출력
    while ( 1 )
    {
        int len_Mid = ( len_Left + len_Right ) / 2;
        
        // 다음과 같은 경우가 문제에 만족하는 경우
        if ( BNS( house_Location, N, C, len_Mid ) == 1 && BNS( house_Location, N, C, len_Mid + 1 ) == 0 )
        {
            printf("%d", len_Mid);
            break;
        }
        
        // 더 큰 len_Mid도 가능하다고 판단되는 경우
        else if ( BNS( house_Location, N, C, len_Mid ) == 1 && BNS( house_Location, N, C, len_Mid + 1 ) == 1 )
            len_Left = len_Mid + 1;
            
        // BNS가 len_Mid 일 때 0을 반환 한것으로 더 작은 len_Mid의 값이 대입되어야 함.
        else
            len_Right = len_Mid - 1;
        
    }
    
    
    
    return 0;
}