
#include <stdio.h>

// Function to check password length
int checkLength(char password[])
{
    int i = 0;

    while (password[i] != '\0')
    {
        i++;
    }

    return i > 8;
}

// Function to check uppercase letters
int checkUpper(char password[])
{
    int i;

    for (i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
            return 1;
    }

    return 0;
}

// Function to check lowercase letters
int checkLower(char password[])
{
    int i;

    for (i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
            return 1;
    }

    return 0;
}

// Function to check numbers
int checkDigit(char password[])
{
    int i;

    for (i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= '0' && password[i] <= '9')
            return 1;
    }

    return 0;
}

// Function to check symbols
int checkSymbol(char password[])
{
    int i;

    for (i = 0; password[i] != '\0'; i++)
    {
        if (!((password[i] >= 'A' && password[i] <= 'Z') ||(password[i] >= 'a' && password[i] <= 'z') ||(password[i] >= '0' && password[i] <= '9')))
            return 1;
    }

    return 0;
}

// Function to check all requirements
int checkPassword(char password[])
{
    return checkLength(password) &&checkUpper(password) &&checkLower(password) &&checkDigit(password) && checkSymbol(password);
}

// Function to display missing requirements
void showErrors(char password[])
{
    if (!checkLength(password))
        printf("- More than 8 characters\n");

    if (!checkUpper(password))
        printf("- At least one uppercase letter\n");

    if (!checkLower(password))
        printf("- At least one lowercase letter\n");

    if (!checkDigit(password))
        printf("- At least one number\n");

    if (!checkSymbol(password))
        printf("- At least one symbol\n");
}

// Main function
int main()
{
    char password[100];
    char choice;

    do
    {
        printf("\nEnter password: ");
        scanf("%99s", password);

        if (checkPassword(password))
        {
            printf("\nPassword is strong!\n");
            break;
        }
        else
        {
            printf("\nPassword is weak!\n");
            showErrors(password);

            printf("\nTry again? (y/n): ");
            scanf(" %c", &choice);

            if (choice != 'y' && choice != 'Y')
            {
                printf("Goodbye!\n");
                break;
            }
        }

    } while (1);

    return 0;
}
