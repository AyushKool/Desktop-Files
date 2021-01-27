#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void addEmpty(Node **head, int key)
{
    if ((*head) != NULL)
        return;
    (*head) = (Node *)malloc(sizeof(Node));
    (*head)->data = key;
    (*head)->next = NULL;
}

void append(Node **head, int key)
{
    if ((*head) == NULL)
        addEmpty(head, key);
    else if ((*head)->next != NULL)
        append(&((*head)->next), key);
    else
    {
        Node *newnode = (Node *)malloc(sizeof(Node));
        newnode->data = key;
        newnode->next = NULL;
        (*head)->next = newnode;
    }
}

void displayNode(Node *node)
{
    printf("Data = %d\n", node->data);
    if (node->next == NULL)
    {
        printf("Next = NULL");
        printf("\n\n");
    }
    else
    {
        node = node->next;
        printf("Next = %d", node->data);
        printf("\n   |");
        printf("\n   |");
        printf("\n   V\n");
    }
}

void delAlt(Node *head)
{
    Node *tmp;
    while (head && head->next)
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
        //displayNode(head);
        printf("%d  ", head->data);
        head = head->next;
    }
    printf("\n");
}

void main()
{
    Node *head = NULL;
    append(&head, 6);
    append(&head, 2);
    append(&head, 5);
    append(&head, 7);
    append(&head, 1);
    append(&head, 3);
    display(head);
    delAlt(head);
    display(head);
}