#include <stdio.h>

int main() {
    
    int result = 0;
    char array_Say[101];
    scanf("%s", array_Say);
    
    for(int i = 0; ; i++) {
        
        if (array_Say[i] == '\0') {break;}
        else {
            
            if (array_Say[i] == 'c' && array_Say[i+1] == '=') {
                i++;
                result++;
            }
            else if (array_Say[i] == 'c' && array_Say[i+1] == '-') {
                i++;
                result++;
            }
            else if (array_Say[i] == 'd' && array_Say[i+1] == 'z' && array_Say[i+2] == '=') {
                i += 2;
                result++;
            }
            else if (array_Say[i] == 'd' && array_Say[i+1] == '-') {
                i++;
                result++;
            }
            else if (array_Say[i] == 'l' && array_Say[i+1] == 'j') {
                i++;
                result++;
            }
            else if (array_Say[i] == 'n' && array_Say[i+1] == 'j') {
                i++;
                result++;
            }
            else if (array_Say[i] == 's' && array_Say[i+1] == '=') {
                i++;
                result++;
            }
            else if (array_Say[i] == 'z' && array_Say[i+1] == '=') {
                i++;
                result++;
            }
            else {
                result++;
            }
        }
    }
    
    printf("%d", result);
    
    return 0;
}