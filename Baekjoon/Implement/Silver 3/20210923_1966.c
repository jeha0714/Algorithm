#include <stdio.h>
#include <stdlib.h>

int compare(const void * first, const void * second )
{
    return *(int *)second - *(int *)first;
}



int main() {
    
    int test_Case;
    
    scanf("%d", &test_Case);
    
    for (int now_Try = 0 ; now_Try < test_Case ; now_Try++ )
    {
        int N, M; // 문서의 개수와 몇 번째로 인쇄되었는지 궁금한 문서
        scanf("%d %d", &N, &M);
        
        int array_Important[ N ]; // 중요도를 저장한 배열
        int array_Descending[ N ]; // 중요도를 내림차순으로 저장한 배열
        for (int now_Index = 0 ; now_Index < N; now_Index++) 
        { 
            scanf("%d", &array_Important[ now_Index ] ); 
            array_Descending[ now_Index ] = array_Important[ now_Index ];
        }
        
        qsort(array_Descending, N, sizeof( array_Descending[0] ), compare); // 내림차순으로 정렬
        int index_Important = 0; // 중요도 배열 내부 인덱스를 가리키는 변수
        
        for ( int index_Descending = 0; index_Descending < N ;  )
        {
            // array_Important의 인덱스에 해당하는 중요도가 가장 큰 경우.
            if ( array_Descending[ index_Descending ] == array_Important[ index_Important ] )
            {
                // M과 index_Important기 같은 경우
                if ( M == index_Important )
                {
                    // 결과 값을 출력후 반복문 종료. 다음 테스트 케이스 시작.
                    printf("%d\n", index_Descending + 1);
                    break;
                }
                
                // M과 index_Important기 다른 경우
                else if ( M != index_Important )
                {
                    // 중요도를 0으로 설정. ( 0으로 설정한다는 의미는 pop한 의미로 생각 )
                    array_Important[ index_Important ] = 0;
                    index_Descending++; // 내림차순으로 정렬한 배열의 다음 인덱스로 넘어감.
                    
                    if ( index_Important == N - 1) // 배열의 끝을 도달 시 처음으로 보내줌.
                    {
                        index_Important = 0;
                    }
                    
                    else // 중요도 배열의 인덱스를 +1
                    {
                        index_Important++;
                    }
                    
                }
                
            }
            
            else // array_Descending[ index_Descending ] != array_Important[ index_Important ]
            {
                if ( index_Important == N - 1) // 배열의 끝을 도달 시 처음으로 보내줌.
                {
                    index_Important = 0;
                }
                
                else // 중요도 배열의 인덱스를 +1
                {
                    index_Important++;
                }
                
            }
            
            
        }
        
        
    }
    
    
    
    return 0;
}