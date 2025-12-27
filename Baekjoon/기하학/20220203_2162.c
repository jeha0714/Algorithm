#include <stdio.h>
#include <stdbool.h>

// 외곽을 통한 한 선분과 한 점의 관계를 알기 위한 CSS 함수
int CSS( int x1, int y1, int x2, int y2, int x3, int y3 )
{
    int result = ( x2 -x1 )*( y3 - y1 ) - ( y2 - y1 )*( x3 - x1 );
    
    if ( result > 0 )
        return 1;
    else if ( result == 0 )
        return 0;
    else
        return -1;
}


// 두 선분이 교차하는지 알아보는 홤수 ( 0은 교차한다는 의미 -1은 교차하지 않는다는 의미 )
int line_Relation( int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4 )
{
    int L1_with_first_CSS = CSS( x1, y1, x2, y2, x3, y3);
    int L1_with_second_CSS = CSS( x1, y1, x2, y2, x4, y4);
    
    
    
    if ( L1_with_first_CSS == L1_with_second_CSS )
    {
        if ( L1_with_first_CSS == 1 || L1_with_first_CSS == -1 )
            return -1;
        // 값이 둘다 0임
        else
        {
            int L1_big_X = x1 < x2 ? x2 : x1;
            int L1_small_X = x1 < x2 ? x1 : x2;
            int L1_big_Y = y1 < y2 ? y2 : y1;
            int L1_small_Y = y1 < y2 ? y1 : y2;
            
            int L2_big_X = x3 < x4 ? x4 : x3;
            int L2_small_X = x3 < x4 ? x3 : x4;
            int L2_big_Y = y3 < y4 ? y4 : y3;
            int L2_small_Y = y3 < y4 ? y3 : y4;
            
            if ( ( ( ( L1_small_X <= x3 && x3 <= L1_big_X ) && ( L1_small_Y <= y3 && y3 <= L1_big_Y ) ) ||
            ( ( L1_small_X <= x4 && x4 <= L1_big_X ) && ( L1_small_Y <= y4 && y4 <= L1_big_Y ) ) ) || 
            ( ( ( L2_small_X <= x1 && x1 <= L2_big_X ) && ( L2_small_Y <= y1 && y1 <= L2_big_Y ) ) ||
            ( ( L2_small_X <= x2 && x2 <= L2_big_X ) && ( L2_small_Y <= y2 && y2 <= L2_big_Y ) ) ) )
                return 0;
            else
                return -1;
        }
        
    }
    
    else // L1_with_first_CSS != L1_with_second_CSS
    {
        if ( L1_with_first_CSS != 0 && L1_with_second_CSS != 0 )
        {
            int L2_with_first_CSS = CSS( x3, y3, x4, y4, x1, y1);
            int L2_with_scond_CSS = CSS( x3, y3, x4, y4, x2, y2);
            
            if ( ( L2_with_first_CSS == 1 && L2_with_scond_CSS == -1 ) ||
                ( L2_with_first_CSS == -1 && L2_with_scond_CSS == 1 ) )
                return 0;
            else
                return line_Relation( x3, y3, x4, y4, x1, y1, x2, y2);
        }
        
        // L1_with_first_CSS or L1_with_second_CSS 중 하나는 값이 0임.
        else
        {
            int L1_big_X = x1 < x2 ? x2 : x1;
            int L1_small_X = x1 < x2 ? x1 : x2;
            int L1_big_Y = y1 < y2 ? y2 : y1;
            int L1_small_Y = y1 < y2 ? y1 : y2;
            
            if ( L1_with_first_CSS == 0 )
            {
                if ( ( L1_small_X <= x3 && x3 <= L1_big_X ) && ( L1_small_Y <= y3 && y3 <= L1_big_Y ) )
                    return 0;
                else
                    return -1;
                
            }
            else if ( L1_with_second_CSS == 0 )
            {
                if ( ( L1_small_X <= x4 && x4 <= L1_big_X ) && ( L1_small_Y <= y4 && y4 <= L1_big_Y ) )
                    return 0;
                else
                    return -1;
            }
            
        }
        
    }
    
    return -2;
}

// 최상위 부모 노드를 찾아주는 함수
int find_Parent( int num, int array[][5] )
{
    if ( array[num][4] == num )
        return num;
    return array[num][4] = find_Parent( array[num][4], array );
}


// 두 개의 노드를 이어주는 함수
void merge( int num1, int num2, int array[][5] )
{
    num1 = find_Parent( num1, array );
    num2 = find_Parent( num2, array );
    
    if ( num1 == num2 )
        return;
    
    array[num2][4] = num1;
}

// 두 개의 노드가 연결되어있는지 파악하는 함수 true 라면 연결 false라면 비연결
bool IsUnion ( int num1, int num2, int array[][5] )
{
    num1 = find_Parent( num1, array );
    num2 = find_Parent( num2, array );
    
    if ( num1 == num2 )
        return true;
    
    return false;
}


int main() {
    
    // 주어지는 선분들의 총 개수
    int num_Spot; scanf("%d", &num_Spot );
    
    // 0~3열은 선분을 이루는 양끝점의 좌표, 4열은 현재 속하는 그룹의 부모 노드 저장
    int spot_Field[ num_Spot ][5];
    for(int index = 0 ; index < num_Spot ; index++ )
    {
        // 선분을 이루는 양 끝 점 입력
        scanf("%d %d %d %d", &spot_Field[ index ][0], &spot_Field[ index ][1], 
                                &spot_Field[ index ][2], &spot_Field[ index ][3] );
                                
        // 해당 선분이 속하는 선분그룹을 -1로 초기화.
        spot_Field[ index ][4] = index;
    }
    
    // 선분을 하나하나 비교해가며 선분 그룹을 정해준다.
    for ( int main = 0; main < num_Spot ; main++ )
    {
        for ( int find_Group = 0 ; find_Group < num_Spot ; find_Group++ )
        {
            int code = line_Relation( spot_Field[ main ][0], spot_Field[ main ][1], spot_Field[ main ][2], spot_Field[ main ][3]
                            , spot_Field[ find_Group ][0], spot_Field[ find_Group ][1], spot_Field[ find_Group ][2], spot_Field[ find_Group ][3] );
            
            
            // 만약 교차하는 선분을 찾았다면 그 그룹에 속하는것이므로 부모 노드를 4열에 저장.
            if ( code == 0 )
            {
                merge( main, find_Group, spot_Field );
            }

        }
        
    }
    
    // index 0부터 num_Spot-1까지 [4]를 통해 최상위 부모 노드를 찾는다.
    int parent_Node[ num_Spot ];
    for (int i = 0 ; i < num_Spot ; i++ ) // 우선 0으로 모두 초기화.
        parent_Node[ i ] = 0;
    
    for (int i = 0 ; i < num_Spot ; i++ ) // 최상위 부모 노드 찾는다.
        parent_Node[ find_Parent( spot_Field[i][4], spot_Field ) ]++;
    
    
    // 그룹의 총 개수와 멤버가 가장 많은 그룹의 멤버수를 찾는다.
    int num_Group = 0;
    int member_Max = 0;
    for ( int i = 0 ; i < num_Spot ; i++ )
    {
        if ( member_Max < parent_Node[ i ] )
            member_Max = parent_Node[i];
        
        if ( parent_Node[i] != 0)
            num_Group++;
    }
    
    // 결과값 출력
    printf("%d\n%d", num_Group, member_Max);
    
    
    return 0;
}