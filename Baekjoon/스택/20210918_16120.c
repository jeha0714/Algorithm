#include <stdio.h>
#include <string.h>

char Stack[1000001];
int Top = -1;

void push( char String ) { Stack[++Top] = String; }
void pop() { Stack[Top--] = ' '; }



int main() {
    
    char main_String[1000001];
    int main_Length;
    
    scanf("%s", main_String);
    main_Length = strlen( main_String );
    
    for (int now_Index = 0 ; now_Index < main_Length ; now_Index++ )
    {
        push(main_String[ now_Index ] );
        
        if ( Top < 3 ) { continue; }
        
        else
        {
            if ( strncmp( &Stack[ Top - 3 ], "PPAP", 4) == 0 )
            {
                int num = 4;
                while( num-- ) { pop(); }
                
                push( 'P' );
            }
            
        }
        
    }
    
    if ( Top == 0 && Stack[ Top ] == 'P' ) { printf("PPAP"); }
    else { printf("NP"); }
    
    
    return 0;
}