#include<stdio.h>

int main()
{
    int array_A[26];
    char array_Say[101];
    
    scanf("%s", array_Say);
    
    for (int i=0;i<26;i++){
        
        array_A[i] = -1;   
    }
    
    for(int i=0;;i++){
        
        if(array_Say[i] =='\0'){
            break;
        }
        else if((array_Say[i] != '\0') && (array_A[array_Say[i]%97] == -1)) {
            array_A[(array_Say[i]%97)] = i;
        }
        else {
            continue;
        }
        
    }
    
    for (int i=0;i<26;i++){
        printf("%d ",array_A[i]);
    }
    
    return 0;
}