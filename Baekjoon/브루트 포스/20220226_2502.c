#include <stdio.h>


int main()
{
    // 할머니가 넘어온 날과 그 날 호랑이에게 준 떡의 개수가 주어짐.
    int day, day_by_give_Ricecake; scanf("%d %d", &day, &day_by_give_Ricecake );
    
    
    
    // 첫 날 준 떡의 개수를 A 둘째 날 준 떡의 개수를 B라 한다면 
    // 셋째 날은 A + B, 넷째 날은 A + 2B, 그 다음은 2A + 3B, 3A + 5B, 5A + 8B ..... 로 나아간다.
    // 이때 해당되는 날짜의 A와 B의 계수를 구한다.
    
    
    
    // 기본적으로 할머니가 넘어온 날은 3이상이므로 초기 계수값은 1로 초기화 시킨다.
    int A_Coefficient = 1, B_Coefficient = 1;
    
    // 해당되는 날짜의 계수값이 설정되도록 반복문으로 계수값을 찾아준다.
    for ( int now_Day = 3; now_Day < day; now_Day++ )
    {
        int before_A_Coefficient = A_Coefficient;
        
        A_Coefficient = B_Coefficient;
        B_Coefficient += before_A_Coefficient;
    }

    // 계수값을 찾았다면 aA + bB = day_by_give_Ricecake 의 자연수 A와 B 값을 찾는다.
    for ( int find_A = 1 ; ; find_A++ )
    {
        // 당일날 호랑이에게 준 떡의 개수에서 A의 계수값과 A를 곱한 값을 빼고 남은 떡의 개수
        int left_Ricecake = day_by_give_Ricecake - A_Coefficient * find_A;
        
        // 남은 떡의 개수에서 B의 계수값을 나눌 때 나머지가 없다면 현재 반복문에 사용된 A,B를 출력 후 break
        if ( left_Ricecake % B_Coefficient == 0 )
        {
            printf("%d\n%d", find_A, left_Ricecake / B_Coefficient );
            break;
        }
    }
    
    
    
    return 0;
}
