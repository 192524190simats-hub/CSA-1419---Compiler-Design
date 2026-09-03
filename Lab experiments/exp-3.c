#include <stdio.h>
#include <ctype.h>

int main()
{
    char input[1000];
    int i = 0;

    printf("Enter the program:\n");
    fgets(input, sizeof(input), stdin);

    while (input[i] != '\0')
    {
        /* Ignore spaces, tabs and new lines */
        if (input[i] == ' ' || input[i] == '\t' || input[i] == '\n')
        {
            i++;
        }

        /* Ignore single-line comments */
        else if (input[i] == '/' && input[i + 1] == '/')
        {
            while (input[i] != '\n' && input[i] != '\0')
            {
                i++;
            }
        }

        /* Ignore multi-line comments */
        else if (input[i] == '/' && input[i + 1] == '*')
        {
            i = i + 2;

            while (input[i] != '\0')
            {
                if (input[i] == '*' && input[i + 1] == '/')
                {
                    i = i + 2;
                    break;
                }

                i++;
            }
        }

        /* Display identifiers */
        else if (isalpha(input[i]) || input[i] == '_')
        {
            printf("Identifier: ");

            while (isalnum(input[i]) || input[i] == '_')
            {
                printf("%c", input[i]);
                i++;
            }

            printf("\n");
        }

        /* Display numbers */
        else if (isdigit(input[i]))
        {
            printf("Constant: ");

            while (isdigit(input[i]))
            {
                printf("%c", input[i]);
                i++;
            }

            printf("\n");
        }

        /* Display operators */
        else if (input[i] == '+' || input[i] == '-' ||
                 input[i] == '*' || input[i] == '/' ||
                 input[i] == '=' || input[i] == '%')
        {
            printf("Operator: %c\n", input[i]);
            i++;
        }

        /* Ignore other symbols */
        else
        {
            i++;
        }
    }

    return 0;
}
