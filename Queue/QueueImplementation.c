#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int size;
    int f;
    int b;
    int *arr;
};

int isFull(struct Queue *ptr)
{
    if (ptr->b == ptr->size - 1)
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
    if (ptr->b == -1 || ptr->f == ptr->b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct Queue *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("--Queue OVREFLOW--\n");
    }
    else
    {
        ptr->b++;
        ptr->arr[ptr->b] = value;
    }
}

int dequeue(struct Queue *ptr)
{
    if (isEmpty(ptr))
    {
        printf("---Queue UNDERFLOW---\n");
    }
    else
    {
        ptr->f++;
        int value = ptr->arr[ptr->f];
        return value;
    }
}

int main()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->size = 10;
    q->f = -1;
    q->b = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));
    printf("%d\n",isEmpty(q));
    printf("%d\n",isFull(q));
    enqueue(q,01);
    enqueue(q,02);
    enqueue(q,03);
    enqueue(q,04);
    enqueue(q,05);
    enqueue(q,06);
    printf("%d\n",isEmpty(q));
    printf("Dequeue : %d from Queue\n",dequeue(q));
    printf("Dequeue : %d from Queue\n",dequeue(q));
    printf("Dequeue : %d from Queue\n",dequeue(q));
    printf("Dequeue : %d from Queue\n",dequeue(q));
    printf("Dequeue : %d from Queue\n",dequeue(q));
    printf("Dequeue : %d from Queue\n",dequeue(q));
    printf("%d\n",isEmpty(q));
    enqueue(q,01);
    printf("%d\n",isEmpty(q));

    return 0;
}