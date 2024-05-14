#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *createNode(int n)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = n;
    newNode->next = NULL;
    return newNode;
}

void insertAtStart(int n)
{
    struct Node *newNode = createNode(n);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void insertAtEnd(int n)
{
    struct Node *newNode = createNode(n);
    if (head == NULL)
        head = newNode;

    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteAtStart()
{
    if (head == NULL)
        return;
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

void deleteAtEnd()
{
    if (head == NULL)
        return;
    struct Node *temp = head;

    if (temp->next == NULL)
    {
        head = NULL;
        free(temp);
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void reverse()
{
    if (head == NULL)
        return;
    struct Node *prev = NULL, *curr = head, *next = NULL;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void insertAtPosition(int i, int n)
{
    struct Node *newNode = createNode(n);

    if (i == 0)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (i - 1 && temp->next != NULL)
    {
        temp = temp->next;
        i--;
    }
    newNode->next = temp->next;
    temp->next = newNode;
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
    struct Node *temp = search(n);
    if (temp == NULL)
        return;
    struct Node *newNode = createNode(v);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAfter(int n)
{
    struct Node *temp = search(n);
    if (temp == NULL || temp->next == NULL)
        return;
    struct Node *deletedNode = temp->next;
    temp->next = temp->next->next;
    free(deletedNode);
}

void print()
{
    struct Node *temp = head;
    printf("\nLinked List : ");
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n\n");
}

int main()
{
    int option, flag = 1;
    int n, v;

    while (flag)
    {
        print();
        printf("Singly-Linked-List operations menu.\n1. InsertAtStart\n2. InsertAtEnd\n3. InsertAtPosition\n4. InsertAfter\n5. DeleteAtStart\n6. DeleteAtEnd\n7. DeleteAfter\n8. Reverse\n9. Exit\nChoose a linked-list operation : ");
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
            printf("Enter a index : ");
            scanf("%d", &n);
            printf("Enter a value : ");
            scanf("%d", &v);
            insertAtPosition(n, v);
            break;

        case 4:
            printf("Enter a node value : ");
            scanf("%d", &n);
            printf("Enter a value : ");
            scanf("%d", &v);
            insertAfter(n, v);
            break;

        case 5:
            deleteAtStart();
            break;

        case 6:
            deleteAtEnd();
            break;

        case 7:
            printf("Enter a node value : ");
            scanf("%d", &n);
            deleteAfter(n);
            break;

        case 8:
            reverse();
            break;

        case 9:
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