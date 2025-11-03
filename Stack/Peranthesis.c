#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
int ParenthesicMatch(char *exp)
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = strlen(exp);
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    for (int i = 0; i < exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(s, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(s))
            {
                return 0;
            }
            pop(s);
        }
    }
    if (isEmpty(s))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char *exp = "1*4-3(8/2)";
    if (ParenthesicMatch(exp))
    {
        printf("---Parenthesic MATCHED---\n");
    }
    else
    {
        printf("---Parenthesic NOT MATCHED----\n");
    }
    return 0;
}