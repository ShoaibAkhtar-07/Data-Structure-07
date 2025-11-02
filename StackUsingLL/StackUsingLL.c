#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// TRAVERSING an LinkedList and printing it's values
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Checking whether the STACK is EMPTY or NOT
int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Checking whether the STACK is FULL or NOT
int isFull(struct Node *top)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// PUSHING a value in STACK
struct Node *push(struct Node *top, int x)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("---STACK OVERFLOW---\n");
    }
    else
    {
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

// POPPING a value from stack
int pop(struct Node **top)
{
    if (isEmpty(*top))
    {
        printf("---STACK UNDERFLOW---\n");
        return -1;
    }
    else
    {
        struct Node *p = *top;
        int x = p->data;
        *top = (*top)->next;
        free(p);
        return x;
    }
}

// PEEK operation
int peek(struct Node *top, int p)
{
    struct Node *ptr = top;
    for (int i = 0; (i < p - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}

// STACKTOP
int stacktop(struct Node *top)
{
    return top->data;
}

// STACKBOTTOM
int stackbottom(struct Node *top)
{
    struct Node *ptr = top;
    if (ptr == NULL)
    {
        printf("---STACK is EMPTY---\n");
        return -1;
    }
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    return ptr->data;
}

int main()
{
    struct Node *top = NULL;
    top = push(top, 90);
    top = push(top, 190);
    top = push(top, 290);
    top = push(top, 390);
    linkedListTraversal(top);
    printf("The popped element is : %d\n", pop(&top));
    linkedListTraversal(top);

    printf("%d\n", peek(top, 1));
    printf("%d\n", peek(top, 2));
    printf("%d\n", peek(top, 3));
    printf("\n");
    printf("%d", stacktop(top));
    printf("\n");
    printf("%d", stackbottom(top));
    return 0;
}