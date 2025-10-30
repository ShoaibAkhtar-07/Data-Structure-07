#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

// Checking whether the STACK is EMPTY or FULL
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// PUSHING a value in STACK
void push(struct stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("--STACK OVERFLOW--");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

// POPING  a value in STACK
int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("--STACK UNDERFLOW--");
        return -1;
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top = ptr->top - 1;
        return value;
    }
}

// PEEK Operation in STACK
int peek(struct stack *ptr, int i)
{
    if (i <= 0 || ptr->top - i + 1 < 0)
    {
        printf("---Invalid index---\n");
        return -1;
    }
    else
    {
        return ptr->arr[ptr->top - i + 1];
    }
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    printf("STACK has been created SUCCESSFULLY\n");

    printf("%d\n", isEmpty(s));
    printf("%d\n", isFull(s));
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    push(s, 6);
    push(s, 7);
    push(s, 8);
    push(s, 9);
    push(s, 10);
    printf("POPPED %d from STACK\n", pop(s));
    printf("%d\n", isFull(s));

    for (int i = 1; i <= s->top + 1; i++)
    {
        printf("At position %d the Value %d\n", i, peek(s, i));
    }

    printf("%d\n",peek(s,0));
    printf("%d\n",peek(s,11));

    return 0;
}