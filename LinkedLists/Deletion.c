#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

// Traversal of LinkedList
void LinkedList(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// DELETION at the BEGINNING
struct Node *DeletionAtBeginning(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 111;
    head->next = second;

    second->data = 222;
    second->next = third;

    third->data = 333;
    third->next = NULL;

    printf("---BEFORE DELETION---\n");
    LinkedList(head);

    printf("\n---AFTER DELETION---\n");
    head = DeletionAtBeginning(head);
    LinkedList(head);

    return 0;
}