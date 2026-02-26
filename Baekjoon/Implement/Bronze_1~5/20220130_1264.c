#include <stdio.h>
#include <string.h>


int main()
{
    char string[257];

    while ( strcmp(fgets(string, sizeof(string), stdin), "#\n") != 0 )
    {
            
        int str_Len = strlen(string);
        int result = 0;

        for (int i = 0; i < str_Len; i++)
        {
            if (string[i] == 'A' || string[i] == 'a' || string[i] == 'E' || string[i] == 'e' || string[i] == 'O'
                || string[i] == 'o' || string[i] == 'I' || string[i] == 'i' || string[i] == 'U' || string[i] == 'u')
                result++;
        }

        printf("%d\n", result);
    }


    return 0;
}
