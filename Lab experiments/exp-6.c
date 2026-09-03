#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char id[50];
    int i, valid = 1;

    printf("Enter an identifier: ");
    scanf("%s", id);

    /* Check first character */
    if (!(isalpha(id[0]) || id[0] == '_'))
    {
        valid = 0;
    }

    /* Check remaining characters */
    for (i = 1; id[i] != '\0'; i++)
    {
        if (!(isalnum(id[i]) || id[i] == '_'))
        {
            valid = 0;
            break;
        }
    }

    /* Display result */
    if (valid == 1)
    {
        printf("Valid Identifier\n");
    }
    else
    {
        printf("Invalid Identifier\n");
    }

    return 0;
}
