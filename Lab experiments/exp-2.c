#include <stdio.h>
#include <string.h>

int main()
{
    char line[500];

    printf("Enter a line:\n");
    fgets(line, sizeof(line), stdin);

    /* Check for single-line comment */
    if (line[0] == '/' && line[1] == '/')
    {
        printf("It is a single-line comment.\n");
    }

    /* Check for multi-line comment */
    else if (line[0] == '/' && line[1] == '*')
    {
        if (strstr(line, "*/") != NULL)
        {
            printf("It is a multi-line comment.\n");
        }
        else
        {
            printf("It is the beginning of a multi-line comment.\n");
        }
    }

    /* Not a comment */
    else
    {
        printf("It is not a comment.\n");
    }

    return 0;
}
