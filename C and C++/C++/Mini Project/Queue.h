/*
This Project is made by Ayush Koul
Btech (CSE), 3rd Semester, Graphic Era Deemed University
*/

#ifndef Queue_H
#define Queue_H
#include <stdlib.h>

template <typename T>
class Queue
{
    T *q;
    int n;

public:
    Queue(int s = 0, T def = 0)
    {
        q = (T *)calloc(sizeof(T), s);
        if (def)
            for (int i = 0; i != s; i++)
                q[i] = def;
        n = s;
    }
    void push(T data)
    {
        q = (T *) realloc(q, sizeof(T)*(n+1));
        q[n++] = data;
    }
    void serve()
    {
        if (!n)
            return;
        ++q, n--;
        free(q-2);
    }
    inline int size()
    {
        return n;
    }
    T &operator[](int i)
    {
        if (i >= n)
            return q[n];
        return q[i];
    }
    T* begin()
    {
        return q;
    }
    T* end()
    {
        return q + n;
    }
};
#endif