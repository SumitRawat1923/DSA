#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int stack[SIZE];
int top = -1;

int isEmpty()
{
    return top == -1;
}

int isFull()
{
    return top == SIZE - 1;
}

void push(int n)
{
    if (isFull())
        return;
    top++;
    stack[top] = n;
}

int pop()
{
    if (isEmpty())
        return (int)NULL;
    top--;
}

int peek()
{
    if (isEmpty())
        return (int)NULL;
    return stack[top];
}

void printStack()
{
    printf("\nstack is : | ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void printTop()
{
    if (isEmpty())
    {
        printf("Element at top : NULL\n");
        return;
    }
    printf("Element at top : %d\n", peek());
}

int main()
{
    int v, option, flag = 1;

    while (flag)
    {
        printStack();
        printTop();
        printf("\nStack(using array) operations.\n1. Push\n2. Pop\n3. Exit\nChoose a stack operation : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            if (isFull())
            {
                break;
            }
            printf("Enter a value : ");
            scanf("%d", &v);
            push(v);
            break;
        case 2:
            pop();
            break;
        case 3:
            flag = 0;
            break;
        default:
            printf("Choose a valid option.\n");
        }
        system("cls");
    }
}