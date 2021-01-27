/*
This Project is made by Ayush Koul
Btech (CSE), 3rd Semester, Graphic Era Deemed University
*/

#ifndef STACK_H
#define STACK_H
#include <stdlib.h>

template <typename T>
class Stack
{
    T *stack;
    int n;

public:
    Stack(int s = 0, T def = 0)
    {
        stack = (T *)calloc(sizeof(T), s);
        if (def)
            for (int i = 0; i != s; i++)
                stack[i] = def;
        n = s;
    }
    void push(T data)
    {
        stack = (T *) realloc(stack, sizeof(T)*(n+1));
        stack[n++] = data;
    }
    void pop()
    {
        free(stack + --n);
    }
    T top()
    {
        return stack[n - 1];
    }
    T* begin()
    {
        return stack;
    }
    T* end()
    {
        return stack + n;
    }
    inline int size()
    {
        return n;
    }
    T &operator[](int i)
    {
        if (i >= n)
            return stack[n];
        return stack[i];
    }
};
#endif