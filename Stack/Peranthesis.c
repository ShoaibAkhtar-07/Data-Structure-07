#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    char *arr;
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
void push(struct stack *ptr, char element)
{
    if (isFull(ptr))
    {
        printf("--STACK OVERFLOW---\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = element;
    }
}

// POPING  a value in STACK
char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("--STACK UNDERFLOW--\n");
        return -1;
    }
    else
    {
        char element = ptr->arr[ptr->top];
        ptr->top = ptr->top - 1;
        return element;
    }
}

// Parenthesis Checking Using Stack


int main()
{
    struct stack *s;
    s->size = 10;
    s->top = -1;
    s->arr = (char *)malloc(s->size * (sizeof(char)));
    return 0;
}