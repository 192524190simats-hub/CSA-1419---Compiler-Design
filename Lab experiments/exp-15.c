#include <stdio.h>
#include <ctype.h>

int main()
{
    FILE *fp;
    char filename[100];
    char ch;

    int characters = 0;
    int words = 0;
    int lines = 0;
    int inWord = 0;

    printf("Enter the file name: ");
    scanf("%s", filename);

    /* Open the file */
    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Unable to open the file.\n");
        return 1;
    }

    /* Read the file character by character */
    while ((ch = fgetc(fp)) != EOF)
    {
        characters++;

        /* Count lines */
        if (ch == '\n')
        {
            lines++;
        }

        /* Count words */
        if (isspace(ch))
        {
            inWord = 0;
        }
        else if (inWord == 0)
        {
            words++;
            inWord = 1;
        }
    }

    /* Close the file */
    fclose(fp);

    printf("\nNumber of characters = %d\n", characters);
    printf("Number of words      = %d\n", words);
    printf("Number of lines      = %d\n", lines);

    return 0;
}
