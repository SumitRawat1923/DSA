#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int isEmpty()
{
    return front == -1;
}

int isFull()
{
    return rear - front + 1 == SIZE;
}

void shift()
{
    for (int i = front; i <= rear; i++)
    {
        queue[i - front] = queue[i];
    }
    rear -= front;
    front = 0;
}

void Enqueue(int n)
{
    if (isFull())
    {
        printf("Queue is full.\n");
        return;
    }
    if (front > 0 && rear == SIZE - 1)
    {
        shift();
    }
    if (isEmpty())
    {
        front++;
        rear++;
        queue[front] = n;
    }
    else
    {
        rear++;
        queue[rear] = n;
    }
}

int Dequeue()
{
    if (isEmpty())
        return (int)NULL;
    if (front + 1 > rear)
    {
        int value = queue[front];
        front = -1;
        rear = -1;
        return value;
    }
    return queue[front++];
}

void print()
{
    if (isEmpty())
    {

        printf("Queue : | |\n");
        return;
    }
    printf("Queue : | ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("|\n");
}

int main()
{
    int value, option, flag = 1;

    while (flag)
    {
        print();
        printf("front : %d and rear : %d \n", front, rear);
        printf("\nQueue (using array) operations:\n1. Enqueue\n2. Dequeue\n3. Exit\nChoose a queue operation: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter a value: ");
            scanf("%d", &value);
            Enqueue(value);
            break;
        case 2:
            printf("Dequeued element: %d\n", Dequeue());
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
