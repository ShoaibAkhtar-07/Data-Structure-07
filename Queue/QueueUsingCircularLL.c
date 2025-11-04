#include <stdio.h>
#include <stdlib.h>

struct QueueCL
{
    int size;
    int front;
    int rear;
    int *arr;
};


int isFull(struct QueueCL *ptr)
{
    if (((ptr->rear + 1) % ptr->size) == ptr->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int isEmpty(struct QueueCL *ptr)
{
    if (ptr->rear == ptr->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void enqueue(struct QueueCL *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("--QUEUE OVERFLOW--\n");
    }
    else
    {
        ptr->rear = (ptr->rear + 1) % ptr->size;
        ptr->arr[ptr->rear] = val;
    }
}


int deqeue(struct QueueCL *ptr)
{
    int val = -1;
    if (isEmpty(ptr))
    {
        printf("--QUEUE UNDERFLOW--\n");
        return -1;
    }
    else
    {
        ptr->front = (ptr->front + 1) % ptr->size;
        val = ptr->arr[ptr->front];
    }
    return val;
}



int main()
{
    struct QueueCL *q = (struct QueueCL *)malloc(sizeof(struct QueueCL));
    q->size = 4;
    q->front = 0;
    q->rear = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));
    printf("%d\n",isEmpty(q));
    printf("%d\n",isFull(q));
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    printf("%d\n",isEmpty(q));
    printf("%d\n",isFull(q));
    deqeue(q);


    return 0;
}