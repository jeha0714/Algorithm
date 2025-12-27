#include <stdio.h>

int result = 0;

// num은 함수에 주어진 수, how_many_Try는 num이 생성되기까지 함수가 몇 번 사용되었는지 알려주는 수.
void make_One( int num, int how_many_Try )
{
    if ( num == 1 )
        result = how_many_Try;
    
    else
    {
        // num이 3으로 나누어 떨어지는 경우
        if ( num % 3 == 0 )
        {
            // result에 저장된 값이 현재 진행중인 계산의 how_many_Try값보다 작거나 같은경우 그 진행은 취소.
            if ( result <= how_many_Try )
                return;
            else
                make_One( num / 3, how_many_Try + 1 );
        }
        
        // num이 2으로 나누어 떨어지는 경우
        if ( num % 2 == 0 )
        {
            // result에 저장된 값이 현재 진행중인 계산의 how_many_Try값보다 작거나 같은경우 그 진행은 취소.
            if ( result <= how_many_Try )
                return;
            else
                make_One( num / 2, how_many_Try + 1 );
        }
        
        // -1을 하는 경우
        // result에 저장된 값이 현재 진행중인 계산의 how_many_Try값보다 작거나 같은경우 그 진행은 취소.
        if ( result <= how_many_Try )
            return;
        else
            make_One( num - 1, how_many_Try + 1 );
        
    }
    
}


int main(void)
{
    int num; scanf("%d", &num); // 1로 만드려는 수.
    result = num - 1; // -1로만 진행된 경우.
    
    make_One( num, 0 );
    
    printf("%d", result);
    
    return 0;
}