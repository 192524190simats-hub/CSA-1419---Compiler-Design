#include <stdio.h>
#include <string.h>
#include <ctype.h>

char production[10][20];
int n;

/* Function to find FIRST */
void findFirst(char symbol)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        /* Check if production starts with the required symbol */
        if (production[i][0] == symbol)
        {
            printf("FIRST(%c) = { ", symbol);

            /* Get the right side of production */
            if (production[i][3] == 'e')
            {
                printf("epsilon");
            }
            else
            {
                j = 3;

                /* If first symbol is a terminal */
                if (!isupper(production[i][j]))
                {
                    printf("%c", production[i][j]);
                }

                /* If first symbol is a non-terminal */
                else
                {
                    findFirst(production[i][j]);
                }
            }

            printf(" }\n");
        }
    }
}

int main()
{
    int i;

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("\nEnter productions in the form A->a\n");
    printf("Use 'e' for epsilon.\n\n");

    for (i = 0; i < n; i++)
    {
        printf("Production %d: ", i + 1);
        scanf("%s", production[i]);
    }

    printf("\nFIRST Sets:\n");

    findFirst('S');
    findFirst('A');
    findFirst('B');

    return 0;
}
