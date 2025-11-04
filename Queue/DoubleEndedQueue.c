#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct Queue *ptr)
{
    if (ptr->rear == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct Queue *ptr)
{
    if (ptr->rear == -1 || ptr->front == ptr->rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueueFromRear(struct Queue *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("--Queue OVREFLOW--\n");
    }
    else
    {
        ptr->rear++;
        ptr->arr[ptr->rear] = value;
    }
}

void enqueueFromFront(struct Queue *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("--Queue OVREFLOW--\n");
    }
    if (ptr->front == -1)
    {
        printf("SORRY---can't insert from front\n");
    }
    else
    {
        ptr->arr[ptr->front] = value;
        ptr->front--;
    }
}

int dequeueFromFront(struct Queue *ptr)
{
    if (isEmpty(ptr))
    {
        printf("---Queue UNDERFLOW---\n");
    }
    else
    {
        ptr->front++;
        int value = ptr->arr[ptr->front];
        return value;
    }
}

int dequeueFromRear(struct Queue *ptr)
{
    if (isEmpty(ptr))
    {
        printf("---Queue UNDERFLOW---\n");
        return -1;
    }
    else
    {
        int value = ptr->arr[ptr->rear];
        ptr->rear--;
        return value;
    }
}

//Displaying
void Display(struct Queue *ptr){
    if(isEmpty(ptr)){
        printf("--Queue is EMPTY---\n");
    }
    else{
        for(int i = ptr->front+1;i<= ptr->rear;i++){
            printf("Element at %d : %d\n",i,ptr->arr[i]);
        }
    }
}


int main()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->size = 10;
    q->front = -1;
    q->rear = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));
    printf("%d\n", isEmpty(q));
    printf("%d\n", isFull(q));
    enqueueFromRear(q, 01);
    enqueueFromRear(q, 02);
    enqueueFromRear(q, 03);
    enqueueFromRear(q, 04);
    enqueueFromRear(q, 05);
    dequeueFromFront(q);
    enqueueFromFront(q, 07);
    enqueueFromRear(q, 06);
    Display(q);
    printf("%d\n", isEmpty(q));
    printf("Dequeue : %d from Queue\n", dequeueFromFront(q));
    printf("Dequeue : %d from Queue\n", dequeueFromFront(q));
    printf("Dequeue : %d from Queue\n", dequeueFromRear(q));
    enqueueFromRear(q, 01);
    Display(q);
    return 0;
}