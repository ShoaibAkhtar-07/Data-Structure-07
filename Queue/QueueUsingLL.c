#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void LLTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("---Queue OverFlow---\n");
    }
    else
    {
        newNode->data = val;
        newNode->next = NULL;
        if (front == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }
}

int dequeue()
{
    struct Node *ptr = front;
    if (front == NULL)
    {
        printf("--Queue UnderFlow--\n");
        return -1;
    }
    else
    {
        int val = ptr->data;
        front = front->next;
        free(ptr);
        return val;
    }
}

int main()
{
    LLTraversal(front);
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    printf("--BEFORE DEQUEUE---\n");
    LLTraversal(front);
    dequeue();
    printf("--AFTER DEQUEUE---\n");
    LLTraversal(front);
    return 0;
}