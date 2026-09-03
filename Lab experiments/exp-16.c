#include <stdio.h>
#include <string.h>

int main()
{
    char op[10], arg1[10], arg2[10], result[10];

    printf("Enter three-address code:\n");
    printf("Enter operator, operand1, operand2 and result:\n");

    scanf("%s %s %s %s", op, arg1, arg2, result);

    printf("\nTarget Code:\n");

    // Load first operand
    printf("MOV R0, %s\n", arg1);

    // Perform operation
    if (strcmp(op, "+") == 0)
    {
        printf("ADD R0, %s\n", arg2);
    }
    else if (strcmp(op, "-") == 0)
    {
        printf("SUB R0, %s\n", arg2);
    }
    else if (strcmp(op, "*") == 0)
    {
        printf("MUL R0, %s\n", arg2);
    }
    else if (strcmp(op, "/") == 0)
    {
        printf("DIV R0, %s\n", arg2);
    }
    else
    {
        printf("Invalid operator\n");
        return 0;
    }

    // Store result
    printf("MOV %s, R0\n", result);

    return 0;
}
