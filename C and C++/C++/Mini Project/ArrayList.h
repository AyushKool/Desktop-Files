/*
This Project is made by Ayush Koul
Btech (CSE), 3rd Semester, Graphic Era Deemed University
*/

#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <stdlib.h>

template <typename T>
class ArrayList
{
    T *list;
    int n;

public:
    ArrayList(int s = 0, T def = 0)
    {
        list = (T *)calloc(sizeof(T), s);
        if (def)
            for (int i = 0; i != s; i++)
                list[i] = def;
        n = s;
    }
    void insert(T data, int pos)
    {
        if (pos > n)
            return;
        list = (T *)realloc(list, sizeof(T) * (n + 1));
        int tmp = n;
        n++;
        while (tmp != pos)
            list[tmp] = list[tmp - 1], tmp--;
        list[pos] = data;
    }
    void insert(T data)
    {
        insert(data, n);
    }
    void del(int pos = 0)
    {
        if (pos >= n)
            return;
        int tmp = pos;
        while (tmp != n)
            list[tmp] = list[++tmp];
        list = (T *)realloc(list, sizeof(T) * (n - 1)), n--;
    }
    void resize()
    {
        list = (T *)realloc(list, sizeof(T) * n);
    }
    T *begin()
    {
        return list;
    }
    T *end()
    {
        return list + n;
    }
    inline int size()
    {
        return n;
    }
    T &operator[](int i)
    {
        if (i >= n)
            return list[n];
        return list[i];
    }
    void sort()
    {
        for (int i = 1; i < n; i++)
        {
            T t = list[i];
            int j = i - 1;
            while (j >= 0 && t < list[j])
                list[j + 1] = list[j], j--;
            list[j + 1] = t;
        }
    }
    void swap(int a, int b)
    {
        if (a >= n || b >= n)
            return;
        T tmp = list[a];
        list[a] = list[b];
        list[b] = tmp;
    }
};
#endif