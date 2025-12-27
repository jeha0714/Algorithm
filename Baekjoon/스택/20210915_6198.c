#include <stdio.h>

int stack[80000];
int top = -1;

extern void push(int num);
extern void pop();



int main() {
    
    long long sum_All = 0; // 각 관리인들이 벤치마킹이 가능한 빌딩의 수의 합을 저장할 변수
    int num_Building; // 빌딩의 개수
    scanf("%d", &num_Building);
    
    int result_Building[num_Building]; // 각 빌딩이 다른 빌딩의 옥상을 확인할 수 있는 수를 확인 한 수.
    int height_Building[num_Building]; // 빌딩의 높이를 저장한 배열
    
    for (int now_Index = 0; now_Index < num_Building; now_Index++ ) 
    { 
        // 빌딩의 높이를 입력받음과 동시에 결과 값이 저장될 배열을 0으로 초기화.
        scanf("%d", &height_Building[now_Index]); 
        result_Building[now_Index] = 0;
    }
    
    
    for (int now_Index = num_Building - 1 ; now_Index >= 0 ; now_Index-- )
    {
        if ( top == -1 ) { push( now_Index ); } // 탑이 비었을 시 push
        
        else
        { // 스택에 값이 저장되어있을때
            
            // 스택에 저장된 인덱스값의 높이보다 now_Index의 높이가 클 때 top의 높이보다 작을때까지 pop해준다.
            while ( ( height_Building[now_Index] > height_Building[ stack[top] ] ) && (top != -1 ) )
            {
                result_Building[now_Index]++; // now_Index가 탑의 인덱스 높이보다 크므로 +1 해주고
                result_Building[now_Index] += result_Building[ stack[top] ]; // top의 인덱스보다 작았던 높이들 또한 now_Index의 높이보다 작으므로 그 값을 추가해준다.
                pop(); 
            }
            
            //now_Index를 push.
            push( now_Index );
        }
        
    }
    
    // 각 빌딩에서 확인 가능한 다른 빌딩의 수를 모두 종합.
    for (int now_Index = num_Building - 1 ; now_Index >= 0 ; now_Index-- ) { sum_All += result_Building[now_Index];}
    
    // 답 출력.
    printf("%lld", sum_All);
    
    return 0;
}



/* stack 관련 함수 */

void push(int num)
{
    stack[++top] = num;
}

void pop()
{
    top--;
}