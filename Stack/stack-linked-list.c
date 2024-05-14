#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = (struct Node *)NULL;

struct Node *createNode(int n)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = n;
    newNode->next = NULL;
    return newNode;
}

int isEmpty()
{
    return top == NULL;
}

void push(int n)
{
    struct Node *newNode = createNode(n);
    newNode->next = top;
    top = newNode;
}

int pop()
{
    if (top == NULL)
        return (int)NULL;
    struct Node *oldTop = top;
    top = top->next;
    int val = oldTop->data;
    free(oldTop);
    return val;
}

void printStack(struct Node *top)
{
    if (top == NULL)
        return;
    printStack(top->next);
    printf("%d ", top->data);
}

void printTop()
{
    if (top == NULL)
    {
        printf("Element at top : NULL\n");
    }
    else
    {
        printf("Element at top : %d\n", top->data);
    }
}

int main()
{
    int v, option, flag = 1;

    while (flag)
    {
        printf("\nStack is  : | ");
        printStack(top);
        printf("\n");
        printTop();

        printf("\nStack(using array) operations.\n1. Push\n2. Pop\n3. Exit\nChoose a stack operation : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
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
