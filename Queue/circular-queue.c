#include <stdio.h>
#include <stdlib.h>

#define SIZE 6

int queue[SIZE];
int front = -1, rear = -1;

int isFull()
{
    return (rear + 1) % SIZE == front;
}

int isEmpty()
{
    return front == -1;
}

void Enqueue(int n)
{
    if (isFull())
        return;
    if (isEmpty())
    {
        front = 0;
        rear = 0;
        queue[rear] = n;
        return;
    }
    rear = (rear + 1) % SIZE;
    queue[rear] = n;
}

int Dequeue()
{
    if (isEmpty())
        return (int)NULL;
    int value = queue[front];
    front = (front + 1) % SIZE;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    return value;
}

void print()
{
    if (isEmpty())
    {
        printf("Queue : | |\n");
        return;
    }
    printf("Queue : | ");
    for (int i = front; i != rear; i = (i + 1) % SIZE)
    {
        printf("%d ", queue[i]);
    }
    printf("%d |\n", queue[rear]);
}

int main()
{
    int value, option, flag = 1;

    while (flag)
    {
        print();
        printf("front : %d and rear : %d\n", front, rear);
        printf("\nCircular Queue (using array) operations:\n1. Enqueue\n2. Dequeue\n3. Exit\nChoose a queue operation: ");
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
