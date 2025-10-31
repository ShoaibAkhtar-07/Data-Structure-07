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
    else{
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
    if (isFull(top))
    {
        printf("---STACK OVERFLOW---\n");
    }
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

// POPPING a value from stack
int pop(struct Node** top)
{
    if (isEmpty(*top))
    {
        printf("---STACK UNDERFLOW---\n");
    }
    else
    {
        struct Node *p = *top;
        *top = (*top)->next;
        int x = p->data;
        free(p);
        return x;
    }
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


    return 0;
}