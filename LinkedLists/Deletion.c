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

// DELETION in MIDDLE
struct Node *DeletionInMiddle(struct Node *head, int index)
{
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }

    struct Node *q = head;
    int j = 0;
    while (j != index)
    {
        q = q->next;
        j++;
    }

    p->next = q->next;
    free(q);
    return head;
}

// DELETION at the END
struct Node *DeletionAtEnd(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

// DELETION by VALUE
struct Node *DeletionByValue(struct Node *head, int value)
{
    if (head == NULL)
        return NULL;
    //--2
    if (head->data == value)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    //--2
    struct Node *p = head;
    struct Node *q = head->next;
    while (q != NULL && q->data != value)
    {
        p = p->next;
        q = q->next;
    }
    if (q != NULL)
    {
        p->next = q->next;
        free(q);
    }
    return head;
}


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

    head->data = 111;
    head->next = second;

    second->data = 111;
    second->next = third;

    third->data = 222;
    third->next = fourth;

    fourth->data = 333;
    fourth->next = NULL;

    printf("---BEFORE DELETION---\n");
    LinkedList(head);

    printf("\n---AFTER DELETION at the BEGINNING---\n");
    head = DeletionAtBeginning(head);
    LinkedList(head);

    printf("\n---AFTER DELETION in MIDDLE---\n");
    head = DeletionInMiddle(head, 1);
    LinkedList(head);

    printf("\n---AFTER DELETION at the END---\n");
    head = DeletionAtEnd(head);
    LinkedList(head);

    printf("\n---AFTER DELETION by the VALUE---\n");
    head = DeletionByValue(head, 111);
    LinkedList(head);

    return 0;
}