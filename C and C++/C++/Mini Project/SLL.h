/*
This Project is made by Ayush Koul
Btech (CSE), 3rd Semester, Graphic Era Deemed University
*/

#ifndef SLL_H
#define SLL_H
#include <stdlib.h>
#include <iostream>
template <typename T>
class SLL
{
    typedef struct node
    {
        T info;
        struct node *next;
    } Node;

    Node *head, *tail;

public:
    SLL()
    {
        head = tail = NULL;
        // head = (Node *)malloc(sizeof(Node));
        // head->info = def;
        // head->next = NULL;
        // tail = head;
    }
    void insertRight(T data)
    {
        Node *p = (Node *)malloc(sizeof(Node));
        p->info = data;
        p->next = NULL;
        if (tail == NULL)
            head = p;
        else
            tail->next = p;
        tail = p;
    }
    void insertLeft(T data)
    {
        Node *p = (Node *)malloc(sizeof(Node));
        p->info = data;
        p->next = head;
        if (head == NULL)
            tail = p;
        head = p;
    }
    Node* find(T key)
    {
        Node *tmp = head;
        while(tmp != NULL && tmp->info != key)
            tmp = tmp->next;
        return tmp;
    }
    void deleteNode(const T& key)
    {
        Node *tmp = head, *prev = NULL;
        while(tmp != NULL && tmp->info != key)
            prev = tmp, tmp = tmp->next;
        if (tmp==NULL)
            std::cout << key << " Not found\n";
        else
        {
            if (prev!=NULL)
                prev->next = tmp->next;
            else
                head = head->next;
            free(tmp);
        }
    }
    void deleteNode(Node* n)
    {
        if (n==NULL)
            return;
        deleteNode(n->info);
    }
    Node *begin()
    {
        return head;
    }
    Node *next(Node* curr, int pos = 1)
    {
        while(pos--)
            curr = curr->next;
        return curr;
    }
    Node *end()
    {
        return NULL;
    }
};
#endif