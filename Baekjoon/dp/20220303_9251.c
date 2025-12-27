#include <stdio.h>
#include <string.h>



int main()
{
    // 두 개의 문자열이 주어짐.
    char string1[1001], string2[1001]; scanf("%s %s", string1, string2 );
    
    // 각 문자열의 길이를 저장
    int string1_Len = strlen( string1 ), string2_Len = strlen( string2 );
    
    // 각 단어 하나하나를 비교하면서 
    // 행 기준 해당 열까지 도달 할 때 가장 긴 부분 수열의 길이를 저장. 
    int compare_Each[ string2_Len ][ string1_Len ];
    for (int i = 0 ; i < string2_Len ; i++ )
    {
        for (int j = 0 ; j < string1_Len ; j++ )
        {
            // string2의 첫 번째 문자( 0 행 )를 string1과 비교할 때
            if ( i == 0 )
            {
                if( string2[ i ] == string1[ j ] ) // 두 문자가 같은 경우
                {
                    // 값을 1로 대입
                        compare_Each[ i ][ j ] = 1;
                }
                
                else // string2[ i ] != string1[ j ] 로 두 문자가 다른 경우
                {
                    // 열이 0이 아닌 경우 
                    if ( j != 0 )
                        // 이전 열에 저장된 값을 저장해준다.
                        compare_Each[ i ][ j ] = compare_Each[ i ][ j - 1 ];
                    
                    // 열이 0인 경우는 해당 내부 값을 0으로 설정.
                    else if ( j == 0 )
                        compare_Each[ i ][ j ] = 0;
                }
                
            }
            
            
            // string2의 나머지 문자( 1행 이상 )와 string1을 비교할 때
            else
            {
                if( string2[ i ] == string1[ j ] ) // 두 문자가 같은 경우
                {
                    // 열이 0이 아닌 경우 
                    if ( j != 0 )
                    {
                        // 이전 행 이전 열 값에서 +1 해준다. ( 이전 까지 이어온 최대값에 하나를 덧 붙인다 생각 )
                        compare_Each[ i ][ j ] = compare_Each[ i - 1 ][ j - 1 ] + 1;
                    }
                    
                    // 열이 0인 경우 해당 배열 내부 값을 1로 설정.
                    else if ( j == 0 )
                        compare_Each[ i ][ j ] = 1;
                }
                
                else // string2[ i ] != string1[ j ] 로 두 문자가 다른 경우
                {
                    // 열이 0이 아닌 경우 
                    if ( j != 0 )
                    {
                        // 이전 행 해당 열의 값과 해당 행 이전 열 값중 큰 값을 대입
                        int more_Big = compare_Each[ i - 1 ][ j ] < compare_Each[ i ][ j - 1 ] ? compare_Each[ i ][ j - 1 ] : compare_Each[ i - 1 ][ j ]; 
                        compare_Each[ i ][ j ] = more_Big;
                    }
                    
                    // 열이 0인 경우는 해당 내부 값을 위의 행 해당 열 값으로 설정
                    else if ( j == 0 )
                        compare_Each[ i ][ j ] = compare_Each[ i - 1 ][ j ];
                }
                
            }
            
        }
        
    }
    
    // 결과값인 배열의 행과 열의 끝 값을 출력
    printf("%d", compare_Each[ string2_Len - 1 ][ string1_Len - 1 ] );
    
    return 0;
}
