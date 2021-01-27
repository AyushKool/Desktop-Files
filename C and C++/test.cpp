#include <iostream>
#include <memory>
#include <stdint.h>
using namespace std;

// struct a
// {
//     char c;
// };

// int main()
// {
//     char *p;
//     cout << sizeof(*p) << sizeof(p) << endl;
//     cout << sizeof(char) << sizeof(int);
// }

template <typename T>
auto get_value(T t)
{
    if constexpr (std::is_pointer_v<T>)
        return *t;
    else
        return t;
}

//converts high endian to little indian (required for Intel Processors)
// uint32_t format(const char* &bytes)
// {
//     return (uint32_t)((bytes[0] << 24) |
//         (bytes[1] << 16) |
//         (bytes[2] << 8) |
//         (bytes[3]));
// }

// uint32_t normal(const char* &bytes)
// {
//     return (uint32_t)((bytes[3] << 24) |
//         (bytes[2] << 16) |
//         (bytes[1] << 8) |
//         (bytes[0]));
// }



// int* f()
// {
//     int a[3] = {1, 2, 3};
//     return a; //can't return local var. Make is static
// }


// void func(int *&a)
// {

// }

int main()
{
    // int x = 4;
    // int *p = &x;
    // func(p);


    wchar_t ch;
    auto pi = std::make_unique<int>(9);
    int i = 9;

    std::cout << get_value(pi.get()) << "\n";
    std::cout << get_value(i) << "\n";

    const char bytes[4] = {0x01, 0x23, 0x45, 0x67};
    // const char * p = bytes;
    // printf("0x%08x\n", normal(p));
    printf("0x%08x\n", format(bytes));

    // unsigned int i = 1;  
    // char *c = (char*)&i;  
    // if (*c)  
    //     cout<<"Little endian";  //LSB at lower address
    // else
    //     cout<<"Big endian";  //MSB at lower address

    // char ch = 65;
    // const char * a = &ch;
    // char * const b = &ch;
    // *a = 66; //error
    // *b = 66;

    // const int a = 34;
    // int const b = 34;
}
