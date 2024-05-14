#include <stdio.h>

int fib(int n)
{
    if (n < 2)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

void printString(char *str)
{
    if (*str == '\0')
        return;
    printf("%c ", *str);
    printString(str + 1);
}

void printReverseString(char *str)
{
    if (*str == '\0')
        return;
    printReverseString(str + 1);
    printf("%c ", *str);
}

void TowerOfHanoi(int n, char from, char to, char aux)
{
    if (n == 0)
        return;

    TowerOfHanoi(n - 1, from, aux, to);
    printf("Move %d from %c to %c.\n", n, from, to);
    TowerOfHanoi(n - 1, aux, to, from);
}

int main()
{
    int choice;
    do
    {
        printf("\nMenu Driven :\n");
        printf("1. Fibonacci Sequence\n");
        printf("2. Print String\n");
        printf("3. Print Reverse String\n");
        printf("4. Tower of Hanoi\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int n;
            printf("Enter the number of terms: ");
            scanf("%d", &n);
            printf("Fibonacci Sequence: ");
            for (int i = 0; i < n; i++)
                printf("%d ", fib(i));
            printf("\n");
        }
        break;
        case 2:
        {
            char str[100];
            printf("Enter a string: ");
            scanf("%s", str);
            printf("Printing String: ");
            printString(str);
            printf("\n");
        }
        break;
        case 3:
        {
            char str[100];
            printf("Enter a string: ");
            scanf("%s", str);
            printf("Printing Reverse String: ");
            printReverseString(str);
            printf("\n");
        }
        break;
        case 4:
        {
            int n;
            printf("Enter the number of disks: ");
            scanf("%d", &n);
            printf("Steps to solve Tower of Hanoi:\n");
            TowerOfHanoi(n, 'A', 'C', 'B');
        }
        break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }
    } while (choice != 5);

    return 0;
}
