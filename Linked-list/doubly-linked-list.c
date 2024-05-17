#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

struct Node *createNode(int n)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = n;
    newNode->prev = (struct Node *)NULL;
    newNode->next = (struct Node *)NULL;
    return newNode;
}

void insertAtStart(int n)
{
    struct Node *newNode = createNode(n);
    if (head == NULL && tail == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtEnd(int n)
{
    struct Node *newNode = createNode(n);
    if (head == NULL && tail == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

struct Node *search(int n)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == n)
            return temp;
        temp = temp->next;
    }
    return (struct Node *)NULL;
}

void insertAfter(int n, int v)
{
    struct Node *newNode = createNode(v);
    struct Node *temp = search(n);
    if (temp == NULL)
        return;
    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
        newNode->next = temp->next;
    }
    else
    {
        tail = newNode;
    }
    newNode->prev = temp;
    temp->next = newNode;
}

void deleteAtStart()
{
    if (head == NULL && tail == NULL)
        return;
    struct Node *temp = head;
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    else
    {
        head = NULL;
        tail = NULL;
    }
    free(temp);
}

void deleteAtEnd()
{
    if (head == NULL && tail == NULL)
        return;

    if (head->next == NULL)
    {

        struct Node *temp = head;
        head = NULL;
        tail = NULL;
        free(temp);
    }
    else
    {
        struct Node *temp = tail;
        tail->prev->next = NULL;
        tail = tail->prev;
        free(temp);
    }
}

void deleteAfter(int n)
{
    struct Node *temp = search(n);
    if (temp == NULL || temp->next == NULL)
        return;
    struct Node *deletedNode = temp->next;
    if (temp->next->next != NULL)
    {
        temp->next->next->prev = temp;
        temp->next = temp->next->next;
    }
    else
    {
        temp->next = NULL;
        tail = temp;
    }
    free(deletedNode);
}

void reverse()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        struct Node *next = temp->next;
        temp->next = temp->prev;
        temp->prev = next;
        temp = next;
    }
    temp = tail;
    tail = head;
    head = temp;
}

void print()
{
    struct Node *temp = head;
    printf("Normal Linked List is : [ ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("]\n");
}
void printReverse()
{
    struct Node *temp = tail;
    printf("Reversed Linked List is : [ ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("]\n");
}

int main()
{
    int option, flag = 1;
    int n, v;

    while (flag)
    {
        printf("\n");
        print();
        printReverse();
        printf("\n");
        printf("Doubly-Linked-List operations menu.\n1. InsertAtStart\n2. InsertAtEnd\n3. InsertAfter\n4. DeleteAtStart\n5. DeleteAtEnd\n6. DeleteAfter\n7. Reverse\n8. Exit\nChoose a linked-list operation : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter a value : ");
            scanf("%d", &v);
            insertAtStart(v);
            break;

        case 2:
            printf("Enter a value : ");
            scanf("%d", &v);
            insertAtEnd(v);
            break;

        case 3:
            printf("Enter a node value : ");
            scanf("%d", &n);
            printf("Enter a value : ");
            scanf("%d", &v);
            insertAfter(n, v);
            break;

        case 4:
            deleteAtStart();
            break;

        case 5:
            deleteAtEnd();
            break;

        case 6:
            printf("Enter a node value : ");
            scanf("%d", &n);
            deleteAfter(n);
            break;

        case 7:
            reverse();
            break;

        case 8:
            flag = 0;
            break;

        default:
            printf("Choose a valid option.\n");
            break;
        }
        system("cls");
    }
    return 0;
}
