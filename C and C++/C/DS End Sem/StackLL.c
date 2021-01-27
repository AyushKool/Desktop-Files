#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
} Node;

void push(Node **top, int k)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->next = *top;
    p->info = k;
    *top = p;
}

void pop(Node **top)
{
    Node *p = *top;
    if (p)
    {
        printf("%d popped.\n", p->info);
        *top = (*top)->next;
        free(p);
    }
}

void topToBottom(Node *t)
{
    if (!t)
        return;
    printf("%d ", t->info);
    topToBottom(t->next);
}

void bottomToTop(Node *t)
{
    if (!t)
        return;
    bottomToTop(t->next);
    printf("%d ", t->info);
}

void display(Node *t, int n)
{
    if(!t)
    {
        printf("Stack Empty.\n");
        return;
    }
    switch (n)
    {
    case 1:
        bottomToTop(t);
        break;
    default:
        topToBottom(t);
        break;
    }
    printf("\n");
}

int main(){
    Node *t = NULL;

    //Top to Bottom
    // push(&t, 7);
    // display(t, 0);
    // push(&t, 5);
    // display(t, 0);
    // push(&t, 6);
    // display(t, 0);
    // push(&t, 1);
    // display(t, 0);
    // push(&t, 2);
    // display(t, 0);

    // pop(&t);
    // display(t, 0);
    // pop(&t);
    // display(t, 0);


    //Bottom To Top 
    // push(&t, 7);
    // display(t, 1);
    // push(&t, 5);
    // display(t, 1);
    // push(&t, 6);
    // display(t, 1);
    // push(&t, 1);
    // display(t, 1);
    // push(&t, 2);
    // display(t, 1);
}