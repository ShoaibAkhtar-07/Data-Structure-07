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
    push(s, 11);
    pop(s);
    printf("%d\n", isFull(s));
    return 0;
}