#include <stdio.h>

void calculate_Price( int * before_Red, int red, int * before_Green, int green, int * before_Blue, int blue )
{
    int save_before_Red = *before_Red;
    int save_before_Green = *before_Green;
    int save_before_Blue = *before_Blue;
    
    
    if ( *before_Red + blue < *before_Green + blue )
        save_before_Blue = *before_Red + blue;
    else
        save_before_Blue = *before_Green + blue;
               
             
    if ( *before_Blue + green < *before_Red + green )
        save_before_Green = *before_Blue + green;
    else
        save_before_Green = *before_Red + green;
            
                
    if ( *before_Blue + red < *before_Green + red )
        save_before_Red = *before_Blue + red;
    else
        save_before_Red = *before_Green + red;
        
        
    *before_Red = save_before_Red;
    *before_Green = save_before_Green;
    *before_Blue = save_before_Blue;
}



int main() {
    
    int num_House; scanf("%d", &num_House); // 집의 수
    
    int before_Red = (int)malloc( sizeof(int) );
    int before_Green = (int)malloc( sizeof(int) );
    int before_Blue = (int)malloc( sizeof(int) );
    
    
    for (int now_House = 0 ; now_House < num_House ; now_House++ )
    {
        int red, green, blue;
        scanf("%d %d %d", &red, &green, &blue);
        
        // 첫 번째 집의 경우
        if ( now_House == 0 )
        {
            before_Red = red;
            before_Green = green;
            before_Blue = blue;
        }
        
        // 두 번째 집부터
        else
        {
            calculate_Price( &before_Red, red, &before_Green, green, &before_Blue, blue );
        }
        
        
    }
    
    
    // 세 값들 중 가장 작은 값을 선택하여 출력.
    if ( before_Red <= before_Green && before_Red <= before_Blue )
        printf("%d", before_Red);
    else if ( before_Green <= before_Red && before_Green <= before_Blue )
        printf("%d", before_Green);
    else if ( before_Blue <= before_Red & before_Blue <= before_Green )
        printf("%d", before_Blue);
    
    return 0;
}