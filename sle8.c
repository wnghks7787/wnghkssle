#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char input[1000002];
    int count = 0;

    fgets(input, 1000002, stdin);
    input[strlen(input)] = '\0';

    if(isalpha(input[0]) != 0)
        count++;
    for(int i = 0 ; i < 1000002 ; i++)
    {
        if(input[i] == ' ' && isalpha(input[i + 1]) != 0)
            count++;
        if(input[i] == '\0')
            break;
    }

    printf("%d\n", count);

    return 0;
}