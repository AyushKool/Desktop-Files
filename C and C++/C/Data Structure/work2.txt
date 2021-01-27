/*
Problem Statement: Print Stack in reverse
Name: Ayush Koul
Sec. A Roll No. 24
BTECH CSE 3rd Sem
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int info;
    struct Node *next;
} Node;
void insert(Node **t, int data)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->info = data;
    p->next = *t;
    if (*t == NULL)
        *t = p;
    *t = p;
}
void displayRev(Node *t)
{
    if (t == NULL)
        return;
    displayRev(t->next);
    printf("%d\n", t->info);
}
void display(Node *t)
{
    if (t == NULL)
        return;
    printf("%d\n", t->info);
    display(t->next);
    
}
void main()
{
    Node *top = NULL;
    insert(&top, 6);
    insert(&top, 2);
    insert(&top, 5);
    insert(&top, 7);
    insert(&top, 1);
    insert(&top, 3);
    displayRev(top);
    printf("\n");
    display(top);
}