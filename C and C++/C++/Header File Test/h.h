#pragma once
#include <iostream>
template<typename T>
class A
{
     T t;
public:
     A(){std::cout << "1";}
     A(T t) : t(t){std::cout << "2";}
};