#include <stdio.h>
#include <stdlib.h>


int compare(const void * first, const void * second)
{
    if ( (*(int *)first) < (*(int *)second) )
        return -1;
    
    else if ( (*(int *)first) == (*(int *)second) )
        return 0;
        
    else
        return 1;
        
}




int main() {
    
    int N, M; //N은 주어지는 수의 개수, M은 존재여부를 묻는 수의 개수
    scanf("%d", &N);
    
    int array_Num[N]; // array_Num은 주어지는 수를 저장할 배열
    for (int now_Index = 0; now_Index < N; now_Index++) { scanf("%d", &array_Num[now_Index] ); }
    
    scanf("%d", &M);
    int find_Num[M]; // find_Num은 존재여부를 묻는 수를 저장할 배열
    for (int now_Index = 0; now_Index < M; now_Index++) { scanf("%d", &find_Num[now_Index] ); }
    
    
    qsort(array_Num, N, sizeof(array_Num[0]), compare);
    
    
    for (int now_Index = 0 ; now_Index < M; now_Index++ )
    {
        if ( bsearch( &find_Num[now_Index], array_Num, N, sizeof(array_Num[0]), compare ) != NULL )
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
        
    }

    
    return 0;
}