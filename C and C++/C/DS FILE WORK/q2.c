/*
Name: Ayush Koul
Roll No: 24
Section: A

Problem Statement 2: WAP to implement a priority queue using SLL.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info, prio;
    struct node *next;
} Node;

//Highest priority element is first (Lowest is last)
void insert(Node **head, int key, int p)
{
    Node *n = (Node *)malloc(sizeof(Node)), *tmp = *head;
    n->info = key, n->prio = p;
    if (!tmp)
        *head = n, n->next = NULL;
    else if (tmp->prio < p)
    {
        n->next = *head;
        *head = n;
    }
    else
    {
        while (tmp->next && (tmp->next)->prio > p)
            tmp = tmp->next;
        n->next = tmp->next;
        tmp->next = n;
    }
}

void display(Node *head)
{
    while (head != NULL)
    {
        printf("%d  ", head->info);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    Node *list = NULL;
    int num, p;
    char op;
    do
    {
        printf("\nEnter Element: ");
        scanf("%d", &num);
        printf("Priority: ");
        scanf("%d", &p);
        insert(&list, num, p);
        printf("\nDo you wish to continue (y/n): ");
        fflush(stdin);
        scanf("%c", &op);
    } while (op != 'n' && op != 'N');
    printf("\nList: ");
    display(list);
}