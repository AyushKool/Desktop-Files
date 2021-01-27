#include <stdlib.h>
#include <stdio.h>

#define NL printf("\n")

typedef struct node
{
    int info;
    struct node *left, *right;
} Node;

void insert(Node **r, int k)
{
    if (!*r)
    {
        Node *p = (Node *)malloc(sizeof(Node));
        p->left = p->right = NULL;
        p->info = k;
        *r = p;
    }
    else if ((*r)->info > k)
        insert(&((*r)->left), k);
    else
        insert(&((*r)->right), k);
}

void inorder(Node *r)
{
    if (!r)
        return;
    inorder(r->left);
    printf("%d ", r->info);
    inorder(r->right);
}

void preorder(Node *r)
{
    if (!r)
        return;
    printf("%d ", r->info);
    preorder(r->left);
    preorder(r->right);
}

void postorder(Node *r)
{
    if (!r)
        return;
    postorder(r->left);
    postorder(r->right);
    printf("%d ", r->info);
}

int leaves(Node *r)
{
    if (!r)
        return 0;
    else if (!(r->left || r->right))
        return 1;
    return leaves(r->left) + leaves(r->right);
}

int nodes(Node *r)
{
    if (!r)
        return 0;
    return 1 + nodes(r->left) + nodes(r->right);
}

int main()
{
    Node *r = NULL;
    insert(&r, 8);
    insert(&r, 1);
    insert(&r, 80);
    insert(&r, 9);
    insert(&r, 14);
    insert(&r, 7);

    printf("Preorder: ");
    preorder(r);
    NL;

    printf("Inorder: ");
    inorder(r);
    NL;

    printf("Postorder: ");
    postorder(r);
    NL;
    
    printf("Nodes: %d\n", nodes(r));
    printf("Leaves: %d\n", leaves(r));
}