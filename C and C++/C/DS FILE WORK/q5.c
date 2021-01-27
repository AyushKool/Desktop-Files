/*
Name: Ayush Koul
Roll No: 24
Section: A

Problem Statement 5: WAP to split SLL. The node info at where to split is given by user.
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

//split(Head, key of last node of first LL)
Node* split(Node *head, int k)
{
    while(head && head->info != k)
        head = head->next;
    Node *p = head->next;
    head->next = NULL;
    return p;
}

void display(Node *head)
{
    while (head != NULL)
    {
        printf("%d  ", head->info);
        head = head->next;
    }
}

void main()
{
	Node* head = NULL, *second;
    int n;
    char op;
    do
	{
		printf("\nEnter Element: ");
		scanf("%d", &n);
        insert(&head, n);
        printf("Do you wish to continue (y/n): ");
        fflush(stdin);
        scanf("%c", &op);
	} while(op != 'n' && op != 'N');
    printf("\nBefore Split: ");
    display(head);
    printf("\nEnter where to split: ");
    scanf("%d", &n);
    second = split(head, n);
    printf("\nAfter Split:\n");
    printf("First: ");
    display(head);
    printf("\nSecond: ");
    display(second);
}