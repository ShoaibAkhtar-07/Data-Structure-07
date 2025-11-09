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

void postOrder(struct Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d  ", root->data);
    }
}

void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d  ", root->data);
        inOrder(root->right);
    }
}

int main()
{
    struct Node *p = createNode(4);
    struct Node *c1 = createNode(5);
    struct Node *c2 = createNode(6);
    struct Node *gc1 = createNode(7);
    struct Node *gc2 = createNode(8);
    struct Node *ggc1 = createNode(9);
    struct Node *ggc2 = createNode(10);

    p->left = c1;
    p->right = c2;
    c1->left = gc1;
    c1->right = gc2;
    gc1->left = ggc1;
    gc1->right = ggc2;
    printf("---PREOrder---\n");
    preOrder(p);
    printf("\n");
    printf("---POSTOrder---\n");
    postOrder(p);
    printf("\n");
    printf("---INOrder---\n");
    inOrder(p);

    return 0;
}