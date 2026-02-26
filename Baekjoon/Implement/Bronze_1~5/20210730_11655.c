#include <stdio.h>

int main() {
    
    char code[110];
    
    fgets(code, 110, stdin);
    
    for (int i = 0 ; i < 100 ; i++) {
        
        if (code[i] == '\0') {break;}
        
        if ((code[i] >= 65 && code[i] <= 77) || (code[i] >= 97 && code[i] <= 109)) {
            printf("%c", code[i] + 13);
        }
        else if ((code[i] >= 78 && code[i] <= 90) || (code[i] >= 110 && code[i] <= 122)) {
            printf("%c", code[i] - 13);
        }
        else {
            printf("%c", code[i]);
        }
        
        
    }
    
    
    
    
    return 0;
}