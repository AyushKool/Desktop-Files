/*
Name: Ayush Koul
Roll No: 24
Section: A

Problem Statement 8: WAP to create BST and write functions for the following operations:
(i) count total no. of nodes.
(ii) count total no. of leaf nodes.
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int info;
    struct node *left, *right;
} Node;

void insert(Node **rt, int num)
{
    Node *p;
    if ((*rt) == NULL)
    {
        p = (Node *)malloc(sizeof(Node));
        p->info = num;
        p->left = p->right = NULL;
        (*rt) = p;
    }
    else if (num < (*rt)->info)
        insert(&((*rt)->left), num);
    else
        insert(&((*rt)->right), num);
}

int countNodes(Node *r)
{
    if (!r)
        return 0;
    return countNodes(r->left) + countNodes(r->right) + 1;
}

int countLeaf(Node *r)
{
    if (!r)
        return 0;
    else if (!(r->left || r->right))
        return 1;
    return countLeaf(r->left) + countLeaf(r->right);
}

void main()
{
    Node *root = NULL;
    int n;
    char op;
    do
    {
        printf("\nEnter Element: ");
        scanf("%d", &n);
        insert(&root, n);
        printf("Do you wish to continue (y/n): ");
        fflush(stdin);
        scanf("%c", &op);
    } while (op != 'n' && op != 'N');
    printf("Number of Nodes: %d\nNumber of Leaf Nodes: %d", countNodes(root), countLeaf(root));
}
