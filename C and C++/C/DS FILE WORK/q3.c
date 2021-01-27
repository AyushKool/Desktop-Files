/*
Name: Ayush Koul
Roll No: 24
Section: A

Problem Statement 3: WAP using CLL do processor scheduling for n processes. Every process is given 10s
at a time. Find which process will be complete when and the total waiting time for each.
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int info, t, wait, finish;
    struct node *next;
} Node;

void insert(Node **f, Node **r, int k)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->info = p->t = k;
    p->next = *f;
    if (*r == NULL)
        *f = p;
    else        
        (*r)->next = p;
    *r = p;
}

void calc(Node *f, int n, int tot)
{
    int time = 0, c = 0;
    do
    {
        if (f->info > 0)
            time += 10, f->info -= 10;
        if (f->info == 0)
        {
            f->wait = time - f->t;
            f->finish = time;
            c++;
            f->info = -1;
        }
        f = f->next;
    } while (c != n);
}

void display(Node *f, Node *r)
{
    do
    {
        printf("Waiting time: %d, Finishing time: %d\n", f->wait, f->finish);
        f = f->next;
    } while (f != r->next);
}

void main()
{
    int n, num, sum = 0, t;
    Node *f = NULL, *r = NULL;
    printf("Enter the number of programs: ");
    scanf("%d", &n);
    t = n;
    while (t--)
    {
        printf("Enter the execution time: ");
        scanf("%d", &num);
        sum += num;
        insert(&f, &r, num);
    }
    calc(f, n, sum);
    display(f, r);
}