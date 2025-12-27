#include <stdio.h>
#include <math.h>

// 트리에 해당하는 num노드의 깊이를 반환하는 함수
int find_Depth ( int num )
{
    int num_Depth;
    
    num_Depth = log2( num );
    
    return num_Depth;
}

// 두 개의 노드의 깊이를 같게 만들어주면서 값도 부모노드로 이동시키는 함수
void make_same_Depth( int * A, int * A_Depth, int * B, int * B_Depth )
{
    if ( *A_Depth > *B_Depth )
    {
        int distance_Depth = *A_Depth - *B_Depth;
        
        *A = (int)( *A / pow(2, *A_Depth - *B_Depth) );
        
        *A_Depth = *A_Depth - distance_Depth;
    }
    
    else if ( *A_Depth < *B_Depth )
    {
        int distance_Depth = *B_Depth - *A_Depth;
        
        *B = (int)( *B / pow(2, *B_Depth - *A_Depth) ) ;
        
        *B_Depth = *B_Depth - distance_Depth;
    }
    
    else
        return;
    
}



int main() 
{
    int test_Case;
    scanf("%d", &test_Case);
    
    for (int now_Try = 0 ; now_Try < test_Case ; now_Try++)
    {
        int A, B;
        int A_Depth, B_Depth;
        
        scanf("%d %d", &A, &B);
        
        // 1. 각각의 수의 깊이를 구한다.
        A_Depth = find_Depth( A );
        B_Depth = find_Depth( B );
        
        // 2. 트리의 깊이를 맞추어준다
        make_same_Depth( &A, &A_Depth, &B, &B_Depth );
        
        // 3. depth를 맞춘 이후 두 수의 값이 같을 때 까지 /2 해준다.
        while ( A != B )
        {   
            A /= 2;
            B /= 2;
        }
        
        
        printf("%lld\n", (long long)A *10 );
    }
    
    
    
    return 0;
}