#include <stdio.h>
#include <string.h>

struct Symbol
{
    char name[30];
    char type[20];
    char value[20];
};

struct Symbol table[50];

int count = 0;

/* Insert a symbol */
void insert()
{
    char name[30];

    printf("\nEnter identifier name: ");
    scanf("%s", name);

    /* Check if identifier already exists */
    if (search(name) != -1)
    {
        printf("Identifier already exists.\n");
        return;
    }

    strcpy(table[count].name, name);

    printf("Enter data type: ");
    scanf("%s", table[count].type);

    printf("Enter value: ");
    scanf("%s", table[count].value);

    count++;

    printf("Identifier inserted successfully.\n");
}

/* Search for a symbol */
int search(char name[])
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (strcmp(table[i].name, name) == 0)
        {
            return i;
        }
    }

    return -1;
}

/* Display symbol table */
void display()
{
    int i;

    if (count == 0)
    {
        printf("\nSymbol table is empty.\n");
        return;
    }

    printf("\n-------------------------------------\n");
    printf("Name\tType\tValue\n");
    printf("-------------------------------------\n");

    for (i = 0; i < count; i++)
    {
        printf("%s\t%s\t%s\n",
               table[i].name,
               table[i].type,
               table[i].value);
    }

    printf("-------------------------------------\n");
}

/* Delete a symbol */
void deleteSymbol()
{
    char name[30];
    int position;
    int i;

    printf("\nEnter identifier to delete: ");
    scanf("%s", name);

    position = search(name);

    if (position == -1)
    {
        printf("Identifier not found.\n");
        return;
    }

    /* Shift remaining elements */
    for (i = position; i < count - 1; i++)
    {
        table[i] = table[i + 1];
    }

    count--;

    printf("Identifier deleted successfully.\n");
}

int main()
{
    int choice;
    char name[30];
    int position;

    while (1)
    {
        printf("\n===== SYMBOL TABLE =====\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Search\n");
        printf("4. Delete\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                display();
                break;

            case 3:
                printf("\nEnter identifier to search: ");
                scanf("%s", name);

                position = search(name);

                if (position == -1)
                {
                    printf("Identifier not found.\n");
                }
                else
                {
                    printf("Identifier found.\n");
                    printf("Name  : %s\n", table[position].name);
                    printf("Type  : %s\n", table[position].type);
                    printf("Value : %s\n", table[position].value);
                }

                break;

            case 4:
                deleteSymbol();
                break;

            case 5:
                printf("\nProgram terminated.\n");
                return 0;

            default:
                printf("\nInvalid choice.\n");
        }
    }
}
