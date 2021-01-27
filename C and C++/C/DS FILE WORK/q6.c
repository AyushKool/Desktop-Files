/*
Name: Ayush Koul
Roll No: 24
Section: A

Problem Statement 6: WAP to delete alternate node from SLL.
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

void delAlt(Node *head)
{
    Node *tmp;
    if (!head || !(head->next))//0 or 1 element
        return;
    while(head && head->next)
    {
        tmp = head->next;
        head->next = head->next->next;
        head = head->next;
        free(tmp);
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
    int n;
    char op;
    do
	{
		printf("\nEnter Element: ");
		scanf("%d", &n);
        insert(&list, n);
        printf("Do you wish to continue (y/n): ");
        fflush(stdin);
        scanf("%c", &op);
	} while(op != 'n' && op != 'N');
    printf("\nBefore: ");
    display(list);
    delAlt(list);
    printf("After: ");
    display(list);
}