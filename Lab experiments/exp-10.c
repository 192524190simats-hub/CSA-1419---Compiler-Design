#include <stdio.h>

int main()
{
    char common[20];
    char first[20];
    char second[20];

    printf("Enter first production: ");
    scanf("%s", first);

    printf("Enter second production: ");
    scanf("%s", second);

    printf("Enter common prefix: ");
    scanf("%s", common);

    printf("\nGrammar before left factoring:\n");
    printf("S -> %s | %s | a\n", first, second);
    printf("E -> b\n");

    printf("\nGrammar after left factoring:\n");
    printf("S  -> %sS' | a\n", common);
    printf("S' -> eS | epsilon\n");
    printf("E  -> b\n");

    return 0;
}
