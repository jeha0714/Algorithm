#include <stdio.h>
#include <string.h>

int main() {
    
    char s[4]; scanf("%s", s);
    
    if ( strcmp( s, "A+") == 0 )
        printf("4.3");
    else if ( strcmp( s, "A0") == 0 )
        printf("4.0");
    else if ( strcmp( s, "A-") == 0 )
        printf("3.7");
    else if ( strcmp( s, "B+") == 0 )
        printf("3.3");
    else if ( strcmp( s, "B0") == 0 )
        printf("3.0");
    else if ( strcmp( s, "B-") == 0 )
        printf("2.7");
    else if ( strcmp( s, "C+") == 0 )
        printf("2.3");
    else if ( strcmp( s, "C0") == 0 )
        printf("2.0");
    else if ( strcmp( s, "C-") == 0 )
        printf("1.7");
    else if ( strcmp( s, "D+") == 0 )
        printf("1.3");
    else if ( strcmp( s, "D0") == 0 )
        printf("1.0");
    else if ( strcmp( s, "D-") == 0 )
        printf("0.7");
    else 
        printf("0.0");
    
    return 0;
}