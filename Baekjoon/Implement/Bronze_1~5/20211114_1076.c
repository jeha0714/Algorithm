#include <stdio.h>
#include <string.h>

int main() {
    
    long long result = 0;
    
    char s[10]; 
    scanf("%s", s);
        
        if ( strcmp(s, "black")  == 0 )
            result += 0;
            
        else if ( strcmp(s, "brown") == 0 )
            result += 10;
            
        else if ( strcmp(s, "red") == 0 )
            result += 20;
            
        else if ( strcmp(s, "orange") == 0 )
            result += 30;
            
        else if ( strcmp(s, "yellow") == 0 )
            result += 40;
            
        else if ( strcmp(s, "green") == 0 )
            result += 50;
            
        else if ( strcmp(s, "blue") == 0 )
            result += 60;
            
        else if ( strcmp(s, "violet") == 0 )
            result += 70;
            
        else if ( strcmp(s, "grey") == 0 )
            result += 80;
            
        else if ( strcmp(s, "white") == 0 )
            result += 90;
    
    scanf("%s", s);
        
        if ( strcmp(s, "black")  == 0 )
            result += 0;
            
        else if ( strcmp(s, "brown") == 0 )
            result += 1;
            
        else if ( strcmp(s, "red") == 0 )
            result += 2;
            
        else if ( strcmp(s, "orange") == 0 )
            result += 3;
            
        else if ( strcmp(s, "yellow") == 0 )
            result += 4;
            
        else if ( strcmp(s, "green") == 0 )
            result += 5;
            
        else if ( strcmp(s, "blue") == 0 )
            result += 6;
            
        else if ( strcmp(s, "violet") == 0 )
            result += 7;
            
        else if ( strcmp(s, "grey") == 0 )
            result += 8;
            
        else if ( strcmp(s, "white") == 0 )
            result += 9;
    
    scanf("%s", s);
    
    if ( strcmp(s, "black") == 0 )
            result *= 1;
            
        else if ( strcmp(s, "brown") == 0 )
            result *= 10;
            
        else if ( strcmp(s, "red") == 0 )
            result *= 100;
            
        else if ( strcmp(s, "orange") == 0 )
            result *= 1000;
            
        else if ( strcmp(s, "yellow") == 0 )
            result *= 10000;
            
        else if ( strcmp(s, "green") == 0 )
            result *= 100000;
            
        else if ( strcmp(s, "blue") == 0 )
            result *= 1000000;
            
        else if ( strcmp(s, "violet") == 0 )
            result *= 10000000;
            
        else if ( strcmp(s, "grey") == 0 )
            result *= 100000000;
            
        else if ( strcmp(s, "white") == 0 )
            result *= 1000000000;
    
    
    printf("%lld", result);
    
    return 0;
}