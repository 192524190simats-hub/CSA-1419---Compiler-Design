#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;

/* Push a character onto stack */
void push(char ch)
{
    top++;
    stack[top] = ch;
    stack[top + 1] = '\0';
}

/* Reduce id to E */
int reduce_id()
{
    if (top >= 1 &&
        stack[top - 1] == 'i' &&
        stack[top] == 'd')
    {
        top = top - 1;
        stack[top] = 'E';
        stack[top + 1] = '\0';
        return 1;
    }

    return 0;
}

/* Reduce E+E to E */
int reduce_plus()
{
    if (top >= 2 &&
        stack[top - 2] == 'E' &&
        stack[top - 1] == '+' &&
        stack[top] == 'E')
    {
        top = top - 2;
        stack[top] = 'E';
        stack[top + 1] = '\0';
        return 1;
    }

    return 0;
}

/* Reduce E*E to E */
int reduce_star()
{
    if (top >= 2 &&
        stack[top - 2] == 'E' &&
        stack[top - 1] == '*' &&
        stack[top] == 'E')
    {
        top = top - 2;
        stack[top] = 'E';
        stack[top + 1] = '\0';
        return 1;
    }

    return 0;
}

/* Reduce (E) to E */
int reduce_brackets()
{
    if (top >= 2 &&
        stack[top - 2] == '(' &&
        stack[top - 1] == 'E' &&
        stack[top] == ')')
    {
        top = top - 2;
        stack[top] = 'E';
        stack[top + 1] = '\0';
        return 1;
    }

    return 0;
}

int main()
{
    char input[100];
    int i;
    int changed;

    printf("Grammar:\n");
    printf("E -> E+E\n");
    printf("E -> E*E\n");
    printf("E -> (E)\n");
    printf("E -> id\n\n");

    printf("Enter input string: ");
    scanf("%s", input);

    printf("\nShift-Reduce Parsing:\n");

    for (i = 0; input[i] != '\0'; i++)
    {
        /* Shift */
        push(input[i]);

        printf("Shift %c\tStack: %s\n", input[i], stack);

        /* Keep reducing as long as possible */
        do
        {
            changed = 0;

            if (reduce_id())
            {
                printf("Reduce id -> E\tStack: %s\n", stack);
                changed = 1;
            }
            else if (reduce_brackets())
            {
                printf("Reduce (E) -> E\tStack: %s\n", stack);
                changed = 1;
            }
            else if (reduce_plus())
            {
                printf("Reduce E+E -> E\tStack: %s\n", stack);
                changed = 1;
            }
            else if (reduce_star())
            {
                printf("Reduce E*E -> E\tStack: %s\n", stack);
                changed = 1;
            }

        } while (changed);
    }

    /* Final check */
    if (top == 0 && stack[0] == 'E')
    {
        printf("\nString is ACCEPTED.\n");
    }
    else
    {
        printf("\nString is REJECTED.\n");
    }

    return 0;
}
