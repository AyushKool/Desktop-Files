/*
Name: Ayush Koul
Roll No: 24
Section: A

Problem Statement 4: WAP to implement stack using linked list and then display stack from bottom to top.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int info;
	struct node *next;
} Node;

void push(Node **t, int k)
{
	Node *n = (Node *)malloc(sizeof(Node));
	n->info = k;
	n->next = *t;
	*t = n;
	printf("%d pushed to stack\n", k);
}

void pop(Node **t)
{
	if (!*t)
		return;
	Node *temp = *t;
	*t = (*t)->next;
	printf("\n%d popped from stack\n", temp->info);
	free(temp);
}

void bottomToTop(Node *t)
{
	if (!t)
		return;
	bottomToTop(t->next);
	printf("%d ", t->info);
}

void main()
{
	Node *top = NULL;
	int op, num;
	do
	{
		printf("\n1. Push\n2. Pop\n3. Exit\nEnter: ");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			printf("\nEnter value: ");
			scanf("%d", &num);
			push(&top, num);
			break;
		case 2:
			pop(&top);
			break;
		}
	} while (op != 3);

	printf("\nStack from bottom to top: ");
	bottomToTop(top);
}