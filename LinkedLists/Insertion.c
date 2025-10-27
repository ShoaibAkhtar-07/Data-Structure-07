#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// TRAVERSAL of LINKEDLIST
void LinkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// INSERTION at the BEGINNING
struct Node *InsertionAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

// INSERTION at MIDDLE
struct Node *InsertionAtMiddle(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
};

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 11;
    head->next = second;

    second->data = 12;
    second->next = third;

    third->data = 13;
    third->next = fourth;

    fourth->data = 14;
    fourth->next = NULL;

    printf("---Before INSERTION---\n");
    LinkedListTraversal(head);
    printf("\n");

    head = InsertionAtFirst(head, 10);
    printf("---After INSERTION at the BEGINNING---\n");
    LinkedListTraversal(head);

    head = InsertionAtMiddle(head, 22,2);
    printf("---After INSERTION at MIDDLE---\n");
    LinkedListTraversal(head);

    return 0;
}