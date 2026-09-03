#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char input[500];
    int i = 0;

    printf("Enter a C statement:\n");
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
            break;
        }

        /* Ignore multi-line comments */
        else if (input[i] == '/' && input[i + 1] == '*')
        {
            i += 2;

            while (input[i] != '\0' &&
                   !(input[i] == '*' && input[i + 1] == '/'))
            {
                i++;
            }

            if (input[i] != '\0')
                i += 2;
        }

        /* Identify identifiers */
        else if (isalpha(input[i]) || input[i] == '_')
        {
            char identifier[50];
            int j = 0;

            while (isalnum(input[i]) || input[i] == '_')
            {
                if (j < 49)
                    identifier[j++] = input[i];

                i++;
            }

            identifier[j] = '\0';

            printf("Identifier: %s\n", identifier);
        }

        /* Identify constants */
        else if (isdigit(input[i]))
        {
            char constant[50];
            int j = 0;

            while (isdigit(input[i]) || input[i] == '.')
            {
                if (j < 49)
                    constant[j++] = input[i];

                i++;
            }

            constant[j] = '\0';

            printf("Constant: %s\n", constant);
        }

        /* Identify operators */
        else if (input[i] == '+' || input[i] == '-' ||
                 input[i] == '*' || input[i] == '/' ||
                 input[i] == '=' || input[i] == '%' ||
                 input[i] == '<' || input[i] == '>')
        {
            printf("Operator: %c\n", input[i]);
            i++;
        }

        /* Ignore other symbols such as ; , ( ) */
        else
        {
            i++;
        }
    }

    return 0;
}
