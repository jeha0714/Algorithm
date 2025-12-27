#include <stdio.h>


// 이분탐색을 통해 new_Num이 main_Array자리에 들어갈 위치를 저장
void LIS( int main_Array[], int array_End, int new_Num )
{
    int start = 0, end = array_End;
    int mid = ( start + end ) / 2;
    
    while ( start <= end )
    {
        if ( main_Array[ mid ] < new_Num )
            start = mid + 1;
        else if ( main_Array[ mid ] > new_Num )
            end = mid - 1;
        
        mid = ( start + end ) / 2;
    }
    
    // main_Array 인덱스 mid 값과 비교하며 new_Num을 적절한 위치에 삽입
    if ( main_Array[ mid ] < new_Num && main_Array[ mid + 1 ] > new_Num )
        main_Array[ mid + 1 ] = new_Num;
    else 
        main_Array[ mid ] = new_Num;

}



int main()
{
    // 총 책의 개수
    int num_Book; scanf("%d", &num_Book );
    
    // 책이 꽂혀있는 순서가 저장된 배열
    int book_Array[ num_Book ];
    for (int i = 0 ; i < num_Book ; i++)
        scanf("%d", &book_Array[ i ] );
    
    // 기존에 책정리가 되어있는 경우 중 가장 긴 경우를 저장한 배열
    int most_Long[ num_Book ]; 
    // 처음은 배열 내부를 전부 -1로 초기화 한 후 인덱스 0은 book_Array[0]으로 최초 설정.
    for (int i = 0 ; i < num_Book ; i++ )
        most_Long[ i ] = -1;
    most_Long[0] = book_Array[0];
    
    // most_Long 배열의 첫 -1의 인덱스를 나타내는 변수
    int index_most_Long = 1;
    
    
    // 이분탐색을 통한 가장 길게 정리된 경우를 찾는다.
    for (int i = 1 ; i < num_Book ; i++)
    {
        if ( most_Long[ index_most_Long - 1 ] < book_Array[ i ] )
            most_Long[ index_most_Long++ ] = book_Array[ i ];
        
        else
            LIS( most_Long, index_most_Long, book_Array[ i ] );
    }
    
    
    // 최소 횟수는 총 책의 개수에서 가장 길게 정리 된 경우를 빼면 된다.
    printf("%d", num_Book - index_most_Long );
    
    return 0;
}
