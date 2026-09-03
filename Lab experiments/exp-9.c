#include <stdio.h>

int main()
{
    char nonTerminal;
    char alpha[20];
    char beta[20];

    printf("Enter the non-terminal: ");
    scanf(" %c", &nonTerminal);

    printf("Enter alpha (the part after the left recursive symbol): ");
    scanf("%s", alpha);

    printf("Enter beta (the non-left-recursive production): ");
    scanf("%s", beta);

    printf("\nGrammar before eliminating left recursion:\n");
    printf("%c -> %c%s | %s\n", nonTerminal, nonTerminal, alpha, beta);

    printf("\nGrammar after eliminating left recursion:\n");

    printf("%c -> %s%c'\n", nonTerminal, beta, nonTerminal);
    printf("%c' -> %s%c' | epsilon\n", nonTerminal, alpha, nonTerminal);

    return 0;
}
