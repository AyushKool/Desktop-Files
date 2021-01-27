/*
Name: Ayush Koul
Roll No: 24
Section: A

Problem Statement 7: Write a menu driven program to create a DLL using double pointer, by inserting node so that
list remains in ascending order.
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int info;
    struct node *next, *prev;
} Node;

void insert(Node **l, Node **r, int num)
{
    Node *p = (Node *)malloc(sizeof(Node)), *t = *l;
    p->info = num;
    if (*l == NULL)
    {
        *l = *r = p;
        p->prev = p->next = NULL;
    }
    else if (num < (*l)->info)
    {
        p->next = *l;
        p->prev = NULL;
        *l = (*l)->prev = p;
    }
    else if (num > (*r)->info)
    {
        p->prev = *r;
        p->next = NULL;
        *r = (*r)->next = p;
    }
    else
    {
        while (num > (t->next)->info)
            t = t->next;
        p->next = t->next;
        p->prev = t;
        (p->next)->prev = t->next = p;
    }
}
void display(Node *head)
{
    printf("\nList: ");
    if (!head)
    {
        printf("Empty\n");
        return;
    }
    while (head)
    {
        printf("%d ", (head->info));
        head = head->next;
    }
    printf("\n");
}
void main()
{
    Node *left = NULL, *right = NULL;
    int num, op;
    do
    {
        printf("\n1. Insert\n2. Display\n3. Exit\nEnter: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\nEnter key: ");
            scanf("%d", &num);
            insert(&left, &right, num);
            break;
        case 2:
            display(left);
        }
    } while (op != 3);
}
