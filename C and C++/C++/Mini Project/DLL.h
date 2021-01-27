/*
This Project is made by Ayush Koul
Btech (CSE), 3rd Semester, Graphic Era Deemed University
*/

#ifndef DLL_H
#define DLL_H
#include <stdlib.h>
#include <iostream>
template <typename T>
class DLL
{
    typedef struct node
    {
        T info;
        struct node *next, *prev;
    } Node;

    Node *head, *tail;

public:
    DLL(T def = 0)
    {
        head = tail = NULL;
    }
    void insertRight(T data)
    {
        Node *p = (Node *)malloc(sizeof(Node));
        p->info = data;
        p->next = NULL;
        p->prev = tail;
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
        p->prev = NULL;
        if (head == NULL)
            tail = p;
        else
            head->prev = p;
        head = p;
    }
    Node* find(const T& key)
    {
        Node *tmp = head;
        while(tmp != NULL && tmp->info != key)
            tmp = tmp->next;
        return tmp;
    }
    void deleteNode(const T& key)
    {
        Node *tmp = head;
        while(tmp != NULL && tmp->info != key)
            tmp = tmp->next;
        if (tmp==NULL)
            std::cout << "Element Not found\n";
        else
        {
            if (tmp->prev != NULL)
                (tmp->prev)->next = tmp->next;
            else
                head = head->next;

            if (tmp->next != NULL)
                (tmp->next)->prev = tmp->prev;
            else
                tail = tail->prev;
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
    inline int size()
    {
        return end()-begin();
    }
};
#endif