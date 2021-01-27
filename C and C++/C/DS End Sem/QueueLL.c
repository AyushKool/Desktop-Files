#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
} Node;

void insert(Node **l, Node **r, int k)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->next = NULL;
    p->info = k;
    if(!*l)
        *l = p;
    else
        (*r)->next = p;
    *r = p;
}

void serve(Node **l, Node **r)
{
    Node *p = *l;
    if (p)
    {
        *l = (*l)->next;
        free(p);
    }
    if(!*l)
        *r = *l;
}

void display(Node *l)
{
    if(!l)
    {
        printf("Queue Empty.\n");
        return;
    }
    while(l){
        printf("%d ", l->info);
        l = l->next;
    }
    printf("\n");
}

int main(){
    Node *l = NULL, *r = NULL;
    insert(&l, &r, 7);
    display(l);
    insert(&l, &r, 5);
    display(l);
    insert(&l, &r, 6);
    display(l);
    insert(&l, &r, 1);
    display(l);
    insert(&l, &r, 2);
    display(l);

    serve(&l, &r);
    display(l);
    serve(&l, &r);
    display(l);
    serve(&l, &r);
    display(l);

    insert(&l, &r, 7);
    display(l);

    serve(&l, &r);
    display(l);
    serve(&l, &r);
    display(l);
    serve(&l, &r);
    display(l);

    insert(&l, &r, 7);
    display(l);
    insert(&l, &r, 5);
    display(l);
}