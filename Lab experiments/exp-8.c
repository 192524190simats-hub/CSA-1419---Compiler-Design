#include <stdio.h>
#include <string.h>
#include <ctype.h>

char production[10][20];
int n;

char followS[10] = "";
char followA[10] = "";
char followB[10] = "";

/* Check whether character already exists */
int contains(char set[], char ch)
{
    int i;

    for (i = 0; set[i] != '\0'; i++)
    {
        if (set[i] == ch)
            return 1;
    }

    return 0;
}

/* Add character to set */
void add(char set[], char ch)
{
    int len;

    if (!contains(set, ch))
    {
        len = strlen(set);
        set[len] = ch;
        set[len + 1] = '\0';
    }
}

int main()
{
    int i, j, k;
    char lhs;

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("\nEnter productions without spaces.\n");
    printf("Use e for epsilon.\n\n");

    for (i = 0; i < n; i++)
    {
        printf("Production %d: ", i + 1);
        scanf("%s", production[i]);
    }

    /* # represents end of input */
    add(followS, '#');

    /* Check all productions */
    for (i = 0; i < n; i++)
    {
        lhs = production[i][0];

        for (j = 3; production[i][j] != '\0'; j++)
        {
            /* Check for A */
            if (production[i][j] == 'A')
            {
                if (production[i][j + 1] != '\0')
                {
                    /* Next symbol is a terminal */
                    if (!isupper(production[i][j + 1]) &&
                        production[i][j + 1] != 'e')
                    {
                        add(followA, production[i][j + 1]);
                    }
                }
                else
                {
                    /* A is at the end */
                    if (lhs == 'S')
                    {
                        for (k = 0; followS[k] != '\0'; k++)
                        {
                            add(followA, followS[k]);
                        }
                    }
                }
            }

            /* Check for B */
            if (production[i][j] == 'B')
            {
                if (production[i][j + 1] != '\0')
                {
                    /* Next symbol is a terminal */
                    if (!isupper(production[i][j + 1]) &&
                        production[i][j + 1] != 'e')
                    {
                        add(followB, production[i][j + 1]);
                    }
                }
                else
                {
                    /* B is at the end */
                    if (lhs == 'S')
                    {
                        for (k = 0; followS[k] != '\0'; k++)
                        {
                            add(followB, followS[k]);
                        }
                    }
                }
            }
        }
    }

    /* Display FOLLOW sets */
    printf("\nFOLLOW Sets:\n");

    printf("FOLLOW(S) = { ");
    for (i = 0; followS[i] != '\0'; i++)
    {
        printf("%c ", followS[i]);
    }
    printf("}\n");

    printf("FOLLOW(A) = { ");
    for (i = 0; followA[i] != '\0'; i++)
    {
        printf("%c ", followA[i]);
    }
    printf("}\n");

    printf("FOLLOW(B) = { ");
    for (i = 0; followB[i] != '\0'; i++)
    {
        printf("%c ", followB[i]);
    }
    printf("}\n");

    return 0;
}
