#include <iostream>

struct A
{
    int x = 0;

    A(const A &obj)
    {
        std::cout << "Copy\t" << this << "\t\n";
    }

    A()
    {
        std::cout << "Normal\n";
    }

    A f()
    {
        //this returns exact
        A obj;
        // std::cout << &obj << std::endl;
        return obj;

        //this returns copy
        return *this;
    }

    // A& f()
    // {
    //     //this returns exact
    //     A obj;
    //     return obj;

    //     //this returns exact
    //     return *this;
    // }
    void showChange()
    {
        std::cout << ++x << std::endl;
    }
    ~A()
    {
        std::cout << "Die\n";
    }

    void operator=(const A &o)
    {
        std::cout << "equal\n";
    }

    A fun()
    {
        A o;

        return o;
    }
};

A fun()
{
    A o;

    return o;
}

int main()
{
    A a = A().fun();
    // a.f();

    //copySSS
    // A b = a.f();

    // //normal, normal then copy then equal
    // A b;
    // b = a.f();
    // std::cout << "hello\n";

    //copy
    // A b = *(new A());

    // //equal
    // A c;
    // c = *(new A());

    // std::cout << &b << std::endl;
    // a.showChange();
    // a.f().showChange();
    // a.showChange();
}