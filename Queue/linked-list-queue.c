#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = (struct Node *)NULL, *rear = (struct Node *)NULL;

int isEmpty()
{   
    return front == NULL;
}

struct Node *createNode(int n)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = n;
    newNode->next = (struct Node *)NULL;
    return newNode;
}

void Enqueue(int n)
{
    struct Node *newNode = createNode(n);
    if (isEmpty())
    {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

int Dequeue()
{
    if (front == NULL)
        return (int)NULL;
    struct Node *temp = front;
    front = front->next;

    if (front == NULL)
    {
        rear == NULL;
    }

    int val = temp->data;
    free(temp);
    return val;
}

void print()
{
    if (isEmpty())
    {
        printf("Queue : | |\n");
        return;
    }
    struct Node *temp = front;
    printf("Queue : | ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("|\n");
}

int main()
{
    int value, option, flag = 1;

    while (flag)
    {
        print();
        printf("\n Queue( linked-list ) operations:\n1. Enqueue\n2. Dequeue\n3. Exit\nChoose a queue operation: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter a value: ");
            scanf("%d", &value);
            Enqueue(value);
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            flag = 0;
            break;
        default:
            printf("Choose a valid option.\n");
        }
        system("cls");
    }

    return 0;
}