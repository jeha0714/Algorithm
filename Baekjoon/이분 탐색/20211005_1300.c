#include <stdio.h>


int BNS( int mid, int array_Size )
{
    int small_than_Me = 0; // mid이하인 수를 저장한 변수.
    
    // 2차원 배열에서 각 행마다 mid이하인 수를 small_than_Me에 더해준다.
    for (int Current_Size = array_Size ; Current_Size >= 1 ; Current_Size-- )
    {
        if ( array_Size < mid / Current_Size )
            small_than_Me += array_Size;
        
        else
            small_than_Me += ( mid / Current_Size );
        
    }
    
    
    return small_than_Me;
}



int main() {
    
    int array_Size; scanf("%d", &array_Size); // 배열의 크기 array_Size
    int find_K; scanf("%d", &find_K); // 배열 B의 find_K번째 수를 찾아야 함.
    int solution; // 문제의 해답을 저장한 변수
    
    int left = 1; 
    int right = (long long)array_Size * (long long)array_Size > 1000000000 ? 1000000000 : array_Size * array_Size;
    
    while ( left <= right )
    {
        int mid = ( left + right ) / 2;
        
        if ( BNS( mid, array_Size ) >= find_K  )
        {
            solution = mid;
            right = mid - 1;
        }
        
        else if ( BNS( mid, array_Size ) < find_K )
            left = mid + 1;

    }
    
    // 해답을 출력.
    printf("%d\n", solution);
    
    return 0;
}