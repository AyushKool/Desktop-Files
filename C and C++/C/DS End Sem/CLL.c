#include <stdio.h>
#include <stdlib.h>

//CLL
typedef struct node
{
    int info;
    struct node *next;
} Node;

void insert(Node **head, Node **tail, int k)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->next = *head;
    p->info = k;
    if (!*head)
        *head = p;
    else
        (*tail)->next = p;
    *tail = p;
}

void orderInsert(Node **head, int k)
{
    Node *p = (Node *)malloc(sizeof(Node)), *t = *head;
    p->info = k;
    if (!*head)
        *head = p->next = p;
    else if (t->info > k)
    {
        p->next = t;
        while (t->next != *head)
            t = t->next;
        *head = t->next = p;
    }
    else
    {
        for (; t->next != *head && (t->next)->info < k; t = t->next);
        p->next = t->next;
        t->next = p;
    }
}

void display(Node *n)
{
    Node *temp = n;
    do
    {
        printf("%d ", n->info);
        n = n->next;
    } while (n != temp);
    printf("\n");
}

int main()
{
    Node *head = NULL, *tail = NULL;
    // insert(&head, &tail, 7);
    // insert(&head, &tail, 4);
    // insert(&head, &tail, 5);
    // display(head);
    // insert(&head, &tail, 4);
    // insert(&head, &tail, 5);
    // display(head);

    // orderInsert(&head, 8);
    // display(head);
    // orderInsert(&head, 2);
    // display(head);
    // orderInsert(&head, 20);
    // display(head);
    // orderInsert(&head, 10);
    // display(head);
    // orderInsert(&head, 6);
    // display(head);
    // orderInsert(&head, 1);
    // display(head);
    // orderInsert(&head, 100);
    // display(head);
}