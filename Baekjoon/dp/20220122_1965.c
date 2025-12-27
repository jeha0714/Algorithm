#include <stdio.h>

int main()
{
    // 상자의 개수 num_Box
    int num_Box; scanf("%d", &num_Box );
    
    // num_Box개수의 상자의 크기를 저장한 배열
    int box_Size[ num_Box ];
    for (int i = 0 ; i < num_Box ; i++)
        scanf("%d", &box_Size[ i ] );
    
    // 각 인덱스까지 도달 했을 때 넣을 수 있는 박스의 수의 최대값.
    int index_Max[ num_Box ];
    
    
    // 이중 for문 시간복잡도 O(n^2)를 사용
    // 해당 인덱스 전까지 돌면서 자기보다 값이 작으면서 담아넣은 박스 최대 개수를 찾아서 저장.
    for (int i = 0 ; i < num_Box ; i++ )
    {
        // index_Max[ i ] = 1 으로 초기값 설정
        index_Max[ i ] = 1;
        
        for (int j = 0 ; j < i ; j++ )
        {
            if ( box_Size[ j ] < box_Size[ i ]  &&  index_Max[ j ] >= index_Max[ i ] )
                index_Max[ i ] = index_Max[ j ] + 1;
        }
        
    }
    
    // index_Max 배열 값중 가장 큰 값을 찾는다.
    int find_Max = 0;
    for (int i = 0 ; i < num_Box ; i++ )
    {
        if ( find_Max < index_Max[ i ] )
            find_Max = index_Max[ i ];
    }
    
    printf("%d", find_Max );
    

    return 0;
}
