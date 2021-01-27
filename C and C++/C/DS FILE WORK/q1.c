/*
Name: Ayush Koul
Roll No: 24
Section: A

Problem Statement 1: WAP to find union and intersection of 2 given SLL.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
} Node;

void insert(Node **head, int key)
{
    if ((*head) == NULL)
    {
        (*head) = (Node *)malloc(sizeof(Node));
        (*head)->info = key;
        (*head)->next = NULL;
    }
    else if ((*head)->next != NULL)
        insert(&((*head)->next), key);
    else
    {
        Node *newnode = (Node *)malloc(sizeof(Node));
        newnode->info = key;
        newnode->next = NULL;
        (*head)->next = newnode;
    }
}

Node *listIntersection(Node *head1, Node *head2)
{
    Node *ans = NULL, *p = head2;
    while (head1 != NULL)
    {
        head2 = p;
        while (head2 != NULL)
        {
            if (head1->info == head2->info)
                insert(&ans, head1->info);
            head2 = head2->next;
        }
        head1 = head1->next;
    }
    return ans;
}

Node *listUnion(Node *head1, Node *head2)
{
    Node *ans = NULL, *tmp = head1;
    int flag;
    while (head1)
    {
        insert(&ans, head1->info);
        head1 = head1->next;
    }
    while (head2)
    {
        flag = 1;
        head1 = tmp;
        while (head1)
        {
            if (head1->info == head2->info)
            {
                flag = 0;
                break;
            }
            head1 = head1->next;
        }
        if (flag)
            insert(&ans, head2->info);
        head2 = head2->next;
    }
    return ans;
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
    Node *one = NULL, *two = NULL;
    int num;
    char op;
    do
    {
        printf("\nEnter elements of list 1: ");
        scanf("%d", &num);
        insert(&one, num);
        printf("Do you wish to continue (y/n): ");
        fflush(stdin);
        scanf("%c", &op);
    } while (op != 'n' && op != 'N');
    do
    {
        printf("\nEnter elements of list 2: ");
        scanf("%d", &num);
        insert(&two, num);
        printf("Do you wish to continue (y/n): ");
        fflush(stdin);
        scanf("%c", &op);
    } while (op != 'n' && op != 'N');

    printf("\n\nList One and Two Union: ");
    display(listUnion(one, two));
    printf("List One and Two Intersection: ");
    display(listIntersection(one, two));
}