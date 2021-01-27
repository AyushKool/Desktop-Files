/*
Problem Statement: Delete Node using key
Name: Ayush Koul
Sec. A Roll No. 24
BTECH CSE 3rd Sem
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
} Node;
void display(Node *head)
{
    while (head != NULL)
        printf("%d ", head->info), head = head->next;
    printf("\n");
}
void insert(Node **head, Node **tail, int data)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->info = data;
    p->next = NULL;
    if (*tail == NULL)
        *head = p;
    else
        (*tail)->next = p;
    *tail = p;
}
void del(Node **head, Node **tail, int key)
{
    Node *tmp = *head, *prev = NULL;
    while (tmp != NULL && tmp->info != key)
        prev = tmp, tmp = tmp->next;
    if (tmp == NULL)
        printf(" Not found\n");
    else
    {
        if (prev != NULL)
        {
            prev->next = tmp->next;
            if (tmp == *tail)
                *tail = prev;
        }
        else
            *head = (*head)->next;
        free(tmp);
    }
}
int main()
{
    Node *head = NULL, *tail = NULL;
    insert(&head, &tail, 8);
    insert(&head, &tail, 7);
    insert(&head, &tail, 9);
    del(&head, &tail, 9);
    insert(&head, &tail, 78);
    display(head);
}