#include <stdio.h>

int main() {
    
    int N;
    int left = 1, right = 1;
    int max;
    
    scanf("%d", &N);
    
    int array[N];
    for (int now_Index = 0 ; now_Index < N; now_Index++ ) { scanf("%d", &array[now_Index]); }
    
    
    max = array[0];
    for (int now_Index = 1 ; now_Index < N; now_Index++ )
    {
        if ( max < array[now_Index])
        {
            left++;
            max = array[now_Index];
        }
        
    }
    
    max = array[N - 1];
    for (int now_Index = N - 2 ; now_Index >= 0; now_Index-- )
    {
        if ( max < array[now_Index] )
        {
            right++;
            max = array[now_Index];
        }
    }
    
    
    printf("%d\n%d", left, right);
    
    return 0;
}