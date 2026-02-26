#include <stdio.h>
#include <string.h>


int main() {
   
   int main_Length, current = 0;
   char main_Name[102], short_Name[102];
   scanf("%s", main_Name);
   
   main_Length = strlen(main_Name);
   
   for (int now_Index = 0 ; now_Index < main_Length ; now_Index++ )
   {
       if ( main_Name[now_Index] >= 65 && main_Name[now_Index]<= 90 ) 
       {
           short_Name[current++] = main_Name[now_Index];
       }
       
       else 
       {
            continue;
       }
       
   }
   
   short_Name[ strlen(short_Name) ] = '\0';
   printf("%s", short_Name);
   
   
    return 0;
}