#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void DoubleLLTraversal(struct Node *head){
    struct Node *ptr = head;
    while (ptr != NULL){
        printf("Elements = %d\n",ptr->data);
        ptr = ptr->next;
    }
    
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    head->prev=NULL;
    head->data=1;
    head->next=second;
    
    second->prev=head;
    second->data=2;
    second->next=third;

    third->prev=second;
    third->data=3;
    third->next=fourth;

    fourth->prev=third;
    fourth->data=4;
    fourth->next=NULL;

    DoubleLLTraversal(head);

    return 0;
}