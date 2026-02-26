#include<stdio.h>

int main()
{
    char say_Word[1000000];
    int array_Alp[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int max =0;
    int checkcode =0;
    
    scanf("%s", say_Word);
    
    for(int i=0;;i++){
        if (say_Word[i] == '\0'){
            break;
        }
        else if (say_Word[i] <=90 && say_Word[i] >=65) {
            array_Alp[say_Word[i]%65]++;     
        }
        else {
            array_Alp[say_Word[i]%97]++;
        }
        
    }
    
    for (int i=0;i<26;i++){
        if (max <= array_Alp[i] ) {
            max = array_Alp[i];
            checkcode = i;
        }
    }
    
    for (int i=0;i<26;i++){
        if (max == array_Alp[i] && checkcode != i){
            printf("?");
            checkcode = -1;
            break;
        }
    }    
    
    if (checkcode >= 0) {
        printf("%c", checkcode+65);
    }
    
    return 0;
}