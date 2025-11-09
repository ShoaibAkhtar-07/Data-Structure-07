#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *s = (struct Node *)malloc(sizeof(struct Node));
    s->data = data;
    s->left = NULL;
    s->right = NULL;
    return s;
}

void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d  ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    struct Node *p = createNode(2);
    struct Node *c1 = createNode(3);
    struct Node *c2 = createNode(4);
    struct Node *gc1 = createNode(7);
    struct Node *gc2 = createNode(8);
    p->left = c1;
    p->right = c2;
    c1->left = gc1;
    c1->right = gc2;
    preOrder(p);
    return 0;
}