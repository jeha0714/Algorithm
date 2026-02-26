#include<stdio.h>

int main()
{
    int howManyPlay ;
    int rePlay;
    char array_Say[21];
    
    scanf("%d", &howManyPlay);
    
    for (int i=0;i<howManyPlay;i++){//전체 플레이 횟수
        
        int code =0;
        
        scanf("%d %s", &rePlay, array_Say);
        
        for (int j=0;;j++){
        
            if (array_Say[j] != '\0'){
            
                for (int k=0;k<rePlay;k++){
                
                    printf("%c", array_Say[code]);
                    
                }
            }
            else {
                break;
            }
            code++;
        }
        
        printf("\n");
    }
    
    
    
    return 0;
}