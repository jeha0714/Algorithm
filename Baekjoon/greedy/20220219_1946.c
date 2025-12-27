#include <stdio.h>
#include <stdlib.h>


// 첫번째 열 정렬 함수
int compare_Document( const void * first, const void * second )
{
    return *(int*)first - *(int*)second;
}


int main() {
    
    // 테스트 케이스의 수
    int test_Num; scanf("%d", &test_Num );
    
    
    for ( int now = 0 ; now < test_Num ; now++ )
    {
        // 지원자의 수
        int applicant; scanf( "%d", &applicant );
        
        // 1열은 서류성적 2열은 면접성적 저장
        int score[ applicant ][2];
        for(int i_PP = 0 ; i_PP < applicant ; i_PP++ )
            scanf("%d %d", &score[ i_PP ][ 0 ], &score[ i_PP ][ 1 ] );
        
        
        // 서류심사 순위을 오름차순으로 정렬
        qsort( score, applicant, sizeof(score[0]), compare_Document );
        
        
        // 통과한 사람들의 면접 순위가 저장되는 배열과 그 배열에 값을 저장하기 위해 비어있는 공간을 나타내는 인덱스
        int pass_PP[ applicant ], pass_PP_Index = 0;
        
        // pass_PP배열의 0번째 배열 값은 정렬된 score 첫번째 행의 면접점수 설정
        pass_PP[ pass_PP_Index++ ] = score[0][1];
        
        
        // 정렬된 score 배열을 1번째 사람부터 applicant - 1번째 사람까지 돌면서
        // pass_PP_Index - 1번째 사람의 면접 순위보다 score[i_PP]의 면접 순위가 높은 경우 저장해주는 식
        // pass_PP의 배열 내부는 증가하는 형태가 보일 수 있도록 해준다.
        for (int i_PP = 1 ; i_PP < applicant ; i_PP++ )
        {
            if ( pass_PP[ pass_PP_Index - 1 ] > score[ i_PP ][1] )
                pass_PP[ pass_PP_Index++ ] = score[ i_PP ][1];
        }
        
        // 결과를 출력
        printf("%d\n", pass_PP_Index );
    }
    
    
    return 0;
}