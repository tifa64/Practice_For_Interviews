#ifndef VECTOR_H
#define VECTOR_H
#include <stdio.h>
#include <stdlib.h>

class Vector
{
public:
    Vector();

private:
    int sz = 0, capacity, *ar = NULL, i = 0;
public:

    void set_capacity(int n)
    {
        capacity = n;
        ar = (int*) realloc (ar, capacity * sizeof(int));
    }

    int get_capacity()
    {
        return capacity;
    }

    void push(int item)
    {
        if(sz == capacity)
        {
            capacity *= 2;
            ar = (int*) realloc (ar, capacity * sizeof(int));
        }
        ar[sz++] = item;
    }
    int pop()
    {
        if(!sz)
            return -1;
        return ar[--sz];
    }
    int get_size()
    {
        return sz;
    }
    bool is_emptyy()
    {
        return sz == 0;
    }
    void insrt(int item, int index)
    {
        int prev;
        if(capacity - sz <= 2)
        {
            capacity *= 2;
            ar = (int*) realloc (ar, capacity * sizeof(int));
        }
        if(index > sz)
        {
            ar[index-1] = item;
            return;
        }
        sz++;
        for(int i = 0 ; i < sz ; i++)
        {
            if(i >= index - 1)
            {
                prev = ar[i];
                ar[i] = item;
                item = prev;
            }
        }

    }
    int att(int i)
    {
        if(i > sz)
        {
            return -1;
            i = 0;
        }

        return ar[i];
    }
    void prepend(int item)
    {
        sz++;
        int prev;
        for(int i = 0 ; i < sz ; i++)
        {


            prev = ar[i];
            ar[i] = item;
            item = prev;

        }
    }
    void delet(int index)
    {
        int forwrd;
        for(int i = 0 ; i < sz ; i++)
        {
            if(i >= index - 1)
            {
                if(i < sz - 1)
                {
                    forwrd = ar[i+1];
                    ar[i] = forwrd;
                }

            }
        }
        sz --;
    }
    int findd(int item)
    {
        for(int i = 0; i < sz ; i++)
        {
            if(ar[i] == item)
            {
                return i;
            }
        }
        return -1;
    }
    void removee(int item)
    {
        while(findd(item) > 0)
        {
            delet(item);
        }
    }

};

#endif // VECTOR_H
