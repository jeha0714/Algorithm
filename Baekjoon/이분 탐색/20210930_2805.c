#include <stdio.h>

long long result = 0;


// Mid값으로 주어진 나무들을 잘랐을 경우 절단된 나무의 길이를 반환하는 함수
long long Calculate( int Mid, int array_Wood_Length[], int num_Wood )
{
    long long bring_Wood = 0;
    
    for (int now_Index = 0; now_Index < num_Wood ; now_Index++)
    {
        if ( array_Wood_Length[ now_Index ] > Mid )
            bring_Wood += ( array_Wood_Length[ now_Index ] - Mid ); 
    }
    
    
    return bring_Wood;
}


// 이분탐색을 통해 적절한 절단기에 설정하는 높이를 구하는 함수
void BNS ( int num_Wood, int array_Wood_Length[], int bring_Wood, int max )
{
    int Start = 0;
    int End = max;
    
    while( Start <= End )
    {
        int Mid = ( Start + End )/2;

        if ( Calculate( Mid, array_Wood_Length, num_Wood ) >= bring_Wood && Calculate( Mid + 1, array_Wood_Length, num_Wood ) < bring_Wood )
        {
            result = Mid;
            break;
        }   
        
        else if ( Calculate( Mid, array_Wood_Length, num_Wood ) > bring_Wood )
            Start = Mid + 1;
        
        else if ( Calculate( Mid, array_Wood_Length, num_Wood ) < bring_Wood )
            End = Mid - 1;
        
        else if ( Calculate( Mid, array_Wood_Length, num_Wood ) == bring_Wood )
            Start = Mid + 1;
        
    }
    
}




int main() {
    
    int num_Wood, bring_Wood; // 나무의 수와 챙겨가려하는 나무의 길이
    scanf("%d %d", &num_Wood, &bring_Wood );
    
    int array_Wood_Length[ num_Wood ]; // num_Wood개의 나무의 길이가 저장될 배열
    int most_Long_Wood = 0; // 길이가 가장 긴 나무토막을 저장한 변수
    for (int i = 0 ; i < num_Wood ; i++ ) 
    { 
        scanf("%d", &array_Wood_Length[ i ] ); 
        if ( i == 0 ) most_Long_Wood = array_Wood_Length[0];
        else if ( most_Long_Wood < array_Wood_Length[ i ] )
            most_Long_Wood = array_Wood_Length[ i ];
    }
    
    BNS( num_Wood, array_Wood_Length, bring_Wood, most_Long_Wood);
    
    
    printf("%lld", result);
    
    return 0;
}