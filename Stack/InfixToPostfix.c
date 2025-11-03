#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    int size;
    int top;
    char *arr;
};

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

void push(struct stack *ptr, char element)
{
    if (isFull(ptr))
    {
        printf("--STACK OVERFLOW--\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = element;
    }
}

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("--STACK UNDERFLOW--");
        return -1;
    }
    else
    {
        char element = ptr->arr[ptr->top];
        ptr->top = ptr->top - 1;
        return element;
    }
}

char StackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

int precedence(char ch){
    if(ch == '*' || ch == '/'){
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else 
    {
        return 0;
    } 
}

int isOperator(char ch){
    if(ch == '*' || ch == '/' || ch == '+' || ch == '-' ){
        return 1;
    }
    else{
        return 0;
    }
}
char *InfixToPostfix(char *infix)
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = strlen(infix);
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    char *postfix = (char *)malloc(s->size * sizeof(char)); 
    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(StackTop(s)))
            {
                push(s,infix[i]);
                i++;
            }
            else
            {
                postfix[j]=pop(s);
                j++;
            }
            
        }
    }
    while (!isEmpty(s))
    {
        postfix[j] = pop(s);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}

int main()
{
    char *infix = "a+b*c-d";
    printf(InfixToPostfix(infix));
    return 0;
}