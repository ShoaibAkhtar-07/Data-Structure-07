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

int main()
{
    struct Node *top = NULL;
    top = push(top, 90);
    linkedListTraversal(top);
    return 0;
}