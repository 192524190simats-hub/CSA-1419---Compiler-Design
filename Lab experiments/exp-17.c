#include <stdio.h>
#include <string.h>

char leading[3][20];
int count[3] = {0, 0, 0};

/* Add a symbol to LEADING set */
void add(int nonTerminal, char symbol[])
{
    int i;

    for (i = 0; i < count[nonTerminal]; i++)
    {
        if (strcmp(leading[nonTerminal][i], symbol) == 0)
            return;
    }

    strcpy(leading[nonTerminal][count[nonTerminal]], symbol);
    count[nonTerminal]++;
}

int main()
{
	int i;
    printf("Grammar:\n");
    printf("E -> E + T | T\n");
    printf("T -> T * F | F\n");
    printf("F -> ( E ) | id\n\n");

    /*
       F -> ( E )
       F -> id
    */
    add(2, "(");
    add(2, "id");

    /*
       T -> T * F
       T -> F

       LEADING(T) contains '*'
       and LEADING(F)
    */
    add(1, "*");

    add(1, "(");
    add(1, "id");

    /*
       E -> E + T
       E -> T

       LEADING(E) contains '+'
       and LEADING(T)
    */
    add(0, "+");

    add(0, "*");
    add(0, "(");
    add(0, "id");

    printf("LEADING Sets:\n");

    printf("LEADING(E) = { ");
    for (i = 0; i < count[0]; i++)
    {
        printf("%s", leading[0][i]);

        if (i < count[0] - 1)
            printf(", ");
    }
    printf(" }\n");

    printf("LEADING(T) = { ");
    for (i = 0; i < count[1]; i++)
    {
        printf("%s", leading[1][i]);

        if (i < count[1] - 1)
            printf(", ");
    }
    printf(" }\n");

    printf("LEADING(F) = { ");
    for (i = 0; i < count[2]; i++)
    {
        printf("%s", leading[2][i]);

        if (i < count[2] - 1)
            printf(", ");
    }
    printf(" }\n");

    return 0;
}
