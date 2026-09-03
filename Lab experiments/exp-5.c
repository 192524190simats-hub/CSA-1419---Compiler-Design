#include <stdio.h>

int main()
{
    char input[500];
    int i;
    int spaces = 0;
    int tabs = 0;
    int newlines = 0;

    printf("Enter a text:\n");

    fgets(input, sizeof(input), stdin);

    for (i = 0; input[i] != '\0'; i++)
    {
        /* Count spaces */
        if (input[i] == ' ')
        {
            spaces++;
        }

        /* Count tabs */
        else if (input[i] == '\t')
        {
            tabs++;
        }

        /* Count newline */
        else if (input[i] == '\n')
        {
            newlines++;
        }
    }

    printf("\nNumber of spaces     = %d\n", spaces);
    printf("Number of tabs       = %d\n", tabs);
    printf("Number of newlines   = %d\n", newlines);

    return 0;
}
