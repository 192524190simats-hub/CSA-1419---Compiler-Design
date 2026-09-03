#include <stdio.h>
#include <string.h>
#include <ctype.h>

char expression[100];
char stack[100][10];
int top = -1;
int temp = 1;

/* Push a string onto stack */
void push(char str[])
{
    top++;
    strcpy(stack[top], str);
}

/* Pop a string from stack */
void pop(char str[])
{
    strcpy(str, stack[top]);
    top--;
}

/* Generate temporary variable */
void generateCode(char op)
{
    char operand1[10];
    char operand2[10];
    char result[10];

    pop(operand2);
    pop(operand1);

    sprintf(result, "t%d", temp);

    printf("%s = %s %c %s\n",
           result, operand1, op, operand2);

    push(result);

    temp++;
}

int main()
{
    int i;
    char ch;
    char operand[10];
    char left[10];
    char finalResult[10];

    printf("Enter an expression:\n");
    scanf("%s", expression);

    printf("\nThree Address Code:\n");

    /*
       Process multiplication and division first
    */
    for (i = 0; expression[i] != '\0'; i++)
    {
        ch = expression[i];

        if (isalnum(ch))
        {
            operand[0] = ch;
            operand[1] = '\0';
            push(operand);
        }

        else if (ch == '*' || ch == '/')
        {
            generateCode(ch);
        }
    }

    /*
       Process addition and subtraction
    */
    for (i = 0; expression[i] != '\0'; i++)
    {
        ch = expression[i];

        if (ch == '+' || ch == '-')
        {
            generateCode(ch);
        }
    }

    /*
       Get final result
    */
    pop(finalResult);

    printf("\nFinal result stored in: %s\n", finalResult);

    return 0;
}
