#include <stdio.h>



int main() {
    
    int T; scanf("%d", &T); // 테스트 케이스
    int test_case[ T ];
    
    for (int i = 0 ; i < T ; i++)
    {
        int num1, num2; char code;
        scanf("%d", &num1); scanf("%c", &code); scanf("%d", &num2);
        
        printf("%d\n", num1 + num2);
    }
    
    
    
    return 0;
}