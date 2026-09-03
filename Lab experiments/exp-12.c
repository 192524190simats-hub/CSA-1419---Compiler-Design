#include <stdio.h>

char input[100];
int pos = 0;
int valid = 1;

/* Function declarations */
void E();
void Eprime();
void T();
void Tprime();
void F();

/* E -> T E' */
void E()
{
    T();
    Eprime();
}

/* E' -> + T E' | epsilon */
void Eprime()
{
    if (input[pos] == '+')
    {
        pos++;
        T();
        Eprime();
    }
}

/* T -> F T' */
void T()
{
    F();
    Tprime();
}

/* T' -> * F T' | epsilon */
void Tprime()
{
    if (input[pos] == '*')
    {
        pos++;
        F();
        Tprime();
    }
}

/* F -> ( E ) | id */
void F()
{
    /* Check for id */
    if (input[pos] == 'i' && input[pos + 1] == 'd')
    {
        pos = pos + 2;
    }

    /* Check for ( E ) */
    else if (input[pos] == '(')
    {
        pos++;

        E();

        if (input[pos] == ')')
        {
            pos++;
        }
        else
        {
            valid = 0;
            printf("Error: ')' expected\n");
        }
    }

    else
    {
        valid = 0;
        printf("Error: id or '(' expected\n");
    }
}

int main()
{
    printf("Enter expression: ");
    scanf("%s", input);

    E();

    if (input[pos] != '\0')
    {
        valid = 0;
        printf("Error: Unexpected symbol '%c'\n", input[pos]);
    }

    if (valid == 1)
    {
        printf("String is accepted.\n");
    }
    else
    {
        printf("String is rejected.\n");
    }

    return 0;
}
