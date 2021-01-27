/*
Name: Ayush Koul
Roll No: 24
Section: A

Problem Statement 12: WAP to convert any infix expression into postfix using stack.
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    char info;
    struct node *next;
} Node;

int prec(char op)
{
    if (op == '=')
        return 1;
    else if (op == '+' || op == '-')
        return 2;
    else if (op == '*' || op == '/')
        return 3;
    else if (op == '^')
        return 4;
    return -1;
}

void push(Node **t, char k) 
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->info = k;
    n->next = *t;
    *t = n;
}

void pop(Node **t)
{
    if (!(*t))
        return;
    Node *temp = *t;
    *t = (*t)->next;
    if (temp->info != '(')
        printf("%c", temp->info);
    free(temp);
}

char peek(Node *t)
{
    return t->info;
}

int isOp(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '=':
    case '^':
    case '(':
    case ')':
        return 1;
    }
    return 0;
}

void postfix()
{
    Node *tp = NULL;
    char ch; int f = 1;
    do
    {
        scanf("%c", &ch);
        if(f)
            printf("Post-fix Expression: "), f=0;
        if (ch == 32 || ch == '\n')
            continue;
        if (!isOp(ch))
        {
            printf("%c", ch);
            continue;
        }
        if (ch == '(')
            push(&tp, ch);
        else if (ch == ')')
        {
            while (tp && peek(tp) != '(')
                pop(&tp);
            pop(&tp);
        }
        else
        {
            while (tp && prec(ch) <= prec(peek(tp)))
                pop(&tp);
            push(&tp, ch);
        }
    } while (ch != '\n');

    while (tp)
        pop(&tp);
}

void main()
{
    char op;
    do
    {
        printf("Enter Infix Expression: ");
        fflush(stdin);
        postfix();
        printf("\n\nDo you wish to continue (y/n): ");
        fflush(stdin);
        scanf("%c", &op);
	} while(op != 'n' && op != 'N');
}